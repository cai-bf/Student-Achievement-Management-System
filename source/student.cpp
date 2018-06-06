//
// Created by cbf on 18-6-5.
//

#include "../header/Student.h"
#include <iomanip>
using namespace std;

void Student::stumsg(string aname, string aid, int cpp, int java, int math)
{

    temp = new StudentMsg;
    init(cpp, java, math);
    name = aname;
    id = aid;
    score = (cpp + java + math);
    temp->name = name;
    temp->id = id;
    temp->cpp = to_string(cpp);
    temp->java = to_string(java);
    temp->math = to_string(math);
    temp->total = to_string(score);
}

Student::Student(){
    msg = nullptr;
    sortedMsg = nullptr;
    temp = nullptr;
    initMsg();
//    msg = Sort::sorted(msg, "total");
}

Student::~Student(){
    save();

}

void Student::save(){
    if(msg->name != ""){
        system("cp ../score.txt  ../score.txt.bak");
        try{
            file.open("../score.txt", ios::in|ios::out|ios::trunc);
            for(;msg != NULL; msg = msg->next){
                file << msg->name << " " << msg->id << " " << msg->cpp << " " << msg->java << " "
                     << msg->math << " " << msg->total << endl;
            }
            file.close();
        }
        catch(exception& e){
            cout << e.what() << endl;
            cout << "保存出错" << endl;
        }
    }
}

void Student::initMsg(){
    msg = new StudentMsg;
    msg->previous = NULL;
    msg->next = NULL;
    msg->name = "";
    StudentMsg *p=msg, *q=p;

    try{
        file.open("../score.txt", ios::in|ios::out);
        while(!file.eof()){
            file >> p->name >> p->id >> p->cpp >> p->java >> p->math >> p->total;
            q->next = new StudentMsg;
            q = q->next;
            q->previous = p;
            p = q;
        }
        file.close();
        p = p->previous;
        p->next = NULL;
        delete q;
        if(msg->name != ""){
            p = p->previous;
            delete p->next;
            p->next = NULL;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        exit(-1);
    }
}

void Student::sorting(string type, bool isreverse){
    string ty = type;
    msg = Sort::sorted(msg, ty, isreverse);
    if(msg->name == ""){
        cout << "暂无记录" << endl;
    }
    else
        display();
}

void Student::addMsg(){
    StudentMsg *tem = Add::addMsg(msg, temp);
    if(tem == NULL){
        char isoverwrite;
        cout << "该学生已存在，是否覆盖修改（Y：是， N:否）" << endl;
        cin >> isoverwrite;
        if(isoverwrite == 'Y'|| isoverwrite == 'y')
            reviseMsg();
    }else{
        msg = tem;
        msg = Sort::sorted(msg, "total", true);
        cout << "添加成功" << endl;
    }
}

void Student::deleteMSg(string aid){
    StudentMsg* tem = Delete::deleteMsg(msg, aid);
    if(tem == NULL)
        cout << "学号不存在" << endl;
    else{
        msg = tem;
        cout << "删除成功" << endl;
    }
}

void Student::reviseMsg(){
    StudentMsg *tem = Revise::reviseMsg(msg, temp);
    if(tem == NULL){
        cout << "不存在该用户，请确认学号是否错误" << endl;
        cout << "若确认无错，是否将该记录添加？(Y:是， N:否)" << endl;
        char i;
        cin >> i;
        if(i == 'Y')
            addMsg();
    }
    else{
        msg = tem;
        msg = Sort::sorted(msg, "total", true);
        cout << "修改成功" << endl;
    }
}

void Student::queryMsg(string type, string content){

    StudentMsg *feedback = Query::queryMsg(msg, type, content);
    if(feedback->name == ""){
        cout << "查询不到" << endl;
    }
    else
        display(feedback);
}

void Student::display(StudentMsg *ms){
    cout << setw(6) << "name" << setw(6) << "id" << setw(6) << "cpp" << setw(6) << "java"<< setw(6) << "math" << setw(6) << "total" << endl;
    if(ms == NULL){
        ms = msg;
    }
    StudentMsg* t = ms;
    for(; t != NULL; t = t->next){
        cout << setw(6) << t->name << setw(6) << t->id << setw(6) << t->cpp << setw(6) << t->java << setw(6) << t->math << setw(6) << t->total << endl;
    }
}

void Student::merge(string paths){
    Merge::mergeMsg(msg, paths);
}

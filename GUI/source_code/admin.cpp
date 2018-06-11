#include "admin.h"
#include <iomanip>
#include<QMessageBox>
using namespace std;


 // 设置学生数据
void Admin::stumsg(string aname, string aid, int cpp, int java, int math)
{

    temp = new StudentMsg;
    init(aname, aid, cpp, java, math);

    score = (cpp + java + math);
    temp->name = name;
    temp->id = id;
    temp->cpp = to_string(cpp);
    temp->java = to_string(java);
    temp->math = to_string(math);
    temp->total = to_string(score);
}

Admin::Admin(){
    msg = nullptr;
    temp = nullptr;
    initMsg();
}

Admin::~Admin(){
    sorting("total");
    save();

}

// 保存文件
void Admin::save(){
    if(msg->name != ""){
        // 保存前对原来文件进行备份
        system("cp ./data/score.txt  ./data/score.txt.bak");
        try{
            file.open("./data/score.txt", ios::in|ios::out|ios::trunc);
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

// 初始化
void Admin::initMsg(){
    msg = new StudentMsg;
    msg->previous = NULL;
    msg->next = NULL;
    msg->name = "";
    StudentMsg *p=msg, *q=p;

    try{


        // 读取文件，创建记录链表
        file.open("./data/score.txt", ios::in|ios::out);
        if(!file){
            system("touch ./data/score.txt");
            file.open("./data/score.txt", ios::in|ios::out);
        }
        while(!file.eof()){
            file >> p->name >> p->id >> p->cpp >> p->java >> p->math >> p->total;
            q->next = new StudentMsg;
            q = q->next;
            q->previous = p;
            p = q;
        }
        file.close();
        // 删除新建的空结点
        p = p->previous;
        p->next = NULL;
        delete q;
        // 删除读取文件末尾时多出来的空结点
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

 // 调用排序方法
void Admin::sorting(string type, bool isreverse){
    string ty = type;
    msg = Sort::sorted(msg, ty, isreverse);
}

// 调用增加记录方法
void Admin::addMsg(QWidget *parent){
    StudentMsg *tem = Add::addMsg(msg, temp);
    QMessageBox *existAlready = new QMessageBox;
    if(tem == NULL){
        existAlready->warning(parent, "WARNING", "id already exist");
    }else{
        msg = tem;
        msg = Sort::sorted(msg, "total", true);
        existAlready->information(parent, "ADD", "add successfully");
    }
}

// 调用删除记录方法
void Admin::deleteMsg(string aid, QWidget *parent){
    StudentMsg* tem = Delete::deleteMsg(msg, aid);
    QMessageBox *deleteBox = new QMessageBox;
    if(tem == NULL)
        deleteBox->warning(parent, "WARNING", "id not exists");
    else{
        msg = tem;
        deleteBox->information(parent, "DELETE", "delete successfully");
    }
}

// 调用修改记录方法
void Admin::reviseMsg(QWidget *parent){
    StudentMsg *tem = Revise::reviseMsg(msg, temp);
    QMessageBox *notexist = new QMessageBox;
    if(tem == NULL){
        notexist->warning(parent, "WARNING", "id not exist!");
    }
    else{
        msg = tem;
        msg = Sort::sorted(msg, "total", true);
        notexist->information(parent, "REVISE", "revise successfully");
    }
}

// 调用查询记录方法
StudentMsg* Admin::queryMsg(string type, string content,string com, QWidget *parent){

    StudentMsg *feedback = Query::queryMsg(msg, type, content, com);
    if(feedback->name.empty()){
        QMessageBox *queryBox = new QMessageBox;
        queryBox->information(parent, "Query", "have no one");
    }
    return feedback;

}

// 调用合并文件方法
void Admin::merge(string paths, QWidget* parent){
    Merge::mergeMsg(msg, paths, parent);
    sorting("total");
}


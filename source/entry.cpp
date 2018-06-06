//
// Created by cbf on 18-6-5.
//

#include "../header/Entry.h"

void Entry::firstPage(){
    system("clear");
    cout << "请输入对应的选项序号" << endl;
    cout << "1.总分榜，2.排序，3.增加记录，4.删除记录，5.修改记录，6.查询，7.合并文件，8.退出" << endl;
    int n;
    cin >> n;

    if (n==1) lookAll();
    else if (n==2) sorting();
    else if (n==3) add();
    else if (n==4) del();
    else if (n==5) revise();
    else if (n==6) searchs();
    else if (n==7) merges();
    else ;
}

void Entry::lookAll(){
    system("clear");
    student.sorting("total");
    cout << "\t 1.返回主页      2.退出" << endl;
    int n;
    cin >> n;
    if(n==1)
        firstPage();
}

void Entry::sorting(){
    system("clear");
    cout << "输入要排序的关键词(name, id, cpp, java, math)" << endl;
    string type;
    cin >> type;
    while(type != "name" && type != "id" && type != "cpp" && type != "java" && type != "math"){
        cout << "输入错误，请重新输入" << endl;
        cin >> type;
    }
    cout << "请选择正序或倒序(1.正序,  2.倒序)" << endl;
    int i;
    cin >> i;
    bool isreverse = (i==2?true:false);
    student.sorting(type, isreverse);
    cout << "\t 1.返回主页        2.查看其他排序        3.退出" << endl;
    int n;
    cin >> n;
    if(n==1)
        firstPage();
    else if (n==2)
        sorting();
}

void Entry::add(){
    string aname, aid;
    int acpp, ajava, amath, n;
    system("clear");
    cout << "请输入姓名, 学号, cpp, java, math" << endl;
    cin >> aname >> aid >> acpp >> ajava >> amath;
    student.stumsg(aname, aid, acpp, ajava, amath);
    student.addMsg();
    cout << "\t 1.返回主页        2.继续添加        3.退出" << endl;
    cin >> n;
    if(n==1)
        firstPage();
    else if (n==2)
        add();
}

void Entry::del(){
    system("clear");
    string aid;
    cout << "输入想要删除的信息对应的学号" << endl;
    cin >> aid;
    student.deleteMSg(aid);
    cout << "\t 1.返回主页        2.继续删除        3.退出" << endl;
    int n;
    cin >> n;
    if(n==1)
        firstPage();
    else if (n==2)
        del();
}

void Entry::revise(){
    system("clear");
    cout << "请输入姓名,学号,cpp,java,math" << endl;
    string aname, aid;
    int acpp, ajava, amath, n;
    cin >> aname >> aid >> acpp >> ajava >> amath;
    student.stumsg(aname, aid, acpp, ajava, amath);
    student.reviseMsg();
    cout << "\t 1.返回主页        2.继续修改        3.退出" << endl;
    cin >> n;
    if(n==1)
        firstPage();
    else if (n==2)
        revise();
}

void Entry::searchs(){
    system("clear");
    string type, content;
    cout << "输入想要查询的选项(name, id, cpp, java, math, total)" << endl;
    cin >> type;
    for(;type != "name" && type != "id" && type != "cpp" && type != "java" && type != "math" && type != "total";){
        cout << "输入错误，请重新输入" << endl;
        cin >> type;
    }
    cout << "输入查询内容" << endl;
    cin >> content;

    student.queryMsg(type, content);
    int n;
    cout << "\t 1.返回主页        2.继续查询        3.退出" << endl;
    cin >> n;
    if (n==1)
        firstPage();
    else if (n==2)
        searchs();
}

void Entry::merges(){
    string paths;
    int n;
    cout << "输入要合并的文件路径" << endl;
    cin >> paths;
    student.merge(paths);
    cout << "\t 1.返回主页        2.继续合并        3.退出" << endl;
    cin >> n;
    if (n==1)
        firstPage();
    else if (n==2)
        merges();
}

Entry::Entry(){
    firstPage();
}

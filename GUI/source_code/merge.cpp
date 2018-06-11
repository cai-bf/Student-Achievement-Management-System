
#include "merge.h"
#include <fstream>
#include<vector>
#include<QMessageBox>

// 合并文件
StudentMsg* Merge::mergeMsg(StudentMsg* msg, string paths, QWidget* parent){
    fstream reads;
    reads.open(paths, ios::in|ios::out);
    vector<string> repeat;
    int n=0;
    try{
        string aname, aid, acpp, ajava, amath;
        StudentMsg *merg = new StudentMsg, *t=merg, *tem, *p=nullptr;
        merg->previous = NULL;
        merg->next = NULL;
        merg->name = "";
        int x=0;
        while(!reads.eof()){
            reads >> aname >> aid >> acpp >> ajava >> amath;
            x = 0;
            for(p = msg;p != NULL; p = p->next){
                if(p->id == aid){
                    n = 1;
                    x = 1;
                    repeat.push_back(aid);
                    break;
                }
            }
            if(x==1) continue;
            t->name = aname;
            t->id = aid;
            t->cpp = acpp;
            t->java = ajava;
            t->math = amath;
            t->total = to_string(stoi(acpp)+stoi(ajava)+stoi(amath));
            tem = new StudentMsg;
            t->next = tem;
            tem->previous = t;
            t = tem;
        }
        reads.close();
        // 删除最后的新建空结点
        if(t->previous != NULL){
            t = t->previous;
            t->next = NULL;
            delete tem;
        }

        // 删除读取文件末尾产生的重复结点
        if(t->previous != NULL){
            t = t->previous;
            delete t->next;
            t->next = NULL;
        }

        // 合并链表
        if(merg->name != ""){
            if(msg->name == ""){
                msg = merg;
            }else{
                StudentMsg *pri = msg;
                for(;pri->next != NULL; pri = pri->next);
                pri->next = merg;
            }
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
    }

    if(n == 1){
        string result = "id为";
        if(repeat.size()>1 && repeat[repeat.size()-2]==repeat.back())
            repeat.pop_back();
        for(size_t i = 0; i < repeat.size(); ++i){
            result += repeat[i];
            result += " ";
        }
        result += "已存在, 自动忽略";
        QMessageBox *box = new QMessageBox;
        box->information(parent, "ATTENTION",
                         QString(QString::fromLocal8Bit(result.c_str())));
    }

    return msg;
}

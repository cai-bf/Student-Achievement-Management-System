//
// Created by cbf on 18-6-5.
//

#include "../header/Merge.h"
#include <fstream>

StudentMsg* Merge::mergeMsg(StudentMsg* msg, string paths){
    fstream reads;
    reads.open(paths, ios::in|ios::out);
    try{
        string aname, aid, acpp, ajava, amath;
        StudentMsg *merg = new StudentMsg, *t=merg, *tem;
        merg->previous = NULL;
        merg->next = NULL;
        merg->name = "";

        while(!reads.eof()){
            reads >> aname >> aid >> acpp >> ajava >> amath;
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
        t = t->previous;
        t->next = NULL;
        delete tem;
//        if (t->name.empty()){
//            t = t->previous;
//            delete t->next;
//            t->next = NULL;
//        }
        t = t->previous;
        delete t->next;
        t->next = NULL;

        if(merg->name != ""){
            if(msg->name == ""){
                msg = merg;
            }else{
                StudentMsg *pri = msg;
                for(;pri->next != NULL; pri = pri->next);
                pri->next = merg;
            }
        }
        cout << "合并成功" << endl;
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
    return msg;
}
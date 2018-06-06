//
// Created by cbf on 18-6-5.
//

#include "../header/Revise.h"

// 修改记录，以学号为依据
StudentMsg* Revise::reviseMsg(StudentMsg *msg, StudentMsg *rev){
    StudentMsg *p = msg;
    for(; p != NULL; p = p->next){
        if(p->id == rev->id){
            p->name = rev->name;
            p->cpp = rev->cpp;
            p->java = rev->java;
            p->math = rev->math;
            p->total = to_string(stoi(rev->cpp)+stoi(rev->java)+stoi(rev->math));
            return msg;
        }
    }
   
    // 查询不到则返回NULL
    p = NULL;
    return p;
}

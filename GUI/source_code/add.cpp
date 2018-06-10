#include "add.h"
#include <string>

// 检查是否已存在该学号
bool Add::check(StudentMsg *msg, StudentMsg* add){
    if(msg->name == "")
        return true;
    for(;msg != NULL; msg = msg->next){
        if(msg->id == add->id)
            return false;
    }
    return true;
}

// 添加记录
StudentMsg* Add::addMsg(StudentMsg* msg, StudentMsg* add){
    // 若存在则返回NULL
    if(!check(msg, add)){
        StudentMsg *has = NULL;
        return has;
    }
    StudentMsg *p=msg, *q= nullptr;
    // 尚未有记录的情况,即添加的记录为head结点
    if(p->name == ""){
        msg->name = add->name;
        msg->id = add->id;
        msg->cpp = add->cpp;
        msg->java = add->java;
        msg->math = add->math;
        msg->total = add->total;
        return msg;
    }
    /*if(p->total < add->total){*/
        //add->next = msg;
        //msg->previous = add;
        //add->previous = NULL;
        //return add;
    //}
    //for(p = p->next; p!=NULL;p = p->next){
        //if(p->total < add->total){
            //q = p->previous;
            //q->next = add;
            //add->previous = q;
            //add->next = p;
            //p->previous = add;
            //return msg;
        //}
    //}
    //p->next = add;
    //add->previous = p;
    /*add->next = NULL;*/

    // 已有记录的情况
    for(;p->next != NULL; p = p->next);
    p->next = new StudentMsg;
    q = p->next;
    q->previous = p;
    p = p->next;
    p->next = NULL;
    p->name = add->name;
    p->id = add->id;
    p->cpp = add->cpp;
    p->java = add->java;
    p->math = add->math;
    p->total = add->total;
    return msg;
}

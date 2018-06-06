//
// Created by cbf on 18-6-5.
//

#include "../header/Add.h"
#include <string>

bool Add::check(StudentMsg *msg, StudentMsg* add){
    if(msg->name == "")
        return true;
    for(;msg != NULL; msg = msg->next){
        if(msg->id == add->id)
            return false;
    }
    return true;
}

StudentMsg* Add::addMsg(StudentMsg* msg, StudentMsg* add){
    if(!check(msg, add)){
        StudentMsg *has = NULL;
        return has;
    }
    StudentMsg *p=msg, *q= nullptr;
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

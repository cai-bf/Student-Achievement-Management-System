//
// Created by cbf on 18-6-5.
//

#include "../header/Delete.h"

StudentMsg* Delete::deleteMsg(StudentMsg* msg, string id){
    StudentMsg *p = msg;
    for(; p != NULL; p = p->next){
        if(p->id == id){
            if(p->previous == NULL){
                if(p->next == NULL){
                    StudentMsg *x = new StudentMsg;
                    x->name = "";
                    x->previous = NULL;
                    x->next = NULL;
                    return x;
                }
                p = p->next;
                p->previous = NULL;
                return p;
            }
            else if(p->previous != NULL && p->next == NULL){
                p = p->previous;
                delete p->next;
                p->next = NULL;
                return msg;
            }
            else{
                StudentMsg *pre=p->previous, *nex=p->next;
                pre->next = nex;
                nex->previous = pre;
                delete p;
                return msg;
            }
        }
    }
    return NULL;
}
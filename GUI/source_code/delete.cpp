#include "delete.h"

// 删除记录
StudentMsg* Delete::deleteMsg(StudentMsg* msg, string id){
    StudentMsg *p = msg;
    for(; p != NULL; p = p->next){
        if(p->id == id){
            // 要删除的记录位于首结点的情况
            if(p->previous == NULL){
                // 总共只有两个记录的情况
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
            // 位于尾结点的情况
            else if(p->previous != NULL && p->next == NULL){
                p = p->previous;
                delete p->next;
                p->next = NULL;
                return msg;
            }
            // 位于中间结点
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

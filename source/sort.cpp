//
// Created by cbf on 18-6-5.
//

#include "../header/Sort.h"
#include<map>

StudentMsg* Sort::sorted(StudentMsg*msg, string type, bool isreverse){
    if(msg->name == "")
        return msg;
    map<string, int> getType;
    getType.insert(pair<string, int>("name", 1));
    getType.insert(pair<string, int>("id", 2));
    getType.insert(pair<string, int>("cpp", 3));
    getType.insert(pair<string, int>("java", 4));
    getType.insert(pair<string, int>("math", 5));
    getType.insert(pair<string, int>("total", 6));

    StudentMsg *p=msg, *q= nullptr, *temp=nullptr, *pre=nullptr, *depend=msg;
    int n=0;
    for(;depend->next != NULL; depend = depend->next)
        n++;
    bool isbig;
    for(int i=0;i<n; p = msg,i++){
//        q = p->next;
        for(; p->next != NULL; p = p->next){
            q = p->next;
            if(type != "name"){
                int a = stoi(p->value(getType[type]));
                int b = stoi(q->value(getType[type]));
                if (isreverse)
                    isbig = a<b;
                else
                    isbig = a>b;
            } else {
                if (isreverse)
                    isbig = p->value(getType[type]) < q->value(getType[type]);
                else
                    isbig = p->value(getType[type]) > q->value(getType[type]);
            }
            if(isbig){
                if(p->previous == NULL){
                    if(q->next == NULL){
                        p->previous = q;
                        q->next = p;
                        p->next = NULL;
                        q->previous = NULL;
                        p = q;
                        msg = p;
                    }else{
                        temp = q->next;
                        p->next = temp;
                        temp->previous = p;
                        p->previous = q;
                        q->next = p;
                        q->previous = NULL;
                        msg = q;
                        p = msg;
//                        q = p->next;
                    }
                }else if(p->previous!= NULL && q->next == NULL){
                    temp = p->previous;
                    temp->next = q;
                    q->previous = temp;
                    q->next = p;
                    p->previous = q;
                    p->next = NULL;
                    p = q;
                }else{
                    pre = p->previous;
                    temp = q->next;
                    pre->next = q;
                    q->previous = pre;
                    q->next = p;
                    p->previous = q;
                    p->next = temp;
                    temp->previous = p;
                    p = q;
//                    q = p->next;
                }
            }
        }
    }
    return msg;
}

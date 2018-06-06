//
// Created by cbf on 18-6-5.
//

#include "../header/Query.h"
#include<map>

StudentMsg* Query::queryMsg(StudentMsg *msg, string type, string content){
    StudentMsg *p = msg, *getMsg=new StudentMsg, *r=getMsg;
    // 初始化查询结果链表
    getMsg->previous = NULL;
    getMsg->next = NULL;
    getMsg->name = "";
   
    // 初始化键值对
    map<string, int> getType;
    getType.insert(pair<string, int>("name", 1));
    getType.insert(pair<string, int>("id", 2));
    getType.insert(pair<string, int>("cpp", 3));
    getType.insert(pair<string, int>("java", 4));
    getType.insert(pair<string, int>("math", 5));
    getType.insert(pair<string, int>("total", 6));
   
    // 迭代查询
    for(; p != NULL; p = p->next){
        if(p->value(getType[type]) == content){
            r->name = p->name;
            r->id = p->id;
            r->cpp = p->cpp;
            r->java = p->java;
            r->math = p->math;
            r->total = p->total;
            // 新建下一个结点
            r->next = new StudentMsg;
            r->next->previous = r;
            r = r->next;
            r->next = NULL;
        }
    }
    // 删除新建的空结点
    if(getMsg->next != NULL){
        r = r->previous;
        delete r->next;
        r->next = NULL;
    }
    return getMsg;
}

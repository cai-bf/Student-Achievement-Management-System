#include "query.h"

StudentMsg* Query::queryMsg(StudentMsg *msg, string type, string content, string com){
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
        if(check(com, type, content, p, getType)){
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


// 判断条件是否成立
bool Query::check(string com,string type, string content, StudentMsg* p, map<string, int> getType){
    if(type != "name"){
        if(com=="=")
            return stoi(p->value(getType[type])) == stoi(content);
        else if(com==">")
            return stoi(p->value(getType[type])) > stoi(content);
        else if(com=="<")
            return stoi(p->value(getType[type])) < stoi(content);
        else if(com==">=")
            return stoi(p->value(getType[type])) >= stoi(content);
        else if(com=="<=")
            return stoi(p->value(getType[type])) <= stoi(content);
        else if(com=="!=")
            return stoi(p->value(getType[type])) != stoi(content);
    }else {
        if(com=="=")
            return p->value(getType[type]) == content;
        else if(com==">")
            return p->value(getType[type]) > content;
        else if(com=="<")
            return p->value(getType[type]) < content;
        else if(com==">=")
            return p->value(getType[type]) >= content;
        else if(com=="<=")
            return p->value(getType[type]) <= content;
        else if(com=="!=")
            return p->value(getType[type]) != content;
    }
}

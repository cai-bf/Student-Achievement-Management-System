#ifndef QUERY_H
#define QUERY_H

// 查询记录
#include "msg.h"
#include<map>

class Query{
public:
    static StudentMsg* queryMsg(StudentMsg*, string, string, string);
private:
    static bool check(string, string, string, StudentMsg*, map<string, int>);
};
#endif // QUERY_H

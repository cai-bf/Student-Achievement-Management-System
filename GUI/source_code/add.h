#ifndef ADD_H
#define ADD_H
#include<iostream>
#include "msg.h"
using namespace std;

class Add{
private:
   // 判断是否存在该学号
    static bool check(StudentMsg*, StudentMsg*);
public:
    // 添加记录函数
    static StudentMsg* addMsg(StudentMsg*, StudentMsg*);

};
#endif // ADD_H

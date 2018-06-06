//
// Created by cbf on 18-6-5.
//

// 添加记录类
#ifndef CPPWORK_ADD_H
#define CPPWORK_ADD_H
#include<iostream>
#include "Msg.h"
using namespace std;

class Add{
private:
   // 判断是否存在该学号
    static bool check(StudentMsg*, StudentMsg*);
public:
    // 添加记录函数
    static StudentMsg* addMsg(StudentMsg*, StudentMsg*);

};
#endif //CPPWORK_ADD_H

//
// Created by cbf on 18-6-5.
//

#ifndef CPPWORK_ADD_H
#define CPPWORK_ADD_H
#include<iostream>
#include "Msg.h"
using namespace std;

class Add{
private:
    static bool check(StudentMsg*, StudentMsg*);
public:
    static StudentMsg* addMsg(StudentMsg*, StudentMsg*);

};
#endif //CPPWORK_ADD_H

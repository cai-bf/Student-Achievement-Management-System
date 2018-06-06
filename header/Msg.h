//
// Created by cbf on 18-6-5.
//

#ifndef CPPWORK_MSG_H
#define CPPWORK_MSG_H
#include <iostream>
#include<string>
using namespace std;
struct StudentMsg{
    string name;
    string id;
    string cpp;
    string java;
    string math;
    string total;
    StudentMsg* previous;
    StudentMsg* next;
    string value(int);

};

#endif //CPPWORK_MSG_H

#ifndef MSG_H
#define MSG_H
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

#endif // MSG_H

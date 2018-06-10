//
// Created by cbf on 18-6-8.
//

#ifndef CPPWORK_STUDENT_H
#define CPPWORK_STUDENT_H

#include "Course.h"

class Student : public Course{
protected:
    string name;
    string id;
    int score;
public:
    void init(string, string, int, int, int);

};

#endif //CPPWORK_STUDENT_H

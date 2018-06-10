#ifndef STUDENT_H
#define STUDENT_H
#include "course.h"

class Student : public Course{
protected:
    string name;
    string id;
    int score;
public:
    void init(string, string, int, int, int);

};

#endif // STUDENT_H

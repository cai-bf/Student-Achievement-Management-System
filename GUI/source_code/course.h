#ifndef COURSE_H
#define COURSE_H
// 父类
#include <iostream>
 using namespace std;

class Course{
    protected:
        int cpp;
        int java;
        int math;
        public:
        void initCourse(int, int, int);
};

#endif // COURSE_H

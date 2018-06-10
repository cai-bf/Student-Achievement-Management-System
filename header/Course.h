//
// Created by cbf on 18-6-5.
//

#ifndef CPPWORK_COURSE_H
#define CPPWORK_COURSE_H
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


#endif //CPPWORK_COURSE_H

//
// Created by cbf on 18-6-8.
//

// 学生信息类
#include "../header/Student.h"

void Student::init(string aname, string aid, int cpp, int java, int math) {
    name = aname;
    id = aid;
    initCourse(cpp, java, math);
}

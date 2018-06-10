
#include "student.h"

void Student::init(string aname, string aid, int cpp, int java, int math) {
    name = aname;
    id = aid;
    initCourse(cpp, java, math);
}

#include "../header/Course.h"
using namespace std;

Course::Course(string acourse, string aname, int aid, int ascore):
   Student(aname, aid, ascore){
      course = acourse;
   }

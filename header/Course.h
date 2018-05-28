#include "Student.h"
using namespace std;

class Course : public Student{
   protected:
      string course;
   public:
      Course(string, string, int, int);
};

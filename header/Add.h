#include<iostream>
#include "Msg.h"
using namespace std;

class Add{
   private:
      static bool check(StudentMsg*, StudentMsg*);
   public:
      static StudentMsg* addMsg(StudentMsg*, StudentMsg*);
      
};

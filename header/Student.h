#include <string>
#include <fstream>
#include"Course.h"
#include"Sort.h"
#include "Add.h"
#include "Delete.h"
#include "Revise.h"
#include "Query.h"
using namespace std;

class Student : public Course{
   private:
      StudentMsg *msg, *sortedMsg, *temp;
      fstream file;
      void initMsg();
      string name;
      string id;
      string score;

   public:
      void stumsg(string, string, string, string, string, string);
      void sorting(string);
      void addMsg();
      void deleteMSg();
      void reviseMsg();
      void queryMsg();
      void display(StudentMsg*);
      Student();
      ~Student();
};

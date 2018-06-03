#include <iostream>
#include<string>
using namespace std;
struct StudentMsg{
   string name;
   string id;
   string cpp;
   string java;
   string math;
   string total;
   StudentMsg* previous;
   StudentMsg* next;
   string value(int);

};


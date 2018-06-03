#include<iostream>
#include <string>
using namespace std;

int main(){
   string a = "11.1";
   string b = "11.10";
   if(a>b)
      cout << "a>b" << endl;
   else if(a<b)
      cout << "a<b" << endl;
   else
      cout << "=" << endl;
}

#include "../header/Student.h"
using namespace std;

void Student::stumsg(string aname, string aid, string ascore, string cpp, string java, string math)
{
   init(cpp, java, math);
   name = aname;
   id = aid;
   score = ascore;
   temp = new StudentMsg;
   temp->name = name;
   temp->id = id;
   temp->cpp = cpp;
   temp->java = java;
   temp->math = math;
   temp->total = score;
}

Student::Student(){
   initMsg();
   msg = Sort::sorted(msg, "total");
}

void Student::initMsg(){
   msg = new StudentMsg;
   msg->previous = NULL;
   msg->next = NULL;
   msg->name = "";
   StudentMsg *p=msg, *q=nullptr;
   file.open("../score.txt", ios::in|ios::out);
   try{
      
      while(!file.eof()){
         for(int i=0; i<6; i++){
            file >> p->name >> p->id >> p->cpp >> p->java >> p->java >> p->math >> p->total;
         }
         q = new StudentMsg;
         p->next = q;
         q->previous = p;
         p = q;
      }
      file.close();
      p = p->previous;
      delete q;
      p->next = NULL;
   }
   catch(exception& e){
      cout << e.what() << endl;
      exit(-1);
   }
}

void Student::sorting(string type){
   sortedMsg = Sort::sorted(msg, type);
}

void Student::addMsg(){
   StudentMsg *tem = Add::addMsg(msg, temp);
   if(tem == NULL){
      char isoverwrite;
      cout << "该学生已存在，是否覆盖修改（Y：是， N:否）" << endl;
      cin >> isoverwrite;
      if(isoverwrite == 'Y')
         reviseMsg(msg, temp);
   }else
      msg = tem;
}

void Student::deleteMSg(){
   string aid;
   cout << "输入想要删除的信息对应的学号" << endl;
   cin >> aid;
   StudentMsg* tem = Delete::deleteMsg(msg, aid);
   if(tem == NULL)
      cout << "学号不存在" << endl;
   else
      msg = tem;
}

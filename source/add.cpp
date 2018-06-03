#include "../header/Add.h"
#include <string>

bool Add::check(StudentMsg *msg, StudentMsg* add){
   if(msg->name == "")
      return true;
   for(;msg != NULL; msg = msg->next){
      if(msg->id == add->id)
         return false;
   }
   return true;
}

StudentMsg* Add::addMsg(StudentMsg* msg, StudentMsg* add){
   if(!check(msg, add)){
      StudentMsg *has = NULL;
      return has;
   }
   StudentMsg *p=msg, *q=nullptr;
   if(p->name == ""){
      add->previous  =NULL;
      add->next = NULL;
      return add;
   }
   if(p->total < add->total){
      add->next = msg;
      msg->previous = add;
      add->previous = NULL;
      return add;
   }
   for(p = p->next; p!=NULL;p = p->next){
      if(p->total < add->total){
         q = p->previous;
         q->next = add;
         add->previous = q;
         add->next = p;
         p->previous = add;
         return msg;
      }
   }
   p->next = add;
   add->previous = p;
   add->next = NULL;
   return msg;
}

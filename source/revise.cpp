#include "../header/Revise.h"

StudentMsg* Revise::reviseMsg(StudentMsg *msg, StudentMsg *rev){
   StudentMsg *p = msg;
   for(; p != NULL; p = p->next){
      if(p->id == rev->id){
         p->name = rev->name;
         p->cpp = rev->cpp;
         p->java = rev->java;
         p->math = rev->math;
         p->total = rev->total;
         return msg;
      }
   }

   p = NULL;
   return p;
}

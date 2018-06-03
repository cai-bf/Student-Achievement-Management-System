#include "../header/Sort.h"
#include<map>

StudentMsg* Sort::sorted(StudentMsg*msg, string type){
   if(msg->name == "")
      return msg;
   map<string, int> getType;
   getType.insert(pair<string, int>("name", 1)); 
   getType.insert(pair<string, int>("id", 2));
   getType.insert(pair<string, int>("cpp", 3));
   getType.insert(pair<string, int>("java", 4));
   getType.insert(pair<string, int>("math", 5));
   getType.insert(pair<string, int>("total", 6));

   StudentMsg *p=msg, *q=p->next, *temp=nullptr, *pre=nullptr, *depend=msg;
   for(;depend->next != NULL; p = msg, depend = depend->next){
      q = p->next;
      for(;p->next != NULL;p = p->next){
         q = p->next;
         if(p->value(getType[type]) < q->value(getType[type])){
            if(p->previous == NULL){
               if(q->next == NULL){
                  p->previous = q;
                  q->next = p;
                  p->next = NULL;
                  q->previous = NULL;
               }else{
                  temp = q->next;
                  p->next = temp;
                  temp->previous = p;
                  p->previous = q;
                  q->next = p;
                  q->previous = NULL;
                  p = msg;
                  q = p->next;
               }
            }else if(p->previous!= NULL && q->next == NULL){
               temp = p->previous;
               temp->next = q;
               q->previous = temp;
               q->next = p;
               p->previous = q;
               p->next = NULL;
            }else{
               pre = p->previous;
               temp = q->next;
               pre->next = q;
               q->previous = pre;
               q->next = p;
               p->previous = q;
               p->next = temp;
               temp->previous = p;
               p = q;
               q = p->next;
            }
         }
      }
   }
   return msg;
}


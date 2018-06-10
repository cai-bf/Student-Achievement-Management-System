//
// Created by cbf on 18-6-5.
//

// 主类，调用各个功能类
#ifndef CPPWORK_ADMIN_H
#define CPPWORK_ADMIN_H
#include <string>
#include <fstream>
#include"Student.h"
#include"Sort.h"
#include "Add.h"
#include "Delete.h"
#include "Revise.h"
#include "Query.h"
#include "Merge.h"

using namespace std;

class Admin : Student{
private:
    StudentMsg *msg,  *temp;
    fstream file;
    void initMsg();
    void save();
   

public:
    void stumsg(string, string, int, int, int);
    void sorting(string, bool isreverse=true);
    void addMsg();
    void deleteMSg(string);
    void reviseMsg();
    void queryMsg(string, string);
    void display(StudentMsg* ms=NULL);
    void merge(string);
    Admin();
    ~Admin();
};
#endif //CPPWORK_ADMIN_H

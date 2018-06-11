#ifndef ADMIN_H
#define ADMIN_H

// 主类，调用各个功能类
#include<QWidget>
#include <string>
#include <fstream>
#include"student.h"
#include"sort.h"
#include "add.h"
#include "delete.h"
#include "revise.h"
#include "query.h"
#include "merge.h"

using namespace std;

class Admin : Student{
protected:
    StudentMsg *msg,  *temp;
    fstream file;
    void initMsg();
    void save();


public:
    void stumsg(string, string, int, int, int);
    void sorting(string, bool isreverse=true);
    void addMsg(QWidget *);
    void deleteMsg(string, QWidget *);
    void reviseMsg(QWidget *);
    StudentMsg* queryMsg(string, string, string, QWidget*);
    void display(StudentMsg* ms=NULL);
    void merge(string, QWidget*);
    Admin();
    ~Admin();
};
#endif // ADMIN_H

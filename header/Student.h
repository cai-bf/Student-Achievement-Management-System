//
// Created by cbf on 18-6-5.
//

#ifndef CPPWORK_STUDENT_H
#define CPPWORK_STUDENT_H
#include <string>
#include <fstream>
#include"Course.h"
#include"Sort.h"
#include "Add.h"
#include "Delete.h"
#include "Revise.h"
#include "Query.h"
#include "Merge.h"

using namespace std;

class Student : public Course{
private:
    StudentMsg *msg, *sortedMsg, *temp;
    fstream file;
    void initMsg();
    void save();
    string name;
    string id;
    int score;

public:
    void stumsg(string, string, int, int, int);
    void sorting(string, bool isreverse=true);
    void addMsg();
    void deleteMSg(string);
    void reviseMsg();
    void queryMsg(string, string);
    void display(StudentMsg* ms=NULL);
    void merge(string);
    Student();
    ~Student();
};
#endif //CPPWORK_STUDENT_H

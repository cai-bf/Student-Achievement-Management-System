//
// Created by cbf on 18-6-5.
//

#ifndef CPPWORK_ENTRY_H
#define CPPWORK_ENTRY_H
#include "Admin.h"
// 渲染界面
class Entry{
private:
    Admin admin;
public:
    void firstPage();
    void lookAll();
    void sorting();
    void add();
    void del();
    void revise();
    void searchs();
    void merges();


    Entry();
};
#endif //CPPWORK_ENTRY_H

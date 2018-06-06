//
// Created by cbf on 18-6-5.
//

#include<iostream>
#include"../header/Msg.h"
using namespace std;

// 获取成员值，以实现多样化查询
string StudentMsg::value(int type){
    string temp;
    switch(type){
        case 1:
            temp = name;
            break;
        case 2:
            temp = id;
            break;
        case 3:
            temp = cpp;
            break;
        case 4:
            temp = java;
            break;
        case 5:
            temp = math;
            break;
        case 6:
            temp = total;
            break;
        default:
            cout << "排序关键字错误" << endl;
            exit(-1);
    }
    return temp;
}

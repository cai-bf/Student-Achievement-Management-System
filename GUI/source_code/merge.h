#ifndef MERGE_H
#define MERGE_H

// 合并文件
#include "msg.h"
#include<QWidget>

class Merge{
public:
    static StudentMsg* mergeMsg(StudentMsg*, string, QWidget*);
};
#endif // MERGE_H

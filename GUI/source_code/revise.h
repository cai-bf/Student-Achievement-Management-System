#ifndef REVISE_H
#define REVISE_H

// 修改记录
#include "msg.h"

class Revise{
public:
    static StudentMsg* reviseMsg(StudentMsg*, StudentMsg*);
};
#endif // REVISE_H

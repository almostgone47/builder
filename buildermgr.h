//
// Created by Jeremiah Barro on 13/8/2023.
//

#ifndef BUILDERS_BUILDERMGR_H
#define BUILDERS_BUILDERMGR_H

#include "structuretype.h"
#include "linkedlist.h"
#include "stack.h"
#include "builder.h"

class buildermgr {
private:
    Builder *builders;
    int builderNum;

public:
    buildermgr(int numBuilders);
    ~buildermgr();

    void addRequest(int, int, structure_type);
    bool doWork();
    void allReturnToBase();
};

#endif //BUILDERS_BUILDERMGR_H

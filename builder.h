//
// Created by Jeremiah Barro on 19/7/2023.
//

#ifndef BUILDERS_BUILDER_H
#define BUILDERS_BUILDER_H

#include <iostream>
#include "structuretype.h"
#include "stack.h"

using namespace std;

class Builder {
    private:
        LinkedList list;
        Stack stack;
        int builderNum = 0;
        int currentSector = 0;
    public:
        void setBuilderNum(int);
        void setCurrentSector(int);
        void addRequest(int, structure_type);
        bool doCycle();
        void returnHome();
};

#endif //BUILDERS_BUILDER_H

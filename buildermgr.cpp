//
// Created by Jeremiah Barro on 13/8/2023.
//

#include "buildermgr.h"
#include "request.h"

buildermgr::buildermgr(int numBuilders) {
    builderNum = numBuilders;
    builders = new Builder[numBuilders];

    for (int i=0;i<numBuilders;i++)
    {
        builders[i].setBuilderNum(i+1);
    }
}

buildermgr::~buildermgr() {
    delete [] builders;
}

void buildermgr::addRequest(int builderNum, int sectorNum, structure_type type) {
    builders[builderNum-1].addRequest(sectorNum,type);
}

bool buildermgr::doWork() {
    bool didSomething = false;

    for (int i = 0; i < builderNum; i++)
    {
        if (builders[i].doCycle())
        {
            didSomething = true;
        }
    }

    return didSomething;
}

void buildermgr::allReturnToBase() {
    for (int i = 0; i < builderNum; i++)
    {
        builders[i].returnHome();
    }
}
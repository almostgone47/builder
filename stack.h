//
// Created by Jeremiah Barro on 19/7/2023.
//

#ifndef BUILDERS_STACK_H
#define BUILDERS_STACK_H

#include "linkedlist.h"

class Stack {
private:
    LinkedList list;
public:
    Stack();
    bool isEmpty();
    Request * push(Request request);
    Request * pop();
    void print();
};

#endif //BUILDERS_STACK_H

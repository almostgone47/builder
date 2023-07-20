//
// Created by Jeremiah Barro on 19/7/2023.
//

#ifndef BUILDERS_LINKEDLIST_H
#define BUILDERS_LINKEDLIST_H

#include "request.h"

struct Node {
    Request data;
    Node *next = nullptr;
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &list);
    const LinkedList& operator=(const LinkedList &list);

    void addFront(Request request);
    void addBack(Request request);
    void removeFront(Request& request);
    void removeBack(Request& request);
    bool isEmpty();

    Request *pop();
};

#endif //BUILDERS_LINKEDLIST_H

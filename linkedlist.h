//
// Created by Jeremiah Barro on 19/7/2023.
//

#ifndef BUILDERS_LINKEDLIST_H
#define BUILDERS_LINKEDLIST_H

#include "request.h"

class LinkedList {
private:
    struct Node {
        Request *data;
        Node *next;

        Node(Request *request) {
            data = request;
            next = nullptr;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &list);
    const LinkedList& operator=(const LinkedList &list);

    void addFront(Request *request);
    void addBack(Request *request);
    Request * removeFront();
    void removeBack();
    bool isEmpty() const;

};

#endif //BUILDERS_LINKEDLIST_H

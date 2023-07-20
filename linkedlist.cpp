//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "linkedlist.h"

LinkedList::LinkedList() {
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {
    head = list.head;
    tail = list.tail;
    count = list.count;

    *this = list;
}

const LinkedList & LinkedList::operator= (const LinkedList &list) {
    if (this == &list) {
        return *this;
    }
    else {
        this->head= list.head;
        this->tail = list.tail;
        this->count = list.count;

        return *this;
    }
}

void LinkedList::addFront(Request request) {
    Node *newNode = new Node();
    newNode->data = request;
    newNode->next = head;
    head = newNode;
    count++;
}

void LinkedList::addBack(Request request) {
    Node *curr = head;
    Node *newNode = new Node();
    newNode->data = request;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        head->data = request;
        count++;
        return;
    }

    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
    tail = newNode;
    count++;
}

void LinkedList::removeFront(Request& request) {
    Node *temp = head;
    request = temp->data;

    head = head->next;
    delete temp;
    temp = nullptr;
    count--;
}

void LinkedList::removeBack(Request& request) {
    Node *curr = head, *prev = nullptr;

    if (head == nullptr) {
        return;
    }

    while (curr->next != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        head = tail = nullptr;
    } else {
        prev->next = nullptr;
        tail = prev;
    }

    request = curr->data;

    delete curr;
    curr = nullptr;
    count--;
}

bool LinkedList::isEmpty() {
    return count == 0;
}

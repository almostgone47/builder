//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "linkedlist.h"

//Name:   LinkedList()
//Desc:   Constructor for LinkedList class.
//input:  none.
//output: none
//return: none
LinkedList::LinkedList() {
}

//Name:   ~LinkedList()
//Desc:   Destructor for LinkedList class. The delete keyword deallocates memory and the pointers are
//        set to null so as not to leave dangling pointers.
//input:  none.
//output: none
//return: none
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

//Name:   LinkedList()
//Desc:   Copy constructor for LinkedList class.
//input:  none.
//output: none
//return: none
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

//Name:   addFront()
//Desc:   Adds a node to the front of the linked list.
//input:  none
//output: none
//return: none
void LinkedList::addFront(Request request) {
    Node *newNode = new Node();
    newNode->data = request;
    newNode->next = head;
    head = newNode;
    count++;
}

//Name:   addBack()
//Desc:   Adds node to the end of the linked list.
//input:  none
//output: none
//return: none
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

//Name:   removeFront()
//Desc:   Removes the first node.
//input:  none
//output: none
//return: none
void LinkedList::removeFront(Request& request) {
    Node *temp = head;
    request = temp->data;

    head = head->next;
    delete temp;
    temp = nullptr;
    count--;
}

//Name:   removeBack()
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
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

//Name:   isEmpty()
//Desc:   Checks to see if there are any nodes in the linked list.
//input:  none
//output: none
//return: none
bool LinkedList::isEmpty() {
    return count == 0;
}

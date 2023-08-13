//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "linkedlist.h"

//Name:   LinkedList
//Desc:   Constructor for LinkedList class.
//input:  none
//output: none
//return: none
LinkedList::LinkedList() {
}

//Name:   ~LinkedList
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

//Name:   LinkedList
//Desc:   Copy constructor for LinkedList class.
//input:  none
//output: none
//return: none
LinkedList::LinkedList(const LinkedList &list) {
    head = nullptr;
    tail = nullptr;
    count = 0;

    Node *curr = list.head;
    while (curr != nullptr) {
        addBack(new Request(*curr->data));
        curr = curr->next;
    }
}

//Name:   operator=
//Desc:   Redefines = to perform deep copy.
//input:  Reference to the linked list to copy from.
//output: none
//return: A reference to the linked list that used the method to copy.
const LinkedList & LinkedList::operator= (const LinkedList &list) {
    if (this != &list) {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;

        Node *curr = list.head;
        while (curr != nullptr) {
            addBack(new Request(*curr->data));
            curr = curr->next;
        }
    }

    return *this;
}

//Name:   addFront
//Desc:   Adds a node to the front of the linked list.
//input:  none
//output: none
//return: none
void LinkedList::addFront(Request *request) {
    Node *newNode = new Node(request);
    newNode->next = head;
    head = newNode;
    count++;
}

//Name:   addBack
//Desc:   Adds node to the end of the linked list.
//input:  none
//output: none
//return: none
void LinkedList::addBack(Request *request) {
    Node *curr = head;
    Node *newNode = new Node(request);

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

//Name:   removeFront
//Desc:   Removes the first node.
//input:  none
//output: none
//return: none
Request * LinkedList::removeFront() {
    Node *temp = head;
    Request *request = head->data;

    head = head->next;
    delete temp;
    temp = nullptr;
    count--;

    return request;
}

//Name:   removeBack
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
void LinkedList::removeBack() {
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

    delete curr;
    curr = nullptr;
    count--;
}

//Name:   isEmpty
//Desc:   Checks to see if there are any nodes in the linked list.
//input:  none
//output: none
//return: none
bool LinkedList::isEmpty() const {
    return count == 0;
}

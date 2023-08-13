//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "stack.h"
#include "request.h"

//Name:   Stack
//Desc:   Default Stack constructor.
//input:  none
//output: none
//return: none
Stack::Stack() {
}

//Name:   isEmpty
//Desc:   Checks to see if stack has an items in it.
//input:  none
//output: none
//return: True or false if empty or not.
bool Stack::isEmpty() const {
    bool result = list.isEmpty();
    return result;
}

//Name:   push
//Desc:   Pushes a request onto top of the stack.
//input:  A request object.
//output: none
//return: A pointer to the request passed in.
void Stack::push(Request *request) {
    list.addFront(request);
}

//Name:   pop
//Desc:   Removes a request from the top of the stack.
//input:  none
//output: none
//return: A reference to the request removed from the top of the stack.
Request * Stack::pop() {
    return list.removeFront();
}
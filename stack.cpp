//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "stack.h"
#include "request.h"

//Name:   Stack()
//Desc:   Default Stack constructor.
//input:  none
//output: none
//return: none
Stack::Stack() {
}

//Name:   isEmpty()
//Desc:
//input:  none
//output: none
//return: none
bool Stack::isEmpty() {
    bool result = list.isEmpty();
    return result;
}

//Name:   push()
//Desc:
//input:  none
//output: none
//return: none
Request * Stack::push(Request request) {
    list.addBack(request);
}

//Name:   pop()
//Desc:
//input:  none
//output: none
//return: none
Request Stack::pop() {
    Request request;
    list.removeBack(request);
    return request;
}
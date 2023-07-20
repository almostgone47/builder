//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "stack.h"
#include "request.h"

Stack::Stack() {
}

bool Stack::isEmpty() {
    bool result = list.isEmpty();
    return result;
}

Request * Stack::push(Request request) {
    list.addBack(request);
}

Request Stack::pop() {
    Request request;
    list.removeBack(request);
    return request;
}
//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "builder.h"

//Name:   removeBack()
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
void Builder::setBuilderNum(int num) {
    builderNum = num;
}

//Name:   removeBack()
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
void Builder::setCurrentSector(int num) {
    currentSector = num;
}

//Name:   removeBack()
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
void Builder::addRequest(int num, structure_type type) {
    Request request(num, type);
    list.addBack(request);
    cout << "Builder #" << builderNum << ": Received a request to build a ";
    request.print();
}

//Name:   removeBack()
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
bool Builder::doCycle() {
    if (list.isEmpty()) {
        return false;
    } else {
        Request request;
        list.removeFront(request);
        int nextSector = request.getSector();

        if (currentSector != nextSector) {
            cout << "Builder #" << builderNum << ": Moving to sector " << nextSector << endl;
            setCurrentSector(nextSector);
        }

        cout << "Builder #" << builderNum << ": Building a ";
        request.print();

        stack.push(request);
    }

    return true;
}

//Name:   removeBack()
//Desc:   Removes the last node.
//input:  none
//output: none
//return: none
void Builder::returnHome() {
    while (!stack.isEmpty()) {
        Request request = stack.pop();
        int nextSector = request.getSector();

        if (nextSector != currentSector) {
            cout << "Builder #" << builderNum << ": Moving to sector " << nextSector << endl;
            setCurrentSector(nextSector);
        }

        cout << "Builder #" << builderNum << ": Connected to ";
        request.print();
    }

    cout  << "Builder #" << builderNum <<": Arrived back at base.";
}
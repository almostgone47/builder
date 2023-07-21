//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "builder.h"

//Name:   setBuilderNum
//Desc:   Setter for the builder instance's builder number.
//input:  An integer representing the builder's number.
//output: none
//return: none
void Builder::setBuilderNum(int num) {
    builderNum = num;
}

//Name:   setCurrentSector
//Desc:   Setter for the builder instance's current sector.
//input:  An integer representing the current sector number.
//output: none
//return: none
void Builder::setCurrentSector(int num) {
    currentSector = num;
}

//Name:   addRequest
//Desc:   Adds a request to the builder instance's list.
//input:  An integer representing the sector and an enum for the structure_type to be built.
//output: Prints that the builder instance's builder number has received a request.
//return: none
void Builder::addRequest(int num, structure_type type) {
    Request request(num, type);
    list.addBack(request);
    cout << "Builder #" << builderNum << ": Received a request to build a ";
    request.print();
}

//Name:   doCycle
//Desc:   Executes one request from a Builder instance's list if list isn't empty.
//input:  none
//output: Prints which sector the builder instance is moving to and the action at that sector.
//return: True or false if the list is empty or not.
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

//Name:   returnHome
//Desc:   Loops through stack until the Builder instance has backtracked through all the requests
//        in its stack until it has returned home.
//input:  none
//output: Where the builder is moving to, then connected to and finally that its returned home.
//return: none
void Builder::returnHome() const {
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
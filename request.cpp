//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "request.h"

Request::Request() {
    this->sector = 0;
    this->type = UNK;
}

Request::Request(int sector, structure_type type) {
    this->sector = sector;
    this->type = type;
}

int Request::getSector() const {
    return sector;
}

char* Request::getType() const {
    char* str = new char[20];
    toString(type, str);
    return str;
}

void Request::setSector(int num) {
    sector = num;
}

void Request::setType(char *str) {
    type = getFromString(str);
}

void Request::print() const {
    const char *structureType = str(type);
    cout << structureType << " in sector " << getSector() << endl;
}
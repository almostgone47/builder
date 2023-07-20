//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "request.h"

//Name:   Request()
//Desc:   Default Request constructor.
//input:  none
//output: none
//return: none
Request::Request() {
    this->sector = 0;
    this->type = UNK;
}

//Name:   Request()
//Desc:   Request constructor.
//input:  none
//output: none
//return: none
Request::Request(int sector, structure_type type) {
    this->sector = sector;
    this->type = type;
}

//Name:   getSector()
//Desc:
//input:  none
//output: none
//return: none
int Request::getSector() const {
    return sector;
}

//Name:   getType()
//Desc:
//input:  none
//output: none
//return: none
char* Request::getType() const {
    char* str = new char[20];
    toString(type, str);
    return str;
}

//Name:   setSector()
//Desc:
//input:  none
//output: none
//return: none
void Request::setSector(int num) {
    sector = num;
}

//Name:   setType()
//Desc:
//input:  none
//output: none
//return: none
void Request::setType(char *str) {
    type = getFromString(str);
}

//Name:   print()
//Desc:
//input:  none
//output: none
//return: none
void Request::print() const {
    const char *structureType = str(type);
    cout << structureType << " in sector " << getSector() << endl;
}
//
// Created by Jeremiah Barro on 19/7/2023.
//

#include "request.h"

//Name:   Request
//Desc:   Default Request constructor.
//input:  none
//output: none
//return: none
Request::Request() {
    this->sector = 0;
    this->type = UNK;
}

//Name:   Request
//Desc:   Request constructor.
//input:  An integer for the sector number and an enum structure_type to be built.
//output: none
//return: none
Request::Request(int sector, structure_type type) {
    this->sector = sector;
    this->type = type;
}

//Name:   getSector
//Desc:   Getter for the sector number.
//input:  none
//output: none
//return: An integer representing the structure number.
int Request::getSector() const {
    return sector;
}

//Name:   getType
//Desc:   Getter for the structure_type.
//input:  none
//output: none
//return: Enum for structure_type.
char* Request::getType() const {
    char* str = new char[20];
    toString(type, str);
    return str;
}

//Name:   setSector
//Desc:   Setter for sector.
//input:  Integer representing the sector number.
//output: none
//return: none
void Request::setSector(int num) {
    sector = num;
}

//Name:   setType
//Desc:   Setter for the structure_type.
//input:  Char pointer for the characters entered for the structure_type.
//output: none
//return: none
void Request::setType(char *str) {
    type = getFromString(str);
}

//Name:   print
//Desc:   Prints the Request instance structure_type and sector.
//input:  none
//output: The Request instance structure_type and sector.
//return: none
void Request::print() const {
    const char *structureType = str(type);
    cout << structureType << " in sector " << getSector() << endl;
}
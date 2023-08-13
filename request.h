//
// Created by Jeremiah Barro on 19/7/2023.
//

#ifndef BUILDERS_REQUEST_H
#define BUILDERS_REQUEST_H

#include <iostream>
#include "structuretype.h"

using namespace std;

class Request {
private:
    int sector;
    structure_type type;
public:
    Request(int,structure_type);
    int getSector() const;
    char * getType() const;
    void setSector(int);
    void setType(char *str);
    void print() const;
};

#endif //BUILDERS_REQUEST_H

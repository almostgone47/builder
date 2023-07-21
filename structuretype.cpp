#include <cstring>
#include "structuretype.h"

//Name:   getFromString
//Desc:   Gets the enum structure_type from a string indicating the desired type.
//input:  Char pointer to string entered for the desired type.
//output: none
//return: Enum structure_type.
structure_type getFromString(const char* str)
{
    structure_type ret = WATER;
    if (strcmp(str,"wind")==0)
    {
	ret = WIND;
    }
    else if (strcmp(str,"water")==0)
    {
	ret = WATER;
    }
    else if (strcmp(str,"solar")==0)
    {
	ret = SOLAR;
    } else
    {
    ret = UNK;
    }
    return ret;
}

//Name:   toString
//Desc:   Converts an enum structure_type to a readable string.
//input:  An enum structure_type and a char pointer to "copy" the string to.
//output: none
//return: none
void toString(const structure_type type,char* str)
{
    switch (type)
    {
	case WIND:
	    strcpy(str,"wind");
	    break;
	case WATER:
	    strcpy(str,"water");
	    break;
	case SOLAR:
	    strcpy(str,"solar");
	    break;
    case UNK:
        strcpy(str,"unknown");
    }
}

//Name:   str
//Desc:   Using an enum structure_type, creates a string for printing the full description of the structure type.
//input:  An enum structure_type.
//output: none
//return: A pointer to the full string description of the structure type.
const char* str(const structure_type type)
{
    const char* ptr;
    switch (type)
    {
	case WIND:
	    ptr = "wind turbine";
	    break;
	case WATER:
	    ptr = "water harvester";
	    break;
	case SOLAR:
	    ptr = "solar energy collector";
	    break;
    default:
        ptr = "unknown structure";
    }
    return ptr;
}

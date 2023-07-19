#include <cstring>
#include "structuretype.h"

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

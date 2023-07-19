#include <iostream>
#include "linkedlist.h"
#include "request.h"
#include "structuretype.h"

using namespace std;

void printRequest(Request e)
{
    cout << "Sector: " << e.getSector() << " Structure: " << e.getType() << endl;
}

void dumpList(LinkedList &ll)
{
    cout << "Dumping the linkedlist" << endl;
    while (!ll.isEmpty())
    {
	    Request result;
        ll.removeBack(result);
	    printRequest(result);
    }
}

int main()
{
    LinkedList ll;
    Request e1(1,WIND);
    Request e2(2,WATER);

    cout << "dump list before adding" << endl;
    dumpList(ll);
    ll.addFront(e1);
    dumpList(ll);
    ll.addFront(e1);
    ll.addFront(e2);
    dumpList(ll);
    
    return 0;
}

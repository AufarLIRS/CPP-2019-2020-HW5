#include <iostream>
#include "Counted.h"

using namespace std;

int main()
{
    vector<Counted*> countedList;
    Counted* a = new Counted();

    Counted* b = new Counted();
    Counted* c = new Counted();
    Counted* d = new Counted();
            delete d;
    Counted* e = new Counted();
        countedList.push_back(a);
        countedList.push_back(b);
        countedList.push_back(c);
        countedList.push_back(e);
       // countedList().push_back(c);
       // countedList().push_back(d);
       // countedList().push_back(e);


        cout<<countedList.back()->getId();

    return 0;
}

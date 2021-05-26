#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "BagIterator.h"
#include <iostream>

using namespace std;

int main() {

    Bag b;
    b.add(5);
    b.add(18);
    b.add(16);
    b.add(15);
    b.add(13);
    b.add(31);
    b.add(26);
    cout<<"Primul Bag:\n";
    b.afisare();
    Bag b2;
    b2.add(10);
    b2.add(26);
    b2.add(16);
    b2.add(15);
    b2.add(13);
    b2.add(31);
    b2.add(5);
    b2.add(18);
    b2.add(16);
    b2.add(15);
    cout<<"Al doilea Bag:\n";
    b2.afisare();

    Bag b3 ;
    b3.vereinigung(b, b2);
    cout<<"Al treilea Bag:\n";
    b3.afisare();


    testAll();
    cout << "Short tests over" << endl;
    testAllExtended();

    cout << "All test over" << endl;

}
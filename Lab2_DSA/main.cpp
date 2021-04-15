#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"
#include <assert.h>
using namespace std;


int main() {

    testAll();
    testAllExtended();

    MultiMap m;
    m.delete_key(1);
    assert(m.size() == 0);
    m.add(1, 100);
    m.add(1, 200);
    m.add(3, 300);
    m.add(1, 500);
    m.add(2, 600);
    m.add(1, 700);

    assert(m.size() == 6);

    m.delete_key(1);
    assert(m.size() == 2);

    m.add(3, 3);
    m.add(1, 5);
    m.add(2, 6);
    m.add(1, 7);

    assert(m.size() == 6);

    m.delete_key(3);
    assert(m.size() == 4);

    m.delete_key(1000);
    assert(m.size() == 4);
    cout<<"totul e bn :)"<<endl;
    cout << "End" << endl;
    system("pause");
}

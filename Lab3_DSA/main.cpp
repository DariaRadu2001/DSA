#include <iostream>
#include "SortedIteratedList.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "ListIterator.h"
#include <cassert>
typedef int TComp;

bool asc1(TComp c1, TComp c2) {
    if (c1 >= c2) {
        return true;
    } else {
        return false;
    }
}

void testFunc() {
    SortedIteratedList list = SortedIteratedList(asc1);
    list.add(1);
    list.add(2);
    list.add(-3);
    list.add(3);
    list.add(11);
    list.add(4);
    list.add(-1);
    list.add(-5);
    list.add(-6);
    list.add(-7);
    ListIterator it = list.first();

    while (it.valid()) {
        std::cout << it.getCurrent() << " ";
        it.next();
    }
    std::cout << '\n';
    list.k_loschen(1);
    assert(list.size() == 0);
    list.add(1);
    list.add(2);
    list.add(-3);
    list.add(3);
    list.add(11);
    list.add(4);
    list.add(-1);
    list.add(-5);
    list.add(-6);
    list.add(-7);
    it.first();


    list.k_loschen(2);
    while (it.valid()) {
        std::cout << it.getCurrent() << " ";
        it.next();
    }
    std::cout << '\n';
    assert(list.size() == 5);
    list.k_loschen(1);
    assert(list.size() == 0);
    list.add(1);
    list.add(2);
    list.add(-3);
    list.add(3);
    list.add(11);
    list.add(4);
    list.add(-1);
    list.add(-5);
    list.add(-6);
    list.add(-7);
    it.first();
    list.k_loschen(4);
    assert(list.size() == 8);
    while (it.valid()) {
        std::cout << it.getCurrent() << " ";
        it.next();
    }
    std::cout << '\n';

}

int main(){
    testAll();
    testAllExtended();
    testFunc();
    std::cout<<"Finished IL Tests!"<<std::endl;
    system("pause");
    return 0;
}
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "assert.h"
#include "SortedMap.h"
#include "SMIterator.h"

#include <iostream>
using namespace std;

bool relation(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    SortedMap sm(relation);
    assert(sm.size() == 0);
    assert(sm.isEmpty());
    sm.add(1,2);
    sm.add(2,2);
    sm.add(3,2);
    sm.add(4,2);
    sm.add(5,2);
    assert(sm.size() == 5);
    SMIterator it = sm.iterator();
    it.first();
    int ct = 0;
    while (it.valid())
    {
        ct++;
        TElem e = it.getCurrent();
        cout<<"key:"<<e.first<<" value:"<<e.second<<endl;
        if(ct == 3)
        {
            it.set(10,10);
            e = it.getCurrent();
            cout<<"new key:"<<e.first<<" new value:"<<e.second<<endl;
        }
        if(ct == 4)
        {
            try {
                it.set(1,8);
                assert(false);
            }
            catch (exception&) {
                assert(true);
            }
        }
        it.next();
    }
    cout<<"VERIFIC\n";
    it.first();
    while (it.valid())
    {
        TElem e = it.getCurrent();
        cout<<"key:"<<e.first<<" value:"<<e.second<<endl;
        it.next();
    }
    cout<<"Testele normale\n";
    testAll();
    cout<<"testele usoare merg <3\n";
    testAllExtended();

    cout << "That's all!" << endl;
    system("pause");
    return 0;
}



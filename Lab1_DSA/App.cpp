#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
#include <assert.h>
using namespace std;




int main() {

    testAll();
    testAllExtended();
    cout<<"HIER BEGINNT DAS ZUSATZFUNKTION"<<endl;
    Set s;

    int a,b;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;

    //a soll kleiner als b sein
    if(a > b)
    {
        int c = a;
        a = b;
        b = c;
    }

    assert(s.size()==0);
    s.Bonus(a,b);
    assert(s.size()==b-a+1);
    assert(s.search(a)==true);
    assert(s.search(b)==true);

    SetIterator it = s.iterator();
    it.first();
    int ct = 0;
    while (it.valid()) {
        ct++;
        it.next();
    }
    assert(ct == s.size());

    Set s2;
    s2.Bonus(-10,30);
    assert(s2.size()==41);
    assert(s2.search(-5)==true);
    assert(s2.search(9)==true);
    assert(s2.search(-50)==false);
    assert(s2.search(-3)==true);
    assert(s2.search(-10)==true);
    assert(s2.search(200)==false);

    SetIterator it2 = s2.iterator();
    it2.first();
    int sum = 0;
    while (it2.valid()) {
        TElem e = it2.getCurrent();
        sum += e;
        it2.next();
    }
    assert(sum == 410);

    cout<<"gut"<<endl;
    cout << "That's all!" << endl;
    system("pause");

}




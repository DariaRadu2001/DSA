#include "SetIterator.h"
#include "Set.h"
#include <exception>

using namespace std;
//Theta(1)
SetIterator::SetIterator(const Set& m) : set(m)
{
    //TODO - Implementation
    this->index = 0;
}

//Theta(1)
void SetIterator::first() {
    //TODO - Implementation
    this->index = 0;
}

//Best=Theta(1) Worst=Theta(n) Avg=Theta(n)
void SetIterator::next() {
    //TODO - Implementation
    if(set.nrElem == 0)
        throw exception();

    if(this->index > set.cap.max)
        throw exception();

    do {
        this->index++;
    }
    while( set.cap.min <= this->index && this->index <= set.cap.max && set.set[this->index]==0);



}

//Theta(1)
TElem SetIterator::getCurrent()
{
    //TODO - Implementation
    if(set.nrElem == 0)
        throw exception();

    if(this->index > set.cap.max)
        throw exception();

    int elem = set.wertebereich.min + this->index;
    if( set.cap.min<= this->index && this->index <= set.cap.max && set.set[this->index] == true)
        return elem;
    else
        //asa trebuie
        return 0;
}

//Theta(1)
bool SetIterator::valid() const {
    //TODO - Implementation
    if(set.nrElem == 0)
        return false;

    if( set.cap.min<= this->index && this->index <= set.cap.max)
        return true;
    else
        return false;
}



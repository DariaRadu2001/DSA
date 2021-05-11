#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

//theta(1)
ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
    //TODO - Implementation
    this->index = list.head;
}

//theta(1)
void ListIterator::first(){
    //TODO - Implementation
    if(list.isEmpty())
        this->index = -1;
    else
        this->index = list.head;
}

//theta(1)
void ListIterator::next() {
    //TODO - Implementation
    if (this->valid())
        this->index = list.next[this->index]; //trebuie sa se duca pe elementul de pe next
    else
        throw exception();
}

//theta(1)
bool ListIterator::valid() const{
    //TODO - Implementation

    if(this->index >=list.cap)
        return false;

    if(list.isEmpty())
        return false;

    if(this->index < 0)
        return false;

    if(0 <= this->index &&  this->index < list.cap)
        if(list.liste_elemente[this->index] != NULL_TCOMP)
            return true;

    return false;
}

//theta(1)
TComp ListIterator::getCurrent() const{
    //TODO - Implementation
    if(this->valid())
        return list.liste_elemente[this->index];
    else
        throw exception();
}



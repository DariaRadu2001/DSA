#include "MultiMapIterator.h"
#include "MultiMap.h"
#include <exception>

//Theta(1)
MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    //TODO - Implementation
    this->el_current = col.head;

}

//Theta(1)
TElem MultiMapIterator::getCurrent() const{
    //TODO - Implementation
    /*if(col.size() == 0 || this->el_current == nullptr)
        throw exception();
        */
    if(this->valid())
    {
        TElem elem;
        /*elem.first = this->el_current->info.first;
        elem.second = this->el_current->info.second;
        */
        elem = this->el_current->info;
        return elem;
    }
    else
        throw exception();

}

//Theta(1)
bool MultiMapIterator::valid() const {
    //TODO - Implementation
    if(col.nrElem == 0)
        return false;

    if(this->el_current == nullptr)
        return false;

    //ist head
    if(this->el_current == col.head)
        return true;

    //ist tail
    if(this->el_current == col.tail)
        return true;

    //ist im mitte
    if(this->el_current->prev != nullptr && this->el_current->next != nullptr)
        return true;

    return false;

}

//Theta(1)
void MultiMapIterator::next() {
    //TODO - Implementation
    /*if(col.size() == 0)
        throw exception();

    if(this->el_current != nullptr)
        this->el_current = this->el_current->next;
    else
        throw exception();
    */
    if(this->valid())
        this->el_current = this->el_current->next;
    else
        throw exception();

}

//Theta(1)
void MultiMapIterator::first() {
    //TODO - Implementation
    this->el_current = col.head;
}


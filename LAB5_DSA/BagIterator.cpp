#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
BagIterator::BagIterator(const Bag& c): bag(c)
{
    //TODO - Implementation
    bool gasit = false;
    for(int i = 0; i < bag.m && !gasit; i++)
        if(bag.list[i] != -1111111)
        {
            gasit = true;
            this->index = i;
        }
}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
void BagIterator::first() {
    //TODO - Implementation

    bool gasit = false;
    for(int i = 0; i < bag.m && !gasit; i++)
        if(bag.list[i] != -1111111)
        {
            gasit = true;
            this->index = i;
        }
}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
void BagIterator::next() {
    //TODO - Implementation
    if(this->valid())
    {
        do{
            this->index++;
        }
        while(bag.list[this->index] == -1111111);
    }
    else
        throw exception();

}

//Theta(1)
bool BagIterator::valid() const {
    //TODO - Implementation
    if(bag.isEmpty() || bag.size() == 0 || this->index >= bag.m || this->index < 0)
        return false;

    if(bag.list[this->index] != -1111111)
        return true;
    else
        return false;

}


//Theta(1)
TElem BagIterator::getCurrent() const
{
    //TODO - Implementation
    if(this->valid())
    {
        return bag.list[this->index];
    }
    else
        throw exception();
}

#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
SMIterator::SMIterator(const SortedMap& m) : map(m){
    //TODO - Implementation
    this->stack = Stack();
    this->el_current = map.wurzel;
    while (this->el_current != nullptr) {
        stack.push(this->el_current);
        this->el_current = this->el_current->links_k;
    }
    if (!stack.isEmpty()) {
        this->el_current = stack.top();
    }
    else {
        this->el_current = nullptr;
    }

}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
void SMIterator::first(){
    //TODO - Implementation
    this->stack = Stack();
    this->el_current = map.wurzel;
    while (this->el_current != nullptr) {
        stack.push(this->el_current);
        this->el_current = this->el_current->links_k;
    }
    if (!stack.isEmpty()) {
        this->el_current = stack.top();
    }
    else {
        this->el_current = nullptr;
    }
}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
void SMIterator::next(){
    //TODO - Implementation

    if (!this->valid())
        throw exception();

    else
    {
        Nod* parinte = this->stack.top();
        this->stack.pop();
        if (parinte->rechts_k != nullptr)
        {
            parinte = parinte->rechts_k;
            while (parinte != nullptr)
            {
                this->stack.push(parinte);
                parinte = parinte->links_k;
            }
        }
        if (!this->stack.isEmpty())
        {
            this->el_current = this->stack.top();
        }
        else
            this->el_current = nullptr;

    }

}

//Theta(1)
bool SMIterator::valid() const{
    //TODO - Implementation
    if(map.nrElem == 0)
        return false;

    if(this->el_current == nullptr)
        return false;

    //ist wurzel
    if(this->el_current == map.wurzel)
        return true;

    if(this->el_current != nullptr)
        return true;

    return false;
}

//Theta(1)
TElem SMIterator::getCurrent() const{
    //TODO - Implementation
    if(this->valid())
    {
        TElem elem;
        elem.first = this->el_current->info.first;
        elem.second = this->el_current->info.second;
        return elem;
    }
    else
        throw exception();
}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
void SMIterator::set(TKey k, TValue v)
{
    if(!this->valid())
        throw exception();
    TElem elem_vechi;
    elem_vechi.first = el_current->info.first;
    elem_vechi.second = el_current->info.second;
    if(map.search(k) != NULL_TVALUE)
        throw exception();
    else
    {
        bool ok = false;
        this->el_current->info.first = k;
        this->el_current->info.second = v;
        Stack stack2 = Stack();
        while(!this->stack.isEmpty())
        {
            if(this->stack.top()->info == elem_vechi)
            {
                stack2.push(this->el_current);
                this->stack.pop();
            }
            else
            {
                stack2.push(this->stack.top());
                this->stack.pop();
            }

        }
        while(!stack2.isEmpty())
        {
            this->stack.push(stack2.top());;
            stack2.pop();
        }

    }
}



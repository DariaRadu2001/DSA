#pragma once
typedef int TKey;
typedef int TValue;
#include <utility>
#include "SortedMap.h"
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);

struct Nod_stack{

    Nod_stack* next;
    Nod_stack* prev;
    Nod* info;
};

class Stack {

private:
    //TODO - Representation
    Nod_stack* head;
    Nod_stack* tail;
    int nrElem_stack;

public:

    Stack();

    //bag un element la capat "deasupra"
    void push(Nod* e);

    //returns the element from the front of the stack 'ala din varf'
    //throws exception if the queue is empty
    Nod* top() const;

    //scot si returnez ultimul el bagat in stack
    //throws exception if the stack is empty
    void pop();

    //checks if the stack is empty
    bool isEmpty() const;

    // destructor
    ~Stack();
};

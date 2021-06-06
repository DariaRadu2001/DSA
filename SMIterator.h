#pragma once
#include "SortedMap.h"
#include "Stack.h"
//DO NOT CHANGE THIS PART
class SMIterator{
    friend class SortedMap;
    friend class Stack;
private:
    const SortedMap& map;
    SMIterator(const SortedMap& mapionar);

    //TODO - Representation
    Nod* el_current;
    Stack stack;

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
    void set(TKey k, TValue v);
};


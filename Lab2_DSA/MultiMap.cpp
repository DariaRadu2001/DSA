#include "MultiMap.h"
#include "MultiMapIterator.h"
//#include <exception>
//#include <iostream>

using namespace std;

//Theta(1)
MultiMap::MultiMap() {
    //TODO - Implementation
    this->head = nullptr;
    this->tail = nullptr;
    this->nrElem = 0;
}

//Theta(1)
void MultiMap::add(TKey c, TValue v) {
    //TODO - Implementation
    TElem elem;
    elem.first = c;
    elem.second = v;
    if(this->nrElem == 0)
    {
        this->head = new DLLNode();
        this->head->info = elem;
        this->head->prev = nullptr;
        this->head->next = nullptr;
        this->tail = this->head;
        this->nrElem++;
    }
    else
        if(this->nrElem == 1)
        {
            this->tail = new DLLNode();
            this->tail->info = elem;
            this->tail->prev = this->head;
            this->head->next = this->tail;
            this->tail->next = nullptr;
            this->nrElem++;
        }
        else
        {
            DLLNode* nod = new DLLNode();
            nod->info = elem;
            nod->prev = this->tail;
            nod->next = nullptr;
            this->tail->next = nod;
            this->tail = nod;
            this->nrElem++;
        }

}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n)
bool MultiMap::remove(TKey c, TValue v) {
    //TODO - Implementation
    if(this->nrElem == 0)
        return false;

    TElem elem;
    elem.first = c;
    elem.second = v;

    bool remove = false;
    //head
    DLLNode* copie;

    //cautam head
    if(this->head->info == elem)
    {
        copie = this->head;
        //nodul de dupa primeste la prev null, rup legatura
        if(this->nrElem > 2)
        {

            this->head->next->prev = nullptr;
            this->head = this->head->next;
            copie->next = nullptr;
            delete copie;
            this->nrElem--;
            return true;
        }
        else
            //ich habe nur tail und head
            if(this->nrElem == 2)
            {
                this->head = this->tail;
                this->tail->prev = nullptr;
                copie->next = nullptr;
                delete copie;
                this->nrElem--;
                return true;

            }
            else
                if(this->nrElem == 1)
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                    this->nrElem --;
                    delete copie;
                    return true;
                }

    }
    else//tail
        if(this->tail->info == elem)
        {
            copie = this->tail;
            //nodul de dupa primeste la prev null, rup legatura
            if(this->nrElem > 2)
            {

                this->tail->prev->next = nullptr;
                this->tail = this->tail->prev;
                copie->prev = nullptr;
                delete copie;
                this->nrElem--;
                return true;
            }
            else
                if(this->nrElem == 1)
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                    this->nrElem --;
                    delete copie;
                    return true;
                }
                else
                    if(this->nrElem == 2)
                    {
                        this->tail = this->head;
                        copie->prev = nullptr;
                        this->head->next = nullptr;
                        delete copie;
                        this->nrElem--;
                        return true;
                    }
        }

    copie = this->head->next;
    //Mitte
    while(copie != nullptr  && copie->info != elem)
        copie = copie->next;

    if(copie != nullptr)
    {
        copie->prev->next = copie->next;
        copie->next->prev = copie->prev;
        copie->prev = nullptr;
        copie->next = nullptr;
        this->nrElem --;
        delete copie;
        remove = true;
    }

    return remove;
}

//Theta(n)
vector<TValue> MultiMap::search(TKey c) const {
    //TODO - Implementation

    vector <TValue> valori;
    if(this->nrElem == 0)
        return valori;
    DLLNode* copie = this->head;
    while(copie != nullptr)
    {
        if(copie->info.first == c)
            valori.push_back(copie->info.second);
        copie = copie->next;
    }

    return valori;
}

//Theta(1)
int MultiMap::size() const {
    //TODO - Implementation
        return this->nrElem;
}

//Theta(1)
bool MultiMap::isEmpty() const {
    //TODO - Implementation
    if( this->nrElem == 0)
        return true;

    return false;
}

//Theta(1)
MultiMapIterator MultiMap::iterator() const {
    return MultiMapIterator(*this);
}

//Theta(n)
void MultiMap::delete_key(TKey k)
{
    DLLNode* current = this->head;
    DLLNode* next;
    bool verif;
    while(current != nullptr) {
        verif = false;
        if (current->info.first == k) {
             next = current->next;
            this->remove(k, current->info.second);
            verif = true;
        }
        if(verif)
            current = next;
        else
            current = current->next;
    }

}

//Theta(n)
MultiMap::~MultiMap() {

    //TODO - Implementation

    if (this->head != nullptr)
    {
        DLLNode* current = this->head;
        DLLNode* next = this->head->next;

        while(current != nullptr)
        {
            delete current;
            current = next;
            if(next != nullptr)
            {
                current->prev = nullptr;
                next = current->next;
            }

        }
    }

}
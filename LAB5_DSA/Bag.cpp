#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <cmath>
using namespace std;


bool prim(int nr)
{
    bool prim = true;
    for(int i = 2; i <= sqrt(nr) && prim ; i++)
        if(nr%i == 0)
            prim = false;

    return prim;
}


void gasire_nr_prim(int &nr)
{
    bool gasit = false;
    while(!gasit)
    {
        nr++;
        gasit = prim(nr);
    }
}

//Theta(n)
Bag::Bag() {
    //TODO - Implementation
    this->nrElem = 0;
    this->m = 13;
    this->list = new TElem [this->m];
    this->next = new int[this->m];
    this->firstFree = 0;
    for(int i = 0; i < this->m; i++)
    {
        this->list[i] = -1111111;
        this->next[i] = -1;
    }

}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
void Bag::newFree(TElem* list)
{
    this->firstFree++;
    while(this->firstFree < this->m && list[this->firstFree] != -1111111)
        this->firstFree++;
}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1) -->Theata(1) amortizat
void Bag::add(TElem elem) {
    //TODO - Implementation
    //resize and rehash
    if(this->firstFree == this->m)
    {
        int cap_veche = this->m;
        this->m = this->m*2;
        gasire_nr_prim(this->m);
        TElem* new_list = new TElem [this->m];
        int* new_next = new int[this->m];
        //initializez noiile liste ca si cum ar fi goale
        for(int i = 0; i < this->m; i++)
        {
            new_list[i] = -1111111;
            new_next[i] = -1;
        }

        //repun elementele cu noul m
        this->firstFree =  0;
        for(int i = 0; i < cap_veche; i++)
        {
            TElem element = this->list[i];
            int pos = h(element, this->m);

            //pozitia e goala unde trebuie pus elementul
            if(new_list[pos] == -1111111)
            {
                new_list[pos] = element;
                if(this->firstFree == pos)
                    newFree(new_list);
            }
            else
                //caz cu coliziune
            {
                int prev; //elementul dinainte unde trebuie sa schimb nextul
                prev = pos;
                while(new_next[prev] != -1)
                    prev = new_next[prev];
                new_next[prev] = this->firstFree;
                new_list[this->firstFree] = element;
                newFree(new_list);
            }
        }
        delete [] this->list;
        delete [] this->next;
        this->list = new_list;
        this->next = new_next;

    }

    int pos = h(elem, this->m);

    //pozitia e goala unde trebuie pus elementul
    if(this->list[pos] == -1111111)
    {
        this->list[pos] = elem;
        this->nrElem++;
        if(this->firstFree == pos)
            newFree(this->list);
    }
    else
    //caz cu coliziune
    {
        this->nrElem++;
        int prev; //elementul dinainte unde trebuie sa schimb nextul
        prev = pos;
        while(this->next[prev] != -1)
            prev = this->next[prev];
        this->next[prev] = this->firstFree;
        this->list[this->firstFree] = elem;
        newFree(this->list);
    }
}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
bool Bag::remove(TElem elem) {
    //TODO - Implementation

    if(this->isEmpty())
        return false;

    int pos = h(elem, this->m);
    int prev = -1;
    int l = 0;

    while(l < this->m && prev==-1)
    {
        if(this->next[l]==pos)
            prev = l;
        l++;
    }

    //avem elementul in lista si nu apare coliziune
    if(this->next[pos] == -1 && this->list[pos] == elem)
    {
        this->nrElem--;
        this->list[pos] = -1111111;
        if(this->firstFree > pos)
            this->firstFree = pos;

        return true;
    }

    //cazul cu coliziune
    else
    {
        while(this->list[pos] != elem && pos != -1)
        {
            prev = pos;
            pos = this->next[pos];
        }

        if(pos == -1)
            return false;
        else
            {
                bool over = false;
                int next_hash;
                int prev_hash;
                this->nrElem--;
                do{
                    next_hash = this->next[pos];
                    prev_hash = pos;
                    while(h(this->list[next_hash],this->m) != pos && next_hash != -1)
                    {
                        prev_hash = next_hash;
                        next_hash = this->next[next_hash];
                    }
                    if(next_hash == -1)
                        over = true;
                    else
                    {
                        this->list[pos] = this->list[next_hash];
                        prev = prev_hash;
                        pos = next_hash;
                    }
                }
                while(!over);

            if(prev != -1)
                this->next[prev] = this->next[pos];

            this->list[pos] = -1111111;
            this->next[pos] = -1;

            if(this->firstFree > pos)
                this->firstFree = pos;
            return true;
        }

    }

}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
bool Bag::search(TElem elem) const {
    //TODO - Implementation
    if(this->isEmpty())
        return false;

    int pos = h(elem, this->m);

    while(pos != -1 && this->list[pos] != elem)
        pos = this->next[pos];

    if(pos == -1)
        return false;
    else
        return true;
}

//Worst:Theta(n) Avg:Theta(n) Best:Theta(1)
int Bag::nrOccurrences(TElem elem) const {
    //TODO - Implementation
    if(this->isEmpty())
        return 0;

    int pos = h(elem, this->m);
    int aparitii = 0;

    while(pos != -1)
    {
        if(this->list[pos] == elem)
            aparitii++;

        pos = this->next[pos];
    }

    return aparitii;
}

//Theta(1)
int Bag::size() const {

    return this->nrElem;
}

//Theta(1)
bool Bag::isEmpty() const {
    //TODO - Implementation
    if(this->nrElem == 0)
        return true;

    return false;
}

//Theta(1)
BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

int Bag::marime() {
    return this->m;
}

//Theta(n)
void Bag::vereinigung(const Bag & b1, const Bag &b2)
{
    Bag b3;
    b3.m = b1.nrElem + b2.nrElem;
    bool gasit = false;
    while(!gasit)
    {
        gasit = prim(b3.m);
        if(!gasit)
            b3.m++;
    }

    TElem* new_list = new TElem [b3.m];
    int* new_next = new int[b3.m];
    for(int i = 0; i < b3.m; i++)
    {
        new_list[i] = -1111111;
        new_next[i] = -1;
    }

    delete [] b3.list;
    delete [] b3.next;
    b3.list = new_list;
    b3.next = new_next;

    TElem elem;
    b3.firstFree = 0;

    for (int i = 0; i < b1.m; i++)
    {
        if (b1.list[i] != -1111111)
        {
            elem = b1.list[i];
            int pos = b3.h(elem, b3.m);

            //pozitia e goala unde trebuie pus elementul
            if (b3.list[pos] == -1111111)
            {
                b3.list[pos] = elem;
                b3.nrElem++;
                if (b3.firstFree == pos)
                {
                    b3.firstFree++;
                    while (b3.firstFree < b3.m && b3.list[b3.firstFree] != -1111111)
                        b3.firstFree++;
                }
            }
            else
                //caz cu coliziune
            {
                b3.nrElem++;
                int prev; //elementul dinainte unde trebuie sa schimb nextul
                prev = pos;
                while (b3.next[prev] != -1)
                    prev = b3.next[prev];
                b3.next[prev] = b3.firstFree;
                b3.list[b3.firstFree] = elem;
                b3.firstFree++;
                while (b3.firstFree < b3.m && b3.list[b3.firstFree] != -1111111)
                    b3.firstFree++;


            }


        }
    }

    for (int j = 0; j < b2.m; j++)
    {
        if (b2.list[j] != -1111111)
        {
            elem = b2.list[j];
            int pos = b3.h(elem, b3.m);

            //pozitia e goala unde trebuie pus elementul
            if (b3.list[pos] == -1111111)
            {
                b3.list[pos] = elem;
                b3.nrElem++;
                if (b3.firstFree == pos)
                {
                    b3.firstFree++;
                    while (b3.firstFree < b3.m && b3.list[b3.firstFree] != -1111111)
                        b3.firstFree++;
                }
            }
            else
                //caz cu coliziune
            {
                b3.nrElem++;
                int prev; //elementul dinainte unde trebuie sa schimb nextul
                prev = pos;
                while (b3.next[prev] != -1)
                    prev = b3.next[prev];
                b3.next[prev] = b3.firstFree;
                b3.list[b3.firstFree] = elem;
                b3.firstFree++;
                while (b3.firstFree < b3.m && b3.list[b3.firstFree] != -1111111)
                    b3.firstFree++;


            }


        }
    }

    delete [] this->list;
    delete [] this->next;
    this->list = b3.list;
    this->next = b3.next;
    this->nrElem = b3.nrElem;
    this->m = b3.nrElem;
    this->firstFree = b3.firstFree;


}

void Bag::afisare()
{
    BagIterator it = this->iterator();
    it.first();
    while (it.valid()) {
        TElem e = it.getCurrent();
        cout<<e<<"\n";
        it.next();
    }
}

//Theta(1)
Bag::~Bag() {
    //TODO - Implementation
    delete [] this->list;
    delete [] this->next;
}


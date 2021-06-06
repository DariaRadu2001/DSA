#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

//Theta(1)
SortedMap::SortedMap(Relation r) {
    //TODO - Implementation
    this->nrElem = 0;
    this->relation = r;
    this->wurzel = nullptr;
}

//Theta(1)
Nod* SortedMap::initNode(TElem elem)
{

    Nod* nod = new Nod();
    nod->info = elem;
    nod->links_k = nullptr;
    nod->rechts_k = nullptr;
    return nod;

}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
Nod* SortedMap::insert_rec(Nod* nod, TElem elem, Relation rel)
{
    if(nod == nullptr)
        nod = initNode(elem);
    else
        if(rel(elem.first, nod->info.first))
            nod->links_k = insert_rec(nod->links_k, elem, rel);
        else
        {
            nod->rechts_k = insert_rec(nod->rechts_k, elem, rel);
        }

    return nod;

}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
TValue SortedMap::add(TKey k, TValue v) {
    //TODO - Implementation
    TElem elem;
    elem.first = k;
    elem.second = v;

    //cazul in care am cheie si trebuie sa inlocuiesc valoarea de la cheie si sa retunez val veche
    if (this->search(k) != NULL_TVALUE)
    {
        TValue vechi = this->search(k);
        bool ok = false;
        Nod* nod ;
        nod = this->wurzel;
        while(!ok)
        {
            if(nod->info.first == k)
            {
                nod->info.second = v;
                ok = true;
            }
            else
                if(relation(k, nod->info.first))
                    nod = nod->links_k;
                else
                    nod = nod->rechts_k;
        }

        return vechi;
    }

    this->wurzel = insert_rec(this->wurzel, elem, this->relation);
    this->nrElem++;
    return NULL_TVALUE;

}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
TValue SortedMap::search_rec(TKey k, Nod* nod) const {

    if(nod == nullptr)
        return NULL_TVALUE;
    else
        if(nod->info.first == k)
            return nod->info.second;
        else
            if(relation(k, nod->info.first))
                return search_rec(k, nod->links_k);
            else
                return search_rec(k, nod->rechts_k);

}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
TValue SortedMap::search(TKey k) const {
    //TODO - Implementation
    return search_rec(k, this->wurzel);
}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
Nod* SortedMap::minimum(Nod* nod)
{
    Nod* current = nod;
    if(current == nullptr)
        return nullptr;
    else
        while(current->links_k != nullptr)
            current = current->links_k;

    return current;
}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
Nod* SortedMap::remove_rec(Nod* nod, TKey k, Relation rel)
{

    if(nod->info.first == k)
    {
        if(nod->links_k == nullptr && nod->rechts_k == nullptr)
        {
            /*TValue v = nod->info.second;

            Nod* aux = new Nod();
            aux->info.second = v;
            return  aux;*/
            delete nod;
            return nullptr;
        }
        else
            if(nod->links_k == nullptr && nod->rechts_k != nullptr)
            {
                /*TValue v_de_sters = nod->info.second;
                delete nod;
                return v_de_sters;*/
                Nod* aux = nod->rechts_k;
                delete nod;
                return aux;
            }
            else
                if(nod->links_k != nullptr && nod->rechts_k == nullptr)
                {
                    /*TValue v_de_sters = nod->info.second;
                    Nod* aux;
                    aux = nod->links_k;
                    nod->info = aux->info;
                    nod->links_k = aux->links_k;
                    nod->rechts_k = aux->rechts_k;
                    delete aux;
                    return v_de_sters;*/
                    Nod* aux = nod->links_k;
                    delete nod;
                    return aux;
                }
                else
                {
                    Nod* min = minimum(nod->rechts_k);
                    nod->info = min->info;
                    nod->rechts_k = remove_rec(nod->rechts_k, min->info.first, rel);
                    return nod;
                }
    }
    else
        if(relation(k, nod->info.first))
        {
            nod->links_k = remove_rec(nod->links_k, k, rel);
            return nod;
        }
        else
        {
            nod->rechts_k = remove_rec(nod->rechts_k, k, rel);
            return nod;
        }


}

//Best:Theta(1) Worst:Theta(n) Avg:Theta(n) --> O(n)
TValue SortedMap::remove(TKey k) {
    //TODO - Implementation
    TValue val;
    val = search(k);
    if(val == NULL_TVALUE)
        return NULL_TVALUE;

    if(this->wurzel == nullptr)
        return NULL_TVALUE;

    this->nrElem--;
    this->wurzel = remove_rec(this->wurzel, k, this->relation);
    return val;


}

//Theta(1)
int SortedMap::size() const {
    //TODO - Implementation
    return this->nrElem;
}

//Theta(1)
bool SortedMap::isEmpty() const {
    //TODO - Implementation
    if(this->nrElem == 0)
        return true;
    return false;
}

//Theta(1)
SMIterator SortedMap::iterator() const {
    return SMIterator(*this);
}

//Theta(n)
SortedMap::~SortedMap() {
    //TODO - Implementation
    if(!isEmpty())
        while (this->wurzel != nullptr)
        {
            remove(this->wurzel->info.first);
        }

}

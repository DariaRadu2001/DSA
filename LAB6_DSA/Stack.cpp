#include "Stack.h"
#include <exception>
using namespace std;

//Theta(1)
Stack::Stack()
{
    this->nrElem_stack = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

//bag un element la capat "deasupra"
//Theta(1)
void Stack::push(Nod* e)
{
    //adaug fix la inceput
    if(this->nrElem_stack == 0)
    {
        this->head = new Nod_stack();
        this->head->info = e;
        this->head->next = nullptr;
        this->head->prev = nullptr;
        this->tail = this->head;
        this->head->prev = nullptr;
        this->nrElem_stack ++;
    }
    else
        //am si tail acum
    if(this->nrElem_stack == 1)
    {
        this->tail = new Nod_stack();
        this->tail->info = e;
        this->head->next = this->tail;
        this->tail->next = nullptr;
        this->tail->prev = this->head;
        this->nrElem_stack++;
    }
    else
    {
        Nod_stack* nod = new Nod_stack();
        nod->info = e;
        nod->next = nullptr;
        nod->prev = this->tail;
        this->tail->next = nod;
        this->tail = nod;
        this->nrElem_stack++;
    }
}

//returns the element from the front of the queue
//throws exception if the queue is empty
//Theta(1)
Nod* Stack::top() const
{
    if(this->nrElem_stack == 0)
        throw exception();

    return this->tail->info;
}

//scot si returnez ultimul el bagat in stack
//throws exception if the stack is empty
//Theta(1)
void Stack::pop()
{
    if(this->nrElem_stack == 0)
        throw exception();

    if (this->tail == this->head)
    {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
        this->nrElem_stack--;
    }

    else
    {
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->nrElem_stack--;
    }


}

//checks if the stack is empty
//Theta(1)
bool Stack::isEmpty() const
{
    if(this->nrElem_stack == 0)
        return true;

    return false;
}


// destructor
//Theta(n)
Stack::~Stack()
{
    while(!this->isEmpty())
        this->pop();
}


#include "Set.h"
#include "SetIterator.h"
//Theta(1)
Set::Set() {
    //TODO - Implementation
    this->nrElem = 0;
    this->wertebereich.min = 0;
    this->wertebereich.max = 0;
    this->cap.min = 0;
    this->cap.max = 0;
    this->set = new bool[1];

}

//Best=Theta(1) Worst=Theta(n) Avg=Theta(n)
bool Set::add(TElem elem)
{
    //TODO - Implementation
    //ob das bitarray leer ist
    if(this->nrElem == 0)
    {
        this->wertebereich.min = elem;
        this->wertebereich.max = elem;
        this->cap.max = 0;
        this->cap.min = 0;
        this->set[this->cap.min] = true;
        //this->set[0] = true;
        //this->set[cap.min] = true;
        this->nrElem++;
        //this->cap.max = 1;
        //this->set[cap.max] = true;
        return true;
    }

    //elem gehort der wertebereich
    else
        if(this->wertebereich.min <= elem && elem <= this->wertebereich.max)
        {   //das Elem ist in dem Set
            if(this->set[elem - this->wertebereich.min])
                return false;
            else
            {
                this->set[elem - this->wertebereich.min] = true;
                this->nrElem++;
                return true;
            }

        }
        // elem < wertebereich.min
        else
            if(elem < this->wertebereich.min)
            {
                this->wertebereich.min = elem;
                //wv Platz brauche ich fur dem neuen Array
                bool* set2 =  new bool[this->wertebereich.max - this->wertebereich.min + 1];
                int i;
                // die Differenz zwischen die alte und neue Kapazitat
                int differenz = (this->wertebereich.max - this->wertebereich.min) - cap.max;
                //wir inizialisieren alle Werten mit false
                for(i = 0; i<= this->wertebereich.max - this->wertebereich.min; i++)
                    set2[i] = false;
                //alle werte die im set sind, werden auch im set2 1 sein
                for(i = 0 ; i<= this->cap.max; i++)
                {
                    set2[differenz] = this->set[i];
                    differenz++;
                }
                this->cap.max = this->wertebereich.max - this->wertebereich.min;
                //fur das gegebene Element
                set2[0] = true;
                this->nrElem++;
                delete[] this->set;
                this->set = set2;
                //this->set[0] = true;
                return true;

            }

            //elem > wertebereich.max
            if(elem > this->wertebereich.max)
            {
                this->wertebereich.max = elem;
                bool *set2 =  new bool[this->wertebereich.max - this->wertebereich.min + 1];
                int i;
                //wie inizialisieren alle Werte mit 0
                for(i = 0; i<= this->wertebereich.max - this->wertebereich.min; i++)
                    set2[i] = false;
                //alle werte die im set sind, werden auch im set2 1 sein

                for(i = 0 ; i<= this->cap.max; i++)
                {
                    set2[i] = this->set[i];
                }
                this->cap.max = this->wertebereich.max - this->wertebereich.min;
                //fur das gegebene Element
                set2[this->cap.max] = true;
                nrElem++;
                delete[] this->set;
                this->set = set2;
                //this->set[this->cap.max] = true;
                return true;

            }

}

//Best=Theta(1) Worst=Theta(n) Avg=Theta(n)
bool Set::remove(TElem elem) {
    //TODO - Implementation
    /*
    if(this->nrElem == 0 || elem < this->wertebereich.min || elem > this->wertebereich.max)
        return false;
    else
        // elem ist an der Unteregranze
        if(elem == this->wertebereich.min)
        {
            if(!this->set[0])
            {
                return false;
            }

            else
            {
                int i;
                this->wertebereich.min = elem + 1;
                this->cap.max--;
                bool* set2 = new bool[this->cap.max + 1];
                //for(i = 0; i<= this->cap.max ; i++)
                //set2[i] = false;
                for(i = 0; i <= this->cap.max; i++)
                    set2[i] = this->set[i+1];
                this->nrElem--;
                delete[] this->set;
                this->set = set2;
                return true;
            }

        }
        else
            if(this->wertebereich.min < elem < this->wertebereich.max)
            {
                if(this->set[elem - this->wertebereich.min])
                {
                    this->set[elem - this->wertebereich.min] = false;
                    this->nrElem--;
                    return true;
                }
                else
                    return false;
            }
            else
                // elem ist an der Oberegranze
                    if(elem == this->wertebereich.max)
                    {
                        if(!this->set[this->cap.max])
                        {
                            return false;
                        }
                        else
                        {
                            int i;
                            this->wertebereich.max = elem - 1;
                            this->cap.max--;
                            bool *set2 = new bool[this->cap.max + 1];
                            //for(i = 0; i<= this->cap.max ; i++)
                                //set2[i] = false;
                            for(i = 1; i <= this->cap.max; i++)
                                set2[i] = this->set[i];
                            this->nrElem--;
                            delete[] this->set;
                            this->set = set2;
                            return true;

                        }

                    }
                    */
    if(this->nrElem == 0 || elem < this->wertebereich.min || elem > this->wertebereich.max)
        return false;


    bool verif = false;

    if(this->set[elem - this->wertebereich.min])
    {
        this->set[elem - this->wertebereich.min] = false;
        verif = true;
        this->nrElem--;
    }

    //elem = w.min
    if(elem == this->wertebereich.min)
    {
        int i;
        this->wertebereich.min = elem + 1;
        this->cap.max--;
        bool* set2 = new bool[this->cap.max + 1];
        //for(i = 0; i<= this->cap.max ; i++)
            //set2[i] = false;
        for(i = 0; i <= this->cap.max; i++)
            set2[i] = this->set[i+1];
        delete[] this->set;
        this->set = set2;
    }
    else
        //elem = w.max
        if(elem == this->wertebereich.max)
        {
            int i;
            this->wertebereich.max = elem - 1;
            this->cap.max--;
            bool* set2 = new bool[this->cap.max + 1];
            //for(i = 0; i<= this->cap.max ; i++)
            //set2[i] = false;
            for(i = 0; i <= this->cap.max; i++)
                set2[i] = this->set[i];
            delete[] this->set;
            this->set = set2;
        }

    if(verif)
        return true;
    else
        return false;

}

//Theta(1)
bool Set::search(TElem elem) const {
    //TODO - Implementation
    if(this->nrElem == 0 || elem < this->wertebereich.min || elem > this->wertebereich.max)
        return false;
    else //elem gehort dem Wertebereich
    {
        if(!this->set[elem - this->wertebereich.min])
            return false;
        else
            return true;
    }
}

//Theta(1)
int Set::size() const {
    //TODO - Implementation
    return this->nrElem;
}

//Theta(1)
bool Set::isEmpty() const {
    //TODO - Implementation
    if(this->nrElem == 0)
        return true;
    else
        return false;
}

//Theta(1)
Set::~Set() {
    //TODO - Implementation
    delete[] this->set;
}


SetIterator Set::iterator() const {
    return SetIterator(*this);
}

//O(n)
void Set::Bonus(int a, int b)
{
    //a soll kleiner als b sein
    if(a > b)
    {
        int c = a;
        a = b;
        b = c;
    }

    this->cap.max = b-a;
    //this->cap.min = 0
    this->wertebereich.min = a;
    this->wertebereich.max = b;
    //this->nrElem = 0
    this->nrElem = b-a+1;
    bool* set2 =  new bool[this->cap.max + 1];
    int i;
    for(i = 0; i <= this->cap.max; i++)
        set2[i] = true;

    delete[] this->set; //am Anfang habe ich in dem Speichern ein dynamischen Array von Dimension 1
    this->set = set2;


}

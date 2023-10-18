#include <iostream>
#include "Leaf.h"
#include "Stem.h"


Stem::Stem(): front(nullptr), back(nullptr), value(0), frequency(0), next(nullptr)
{
 
}

Stem::~Stem() {

Leaf* clfPtr = front;

while(clfPtr != nullptr){
    Leaf* tmp = clfPtr;
    clfPtr = clfPtr->next;
    delete tmp; 
}

}


bool Stem::insert(int value) {
   
    Leaf* clfPtr = front;
    Leaf* plfPtr = nullptr;

    while(clfPtr != nullptr && clfPtr-> value < value){
        plfPtr = clfPtr;
        clfPtr = clfPtr->next;
    }


    if(clfPtr != nullptr){

        if (clfPtr->value == value){
            clfPtr->count++;
            frequency++;
            return false;
        }
    }


    Leaf* nlfPtr = new Leaf();

    nlfPtr-> value = value;
    nlfPtr->count = 1;
    nlfPtr->next = clfPtr;


    if(plfPtr == nullptr){
        front = nlfPtr;
    } else {
        plfPtr->next = nlfPtr;
    }
    frequency++;
    return true;
}



bool Stem::remove(int target) {

    Leaf* clfPtr = front;
    Leaf* plfPtr = nullptr;

    while(clfPtr != nullptr && clfPtr->value < target){
        plfPtr = clfPtr;
        clfPtr = clfPtr->next;
    }

    if(clfPtr == nullptr){
        return false;
    }

    if(clfPtr-> value != target){
        return false;
    }

    if(clfPtr->count > 1){

        clfPtr->count -= 1;
        frequency-= 1;
        return false;

    }

    
    if(plfPtr == nullptr){
        front = clfPtr->next; 
    }


    else {

        plfPtr->next = clfPtr->next;
    }
    frequency-= 1;


    delete clfPtr;
    return true;
}

// Don't modify
std::ostream &operator << (std::ostream &out, const Stem &x) {
    out << x.value <<" | ";
    Leaf *CURLEAF_ptr = x.front;  

    while ( CURLEAF_ptr != nullptr )
    {
        out << *CURLEAF_ptr <<" ";
        CURLEAF_ptr = CURLEAF_ptr -> next;
    }
    out << std::endl;

    return out;
}

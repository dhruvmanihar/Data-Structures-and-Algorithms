#include <iostream>
#include "StemAndLeaf.h"

int StemAndLeaf::getLeafUnit() const {

    return leafUnit;

}

void StemAndLeaf::setLeafUnit(int leafUnit) {

    this->leafUnit = leafUnit;

}

int StemAndLeaf::getStemUnit() const {

    return stemUnit;

}

void StemAndLeaf::setStemUnit(int stemUnit) {

    this->stemUnit = stemUnit;

}

StemAndLeaf::StemAndLeaf() {

    head = nullptr;
    tail = nullptr;

}

StemAndLeaf::~StemAndLeaf() {

    Stem* stem_ptr = head;

    while (stem_ptr != nullptr){
        Stem* tmp = stem_ptr;
        stem_ptr = stem_ptr->next;
        delete tmp;
    }

}

void StemAndLeaf::addTerm(int term) {

    int stVal = term/stemUnit;
    int lfVal = term% stemUnit;
    Stem* currStem = head;
    Stem* prevStem = nullptr;

    while (currStem != nullptr && currStem->value < stVal){

        prevStem = currStem;
        currStem = currStem->next;

    }


    if(currStem == nullptr || currStem->value != stVal){

        Stem* newStem = new Stem();
        newStem->value = stVal;
        newStem->next = currStem;
        if(prevStem == nullptr){
            head = newStem;
        } else {
            prevStem->next = newStem;
        }
        currStem = newStem;
        }


   
    currStem->insert(lfVal);

}

bool StemAndLeaf::removeTerm(int term) {

    int stVal = term/stemUnit;
    int lfVal = term % stemUnit;

    Stem* currentStem = head;
    Stem* prevStem = nullptr; 


    while(currentStem != nullptr && currentStem-> value < stVal){
        prevStem = currentStem;
        currentStem = currentStem-> next;
    }

    if(currentStem == nullptr || currentStem-> value != stVal){
        return false; 
    }


    bool deleted = currentStem->remove(lfVal);


    if(currentStem-> getFront() == nullptr){
        
        if(prevStem == nullptr){
            head = currentStem->next;
        } else {
            prevStem-> next = currentStem->next;
        }
        if(currentStem-> next == nullptr){
            tail = prevStem;
        }
        delete currentStem; 
        }

    return deleted; 
}



// Don't modify
std::ostream &operator << (std::ostream &out, const StemAndLeaf &x) {
	// needs to go through the StemAndLeaf, one stem, then all leaves, then back to the next stem and it's leaves, and continue
    Stem * CURSTEM_ptr = x.head;
    while ( CURSTEM_ptr != nullptr )
    {
      out << *CURSTEM_ptr; 
      CURSTEM_ptr = CURSTEM_ptr -> next;
    }
    
	return out;
}


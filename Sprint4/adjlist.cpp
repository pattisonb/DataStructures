#include "adjlist.h"

AdjList::AdjList()
{
    flights = LinkedList<OriginCity>();
}

AdjList::AdjList(LinkedList<OriginCity> l) {
    flights = l;
}

void AdjList::add(OriginCity city){
    flights.insertAtEnd(city);
}

LinkedList<destinationCity>* AdjList::getDestinations(DSString cityName) {
    LinkedList<OriginCity>::iterator itr;
    itr = flights.begin();
    while(itr.pointer != nullptr) {
        if(itr.pointer->data.getName() == cityName) {
            return itr.pointer->data.destinations;
        }
        itr++;
    }
    return nullptr;
}

bool AdjList::contains(DSString name) {
    LinkedList<OriginCity>::iterator itr;
    itr = flights.begin();
    while(itr.pointer != nullptr) {
        if(itr.pointer->data.getName() == name) {
            return true;
        }
        itr++;
    }
    return false;
}

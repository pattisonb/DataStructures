#include "adjlist.h"

AdjList::AdjList()
{
    flights = LinkedList<OriginCity>();
}

AdjList::AdjList(LinkedList<OriginCity> l) {
    flights = l;
}

void AdjList::add(OriginCity city){
    ++size;
    flights.insertAtEnd(city);
}

LinkedList<destinationCity*>* AdjList::getDestinations(DSString cityName) {
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

int AdjList::getSize() {
    return size;
}

OriginCity AdjList::getOriginCity(DSString cityName) {
    LinkedList<OriginCity>::iterator itr;
    itr = flights.begin();
    while(itr.pointer != nullptr) {
        if(itr.pointer->data.getName() == cityName) {
            return itr.pointer->data;
        }
        itr++;
    }
}

void AdjList::getFlights(Flight& f) {
    LinkedList<destinationCity*>::iterator d;
    DSStack<destinationCity*> destinations;
    DSVector<DSString> cities;
    DSString origCity = f.getOrigin();
    DSString destCity = f.getDest();
    cities.push_back(origCity);
    d = getDestinations(origCity)->begin();
    while (cities.getSize() > 0) {
        if (destinations.peek()->getName() == destCity) {
            f.addPath(destinations);
            destinations.pop();
            cities.pop_back();
        }
        else {
            if (d.pointer->data == nullptr) {

            }
            if (cities.countDuplicate(d.pointer->data->getName()) > 0) {
                d++;
            }
            else {
               cities.push_back(d.pointer->data->getName());
               destinations.push(d.pointer->data);
               d++;
            }
        }
    }
}

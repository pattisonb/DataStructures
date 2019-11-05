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

int AdjList::getSize() {
    return size;
}

void AdjList::getFlights(Flight& f) {
    LinkedList<destinationCity>::iterator dest;
    DSStack<destinationCity> dests;
    DSVector<DSString> cities;
    DSString origCity = f.getOrigin();
    DSString destCity = f.getDest();
    cities.push_back(origCity);
    //trying with one flight
    dest = getDestinations(origCity)->begin();
    dests.push(dest.pointer->data);
    cities.push_back(dest.pointer->data.getName());
    dest = getDestinations(dest.pointer->data.getName())->begin();
    dest++;
    while (!(dest.pointer->data.getName() == destCity)) {
        if (cities.countDuplicate(dest.pointer->data.getName()) > 0) {
            dest++;
        }
        dests.push(dest.pointer->data);
        cities.push_back(dest.pointer->data.getName());
        dest++;
    }
    DSVector<destinationCity> visitedCities;
    while (!dests.isEmpty()) {
        visitedCities.push_back(dests.pop());
    }
    Path path(visitedCities);
    f.addPath(path);
}

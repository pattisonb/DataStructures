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

int AdjList::getOriginCityIndex(DSString cityName) {
    LinkedList<OriginCity>::iterator itr;
    itr = flights.begin();
    while(itr.pointer != nullptr) {
        if(itr.pointer->data.getName() == cityName) {
            return itr.pointer->data.index;
        }
        itr++;
    }
}

void AdjList::reset() {
    LinkedList<OriginCity>::iterator itr;
    itr = flights.begin();
    LinkedList<destinationCity*>::iterator d;
    while (itr.pointer != nullptr) {
        d = getDestinations(itr.pointer->data.getName())->begin();
        while (d.pointer != nullptr) {
            d.pointer->data->isVisited = false;
            d.pointer->data->timesVisited = 0;
            d++;
        }
        itr++;
    }
}

void AdjList::resetIterator(DSString o) {
    LinkedList<destinationCity*>::iterator d;
    d = getDestinations(o)->begin();
    while (d.pointer != nullptr) {
        d.pointer->data->isVisited = false;
        d.pointer->data->timesVisited = 0;
        d++;
    }
}

void AdjList::getFirstFlight(Flight* f) {
    LinkedList<destinationCity*>::iterator d;
    DSStack<destinationCity*> destinations;
    DSVector<DSString> cities;
    DSString origCity = f->getOrigin();
    DSString destCity = f->getDest();
    cities.push_back(origCity);
    //trying with one flight
    d = getDestinations(origCity)->begin();
    destinations.push(d.pointer->data);
    cities.push_back(d.pointer->data->getName());
    d = getDestinations(d.pointer->data->getName())->begin();
    while (!(d.pointer->data->getName() == destCity)) {
        d++;
        if (cities.countDuplicate(d.pointer->data->getName()) > 1) {
            destinations.pop();
            cities.pop_back();
        }
    }
    destinations.push(d.pointer->data);
    cities.push_back(d.pointer->data->getName());
    f->addPath(destinations);
    while(!destinations.isEmpty()) {
        destinations.pop();
    }
    while(!cities.isEmpty()) {
        cities.pop_back();
    }
}

void AdjList::getFlights(Flight*& f) {
    reset();
    LinkedList<destinationCity*>::iterator d;
    DSStack<destinationCity*> destinations;
    DSVector<DSString> cities;
    DSString origCity = f->getOrigin();
    DSString destCity = f->getDest();
    f->setNumPaths(0);
    d = getDestinations(origCity)->begin();
    cities.push_back(origCity);
    bool go = true;
    while (go == true) {
        if ((d.pointer) == nullptr) {
            go = false;
            break;
        }
        if (d.pointer != nullptr) {
            while (d.pointer->data->isVisited == true && go == true) {
                if (d.pointer->next != nullptr) {
                    d++;
                }
                else {
                    d = getDestinations(d.pointer->data->getName())->begin();
                    cities.pop_back();
                }
                if (cities.isEmpty()) {
                    go = false;
                    break;
                }
            }
        }
        destinations.push(d.pointer->data);
        cities.push_back(d.pointer->data->getName());
        d.pointer->data->isVisited = true;
        if (getDestinations(origCity)->getSize() < 3 && d.pointer->data->timesVisited < 10) {
            d.pointer->data->isVisited = false;
            resetIterator(cities.peek());
        }
        if (d.pointer->data->getName() == destCity) {
            //cout << f->paths.countDuplicate(Path(destinations)) << endl;
            if (f->paths.countDuplicate(Path(destinations)) == 0) {
                f->addPath(destinations);
            }
            if (d.pointer->data->timesVisited < 5) {
                d.pointer->data->isVisited = false;
            }
            d.pointer->data->timesVisited += 1;
            for (int i = 0; i < cities.getSize(); i++) {
                cities.pop_back();
            }
            while (!destinations.isEmpty()) {
                destinations.pop();
            }
            d = getDestinations(origCity)->begin();;
        }
        else {
            if (d.pointer == nullptr) {
                d = getDestinations(destinations.pop()->getName())->begin();
                resetIterator(cities.peek());
                cities.pop_back();
                while (d.pointer->data->isVisited == true) {
                    d++;
                }
            }
            if (cities.countDuplicate(d.pointer->data->getName()) > 1) {
                cities.pop_back();
                destinations.pop();
                d.pointer->data->isVisited = false;
                d++;
            }
            else {
                d = getDestinations(destinations.peek()->getName())->begin();
            }
        }
    }
}

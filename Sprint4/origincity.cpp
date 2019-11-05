#include "origincity.h"

OriginCity::OriginCity()
{
   name = "";
   destinations = new LinkedList<destinationCity>();
}

OriginCity::OriginCity(DSString n, LinkedList<destinationCity>* d) {
    name = n;
    destinations = d;
}

OriginCity::~OriginCity() {
    destinations->clear();
}

DSString OriginCity::getName() {
    return name;
}

void OriginCity::addDestination(destinationCity newDest) {
    destinations->insertAtEnd(newDest);
}

void OriginCity::setName(DSString n) {
    name = n;
}

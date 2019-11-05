#ifndef ORIGINCITY_H
#define ORIGINCITY_H
#include "dsstring.h"
#include "destinationcity.h"
#include "linkedlist.h"


class OriginCity
{
    friend class AdjList;
private:
    DSString name;
    LinkedList<destinationCity>* destinations;
public:
    OriginCity();
    OriginCity(DSString, LinkedList<destinationCity>*);
    DSString getName();
    void addDestination(destinationCity);
    void setName(DSString);
};

#endif // ORIGINCITY_H

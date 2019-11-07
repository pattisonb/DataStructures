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
    LinkedList<destinationCity*>* destinations;
public:
    int index = 0;
    OriginCity();
    OriginCity(const OriginCity&);
    OriginCity(DSString, LinkedList<destinationCity*>*);
    ~OriginCity();
    DSString getName();
    void addDestination(destinationCity*);
    void setName(DSString);
    int getSize();
    bool isExhausted();
};

#endif // ORIGINCITY_H

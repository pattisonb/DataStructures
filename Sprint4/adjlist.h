#ifndef ADJLIST_H
#define ADJLIST_H
#include "linkedlist.h"
#include "origincity.h"
#include "destinationcity.h"
#include "dsstring.h"
class AdjList
{
private:
   LinkedList<OriginCity> flights;
   int size = 0;
public:
   AdjList();
   AdjList(LinkedList<OriginCity> flights);
   void add(OriginCity);
   LinkedList<destinationCity>* getDestinations(DSString);
   bool contains(DSString);
   int getSize();
};
#endif // ADJLIST_H

#ifndef ADJLIST_H
#define ADJLIST_H
#include "linkedlist.h"
#include "origincity.h"
#include "destinationcity.h"
#include "dsstring.h"
#include "dsvector.h"
#include "flight.h"
#include "path.h"
#include "dsstack.h"

class AdjList
{
private:
   LinkedList<OriginCity> flights;
   int size = 0;
public:
   AdjList();
   AdjList(LinkedList<OriginCity> flights);
   void add(OriginCity);
   LinkedList<destinationCity*>* getDestinations(DSString);
   bool contains(DSString);
   int getSize();
   void getFirstFlight(Flight&);
   void getFlights(Flight&);
   int getOriginCityIndex(DSString);
   bool isExhausted(DSString);

};
#endif // ADJLIST_H

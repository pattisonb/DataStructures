#ifndef FLIGHTPLANNER_H
#define FLIGHTPLANNER_H
#include <iostream>
#include <fstream>
#include "dsstring.h"
#include "destinationcity.h"
#include "origincity.h"
#include "adjlist.h"
#include "flight.h"
#include "dsstack.h"

class FlightPlanner
{
private:
    DSString flightDataInput;
    DSString requestedFlight;
    DSString print;
    int totalFlights = 0;
public:
    FlightPlanner(DSString, DSString, DSString p);
    void findFlights(Flight, AdjList);
    void printFlight(Flight&, ofstream&);
};

#endif // FLIGHTPLANNER_H

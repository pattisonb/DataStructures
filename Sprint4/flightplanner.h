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
public:
    FlightPlanner(DSString, DSString);
    void findFlights(Flight, AdjList);
};

#endif // FLIGHTPLANNER_H

#ifndef FLIGHTPLANNER_H
#define FLIGHTPLANNER_H
#include <iostream>
#include <fstream>
#include "dsstring.h"
#include "destinationcity.h"
#include "origincity.h"
#include "adjlist.h"

class FlightPlanner
{
private:
    DSString flightDataInput;
public:
    FlightPlanner(DSString);
};

#endif // FLIGHTPLANNER_H

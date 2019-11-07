#ifndef FLIGHT_H
#define FLIGHT_H

#include "dsstring.h"
#include "dsvector.h"
#include "path.h"
#include "dsstack.h"
#include "destinationcity.h"

class Flight
{
    friend class FlightPlanner;
    friend class AdjList;
private:
    DSString originCity;
    DSString destCity;
    DSVector<Path> paths;
    DSString costOrTime = "";
    int numPaths;
public:
    Flight();
    Flight(DSString, DSString);
    void setOrigin(DSString);
    void setDest(DSString);
    void setCostOrTime(DSString);
    void setNumPaths(int);
    DSString getOrigin();
    DSString getDest();
    void addPath(Path&);
    void printFlight();
    void clearPaths();
    void addPath(DSStack<destinationCity*>);
    void sortTime();
    void sortCost();
    void swap (Path* xp, Path* yp);
    void checkPaths();
    //findCity
};

#endif // FLIGHT_H

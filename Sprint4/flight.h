#ifndef FLIGHT_H
#define FLIGHT_H
#include "dsstring.h"
#include "dsvector.h"
#include "path.h"
#include "dsstack.h"
#include "destinationcity.h"

class Flight
{
private:
    DSString originCity;
    DSString destCity;
    DSVector<Path> paths;
public:
    Flight();
    Flight(DSString, DSString);
    void setOrigin(DSString);
    void setDest(DSString);
    DSString getOrigin();
    DSString getDest();
    void addPath(Path);
    void printFlight();
    void clearPaths();
    void addPath(DSStack<destinationCity*>);
};

#endif // FLIGHT_H

#ifndef FLIGHT_H
#define FLIGHT_H
#include "dsstring.h"
#include "dsvector.h"
#include "path.h"

class Flight
{
private:
    DSString originCity;
    DSString destinationCity;
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
};

#endif // FLIGHT_H

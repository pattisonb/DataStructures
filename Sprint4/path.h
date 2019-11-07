#ifndef PATH_H
#define PATH_H
#include "destinationcity.h"
#include "dsvector.h"
#include "dsstack.h"

class Path
{
    friend class Flight;
    friend class FlightPlanner;
private:
    DSVector<destinationCity> cities;
    double cost = 0;
    double time = 0;
public:
    Path();
    Path(const Path&);
    Path(DSStack<destinationCity*>);
    Path(DSVector<destinationCity>);
    bool operator== (const Path&);
    void printPath();
};

#endif // PATH_H

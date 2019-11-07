#ifndef PATH_H
#define PATH_H
#include "destinationcity.h"
#include "dsvector.h"

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
    Path(DSVector<destinationCity>);
};

#endif // PATH_H

#ifndef PATH_H
#define PATH_H
#include "destinationcity.h"
#include "dsvector.h"

class Path
{
private:
    DSVector<destinationCity> cities;
    double cost = 0;
    double time = 0;
public:
    Path();
    Path(DSVector<destinationCity>);
};

#endif // PATH_H
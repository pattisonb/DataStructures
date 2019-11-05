#ifndef DESTINATIONCITY_H
#define DESTINATIONCITY_H
#include "dsstring.h"

class destinationCity
{
private:
    DSString name;
    DSString airline;
    double cost;
    double time;
public:
    destinationCity();
    destinationCity(DSString, DSString, double, double);
    DSString getName();
    DSString getAirline();
    double getCost();
    double getTime();
    void setName(DSString);
    void setPrice(double);
    void setTime(double);
    void setAirline(DSString);
};

#endif // DESTINATIONCITY_H

#include "destinationcity.h"
destinationCity::destinationCity() {
    name = "";
    airline = "";
    cost = 0;
    time = 0;
}

destinationCity::destinationCity(const destinationCity& d) {
    name = d.name;
    airline = d.airline;
    cost = d.cost;
    time = d.time;
}

destinationCity::destinationCity(DSString n, DSString a, double c, double t) {
    name = n;
    airline = a;
    cost = c;
    time = t;
}

double destinationCity::getCost() {
    return cost;
}

DSString destinationCity::getName() {
    return name;
}

DSString destinationCity::getAirline() {
    return airline;
}

double destinationCity::getTime() {
    return time;
}

void destinationCity::setName(DSString n) {
    name = n;
}

void destinationCity::setPrice(double p) {
    cost = p;
}

void destinationCity::setTime(double t) {
    time = t;
}

void destinationCity::setAirline(DSString n) {
    airline = n;
}

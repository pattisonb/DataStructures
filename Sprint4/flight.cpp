#include "flight.h"
Flight::Flight(DSString o, DSString d) {
    originCity = o;
    destinationCity = d;
}
void Flight::setOrigin(DSString o) {
    originCity = o;
}
void Flight::setDest(DSString d) {
    destinationCity = d;
}
void Flight::addPath(Path p) {
    paths.push_back(p);
}

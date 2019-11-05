#include "flight.h"
Flight::Flight() {

}
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
DSString Flight::getOrigin() {
    return originCity;
}
DSString Flight::getDest() {
    return destinationCity;
}
void Flight::printFlight() {
    cout << "Flight 1: " << originCity << ", " << destinationCity << endl;
    for (int i = 0; i < paths.getSize(); i++) {

    }
}

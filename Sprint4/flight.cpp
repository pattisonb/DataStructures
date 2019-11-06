#include "flight.h"
Flight::Flight() {

}
Flight::Flight(DSString o, DSString d) {
    originCity = o;
    destCity = d;
}
void Flight::setOrigin(DSString o) {
    originCity = o;
}
void Flight::setDest(DSString d) {
    destCity = d;
}
void Flight::addPath(Path p) {
    paths.push_back(p);
}
DSString Flight::getOrigin() {
    return originCity;
}
DSString Flight::getDest() {
    return destCity;
}
void Flight::printFlight() {

    cout << "Flight 1: " << originCity << ", " << destCity << endl;
    cout << "Path 1: " << originCity;
    for (int i = 0; i < paths.getSize(); i++) {
        for (int j = paths[i].cities.getSize() - 1; j >= 0; j--) {
            cout << " -> " << paths[i].cities[j].getName() << " (" << paths[i].cities[j].getAirline() << ")";
        }
        cout << "\nTime: " << paths[i].time << " Cost: " << paths[i].cost << endl;
    }
}

void Flight::clearPaths(){
    while (!paths.isEmpty()) {
        paths.pop_back();
    }
}

void Flight::addPath(DSStack<destinationCity*> d) {
    DSVector<destinationCity> v;
    while(!(d.isEmpty())) {
        v.push_back(*d.pop());
    }
    paths.push_back(Path(v));
}

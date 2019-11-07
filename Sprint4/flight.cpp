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

void Flight::setCostOrTime(DSString t) {
    costOrTime = t;
}

void Flight::setNumPaths(int t) {
    numPaths = t;
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
    ++numPaths;
    DSVector<destinationCity> v;
    while(!(d.isEmpty())) {
        v.push_back(*d.pop());
    }
    paths.push_back(Path(v));
}

void Flight::sortTime() {
   int i, j, min_idx;
   int n = paths.getSize();
   for (i = 0; i < n - 1; i++) {
       min_idx = i;
       for ( j = i+1; j < n; j++) {
           if (paths[j].time < paths[min_idx].time) {
               min_idx = j;
               swap(&paths[min_idx], &paths[i]);
           }
       }
   }
}

void Flight::sortCost() {
    int i, j, min_idx;
    int n = paths.getSize();
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for ( j = i+1; j < n; j++) {
            if (paths[j].cost < paths[min_idx].cost) {
                min_idx = j;
                swap(&paths[min_idx], &paths[i]);
            }
        }
    }
}

void Flight::swap (Path* xp, Path* yp) {
    Path temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Flight::checkPaths() {
    for (int i = 0; i < paths.getSize(); i++) {
        cout << paths[i].cities.peek().getName() << endl;
        cout << numPaths << endl;
    }
}

#include "path.h"

Path::Path(){
    cities = DSVector<destinationCity>();
}

Path::Path(const Path& p) {
    cost = p.cost;
    time = p.time;
    cities = p.cities;
}

Path::Path(DSVector<destinationCity> c) {
    cities = c;
    for (int i = 0; i < cities.getSize(); i++) {
        time += cities[i].getTime();
        cost += cities[i].getCost();
    }
    for (int i = 0; i < cities.getSize() - 1; i++) {
        if ((cities[i].getAirline() == cities[i+1].getAirline())) {
            time += 0;
        }
        else {
           time += 22;
        }
    }
    time += ((cities.getSize() - 1) * 43);
    cost += ((cities.getSize() - 1) * 19);
}


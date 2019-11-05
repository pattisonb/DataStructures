#include "path.h"

Path::Path(){
    cities = DSVector<destinationCity>();
}

Path::Path(DSVector<destinationCity> c) {
    cities = c;
    time = ((cities.getSize() - 2) * 43);
    cost = ((cities.getSize() - 2) * 19);
    for (int i = 0; i < cities.getSize(); i++) {
        time += cities[i].getTime();
        cost += cities[i].getCost();
    }
    for (int i = 1; i < cities.getSize() - 1; i++) {
        if (!(cities[i].getAirline() == cities[i+1].getAirline())) {
            time += 22;
        }
    }
}

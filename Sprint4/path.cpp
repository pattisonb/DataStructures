#include "path.h"

Path::Path(){
    cities = DSVector<destinationCity>();
}

Path::Path(const Path& p) {
    cost = p.cost;
    time = p.time;
    cities = p.cities;
}

Path::Path(DSStack<destinationCity*> d) {
    DSVector<destinationCity> v;
    while(!(d.isEmpty())) {
        v.push_back(*d.pop());
    }
    cities = v;
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

void Path::printPath() {
    for (int i = 0; i < cities.getSize(); i++) {
        cout << cities[i].getName() << endl;
    }
    cout << endl;
}

bool Path::operator==(const Path & p) {
    if (this->cost != p.cost) {
        return false;
    }
    if (this->time != p.time) {
        return false;
    }
    if (!(this->cities == p.cities)) {
        return false;
    }
    return true;
}


#include "flightplanner.h"

FlightPlanner::FlightPlanner(DSString a, DSString c, DSString p)
{
    flightDataInput = a;
    requestedFlight = c;
    print = p;
    ifstream flightData(flightDataInput.c_str());
    ifstream reqFlight(requestedFlight.c_str());
    ofstream output(print.c_str());
    //cout << "check" << endl;
    char b[100];
    flightData.getline(b, 100);
    int numFlights;
    numFlights = stoi(b);
    AdjList flightMap;
    for (int i = 0; i < numFlights; i++) {
        destinationCity* tempDest = new destinationCity;
        OriginCity* tempOrig = new OriginCity;
        destinationCity* tempDest2 = new destinationCity; //add to heap
        OriginCity* tempOrig2 = new OriginCity;
        flightData.getline(b, 100, '|');
        DSString originCity1(b);
        tempOrig->setName(b);
        tempDest->setName(b);
        flightData.getline(b, 100, '|');
        DSString originCity2 = b;
        tempOrig2->setName(b);
        tempDest2->setName(b);
        flightData.getline(b, 100, '|');
        double cost = stod(b);
        tempDest->setPrice(cost);
        tempDest2->setPrice(cost);
        flightData.getline(b, 100, '|');
        double time = stod(b);
        tempDest->setTime(time);
        tempDest2->setTime(time);
        flightData.getline(b, 100);
        tempDest->setAirline(b);
        tempDest2->setAirline(b);
        if (flightMap.contains(originCity1)) {
            flightMap.getDestinations(originCity1)->insertAtEnd(tempDest2);
                                    //cout << "check" << endl;
        }
        else{
            flightMap.add(*tempOrig);
            flightMap.getDestinations(originCity1)->insertAtEnd(tempDest2);
                                    //cout << "check" << endl;
        }
        if (flightMap.contains(originCity2)) {
            flightMap.getDestinations(originCity2)->insertAtEnd(tempDest);
                                    //cout << "check" << endl;
        }
        else{
            flightMap.add(*tempOrig2);
            flightMap.getDestinations(originCity2)->insertAtEnd(tempDest);
                                    //cout << "check" << endl;
        }
    }
    reqFlight.getline(b, 100);
    numFlights = atoi(b);
    Flight newFlight;
    for (int i = 0; i < numFlights; i++) {
        totalFlights++;
        reqFlight.getline(b, 100, '|');
        DSString oCity(b);
        newFlight.setOrigin(b);
        reqFlight.getline(b, 100, '|');
        newFlight.setDest(b);
        DSString dCity(b);
        reqFlight.getline(b, 100);
        newFlight.setCostOrTime(b);
//        newFlight.setDest(dCity);
//        newFlight.setOrigin(oCity);
        newFlight.clearPaths();
        flightMap.getFlights(newFlight);
        if (newFlight.costOrTime == "T" || newFlight.costOrTime == "t") {
            newFlight.sortTime();
        }
        else {
            newFlight.sortTime();
        }
        //newFlight.checkPaths();
        printFlight(newFlight, output);
    }
}

void FlightPlanner::printFlight(Flight &f, ofstream& print) {
    print << "Flight " << totalFlights << ": " << f.originCity << ", " << f.destCity;
    if (f.costOrTime == "T" || f.costOrTime == "t") {
        print << " (Time)" << endl;
    }
    else {
        print << " (Cost)" << endl;
    }
    print << endl;
    if (f.numPaths < 3) {
        for (int x = 0; x < f.numPaths; x++) {
            print << "Path " << x + 1 << ": " << f.originCity;
                for (int j = f.paths[x].cities.getSize() - 1; j >= 0; j--) {
                    print << " -> " << f.paths[x].cities[j].getName() << " (" << f.paths[x].cities[j].getAirline() << ")";
                }
                print << "\nTime: " << f.paths[x].time << " Cost: " << f.paths[x].cost << endl;
        }
        print << endl;
    }
    else {
        for (int x = 0; x < 3; x++) {
            print << "Path " << x + 1 << ": " << f.originCity;
                for (int j = f.paths[x].cities.getSize() - 1; j >= 0; j--) {
                    print << " -> " << f.paths[x].cities[j].getName() << " (" << f.paths[x].cities[j].getAirline() << ")";
                }
                print << "\nTime: " << f.paths[x].time << " Cost: " << f.paths[x].cost << endl;
        }
        print << endl;
    }
}

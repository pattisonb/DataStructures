#include "flightplanner.h"

FlightPlanner::FlightPlanner(DSString a)
{
    flightDataInput = a;
    ifstream flightData(flightDataInput.c_str());
    cout << "check" << endl;
    char b[100];
    flightData.getline(b, 100);
    int numFlights;
    numFlights = stoi(b);
    AdjList flightMap;
    for (int i = 0; i < numFlights; i++) {
        destinationCity tempDest;
        OriginCity tempOrig;
        destinationCity tempDest2;
        OriginCity tempOrig2;
        flightData.getline(b, 100, '|');
        DSString originCity1 = b;
        if (!flightMap.contains(b)) {
            tempOrig.setName(b);
        }
        tempDest.setName(b);
        DSString originCity2 = b;
        flightData.getline(b, 100, '|');
        if (!flightMap.contains(b)) {
            tempOrig2.setName(b);
        }
        tempDest2.setName(b);
        flightData.getline(b, 100, '|');
        double cost = stod(b);
        tempDest.setPrice(cost);
        tempDest2.setPrice(cost);
        flightData.getline(b, 100, '|');
        double time = stod(b);
        tempDest.setTime(time);
        tempDest2.setTime(time);
        flightData.getline(b, 100);
        tempDest.setAirline(b);
        tempDest2.setAirline(b);
        if (flightMap.contains(originCity1)) {
            flightMap.getDestinations(originCity1)->insertAtEnd(tempDest);
        }
        else{
            flightMap.add(tempOrig);
            flightMap.getDestinations(originCity1)->insertAtEnd(tempDest);
        }
        if (flightMap.contains(originCity2)) {
            flightMap.getDestinations(originCity2)->insertAtEnd(tempDest2);
        }
        else{
            flightMap.add(tempOrig2);
            flightMap.getDestinations(originCity2)->insertAtEnd(tempDest2);
        }
    }
}

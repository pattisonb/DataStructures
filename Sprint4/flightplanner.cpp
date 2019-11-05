#include "flightplanner.h"

FlightPlanner::FlightPlanner(DSString a, DSString c)
{
    flightDataInput = a;
    requestedFlight = c;
    ifstream flightData(flightDataInput.c_str());
    ifstream reqFlight(requestedFlight.c_str());
    //cout << "check" << endl;
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
        DSString originCity1(b);
        tempOrig.setName(b);
        tempDest.setName(b);
        flightData.getline(b, 100, '|');
        DSString originCity2 = b;
        tempOrig2.setName(b);
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
                                    //cout << "check" << endl;
        }
        else{
            flightMap.add(tempOrig);
            flightMap.getDestinations(originCity1)->insertAtEnd(tempDest);
                                    //cout << "check" << endl;
        }
        if (flightMap.contains(originCity2)) {
            flightMap.getDestinations(originCity2)->insertAtEnd(tempDest2);
                                    //cout << "check" << endl;
        }
        else{
            flightMap.add(tempOrig2);
            flightMap.getDestinations(originCity2)->insertAtEnd(tempDest2);
                                    //cout << "check" << endl;
        }
    }
    reqFlight.getline(b, 100);
    numFlights = atoi(b);
    for (int i = 0; i < numFlights; i++) {
        reqFlight.getline(b, 100, '|');
        DSString oCity(b);
        reqFlight.getline(b, 100, '|');
        DSString dCity(b);
        Flight flight(oCity, dCity);
    }
}

void FlightPlanner::findFlights(Flight f, AdjList list) {
    LinkedList<destinationCity>::iterator itr;


}

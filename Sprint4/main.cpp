#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "flightplanner.h"
#include "dsstring.h"

#define TEST true

using namespace std;

int runCatchTests(int argc, char* const argv[]) {
    return Catch::Session().run();
}

int main(int argc, char* const argv[])
{
    if (argc == 1) {
            return runCatchTests(argc, argv);
    }
    DSString flightData = argv[1];
    DSString requestedFlight = argv[2];
    FlightPlanner fightPlanner(flightData, requestedFlight);
}

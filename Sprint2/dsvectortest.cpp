#include "catch.hpp"
#include "dsvector.h"
#include "dsstring.h"
#include "tweet.h"

TEST_CASE("DSVector class", "[DSVector]") {
    Tweet tweet1(1,1, DSString(""));

    DSVector<int> test;
    DSVector<int> vTest (3);
    vTest[0] = 1;
    vTest[1] = 2;
    vTest[2] = 3;

    DSVector<int> vTest1;
    vTest1 = vTest;

    REQUIRE(vTest[0] == 1);
    REQUIRE(vTest1[0] == 1);
    REQUIRE(vTest1[1] == 2);

    REQUIRE(vTest1[2] == 3);

    vTest.push_back(6);
    vTest.push_back(6);
    vTest.push_back(6);
    vTest.push_back(6);

    REQUIRE(vTest[3] == 6);
    REQUIRE(vTest[4] == 6);
    REQUIRE(vTest[5] == 6);
    REQUIRE(vTest[6] == 6);

    vTest1.pop_back();
    vTest1.pop_back();
    vTest1.pop_back();

    REQUIRE(vTest1.isEmpty() == true);
}

TEST_CASE("DSString class", "[DSString]") {
    DSVector<DSString> vTest (3);
    vTest[0] = "Brian";
    vTest[1] = "Michael";
    vTest[2] = "Pattison";

    DSVector<DSString> vTest1;
    vTest1 = vTest;

    REQUIRE(vTest[0] == "Brian");
    REQUIRE(vTest1[0] == "Brian");
    REQUIRE(vTest1[1] == "Michael");
    REQUIRE(vTest1[2] == "Pattison");

    vTest.push_back("SMU");
    vTest.push_back("SMU");
    vTest.push_back("SMU");
    vTest.push_back("SMU");

    REQUIRE(vTest[3] == "SMU");
    REQUIRE(vTest[4] == "SMU");
    REQUIRE(vTest[5] == "SMU");
    REQUIRE(vTest[6] == "SMU");

    vTest1.pop_back();
    vTest1.pop_back();
    vTest1.pop_back();

    REQUIRE(vTest1.isEmpty() == true);
}

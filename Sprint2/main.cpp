#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#define TEST true

#include "dsvector.h"
#include "dsstring.h"
#include <iostream>
#include <fstream>
#include "tweet.h"

using namespace std;

int stringToInt(string);

int runCatchTests(int argc, char* const argv[]) {
    return Catch::Session().run();
}

int main(int argc, char* const argv[])
{
    if (argc == 1) {
        if (TEST) {
            return runCatchTests(argc, argv);
        }
    }



    ifstream trainData("dev-train-data.csv");
    ifstream trainPosOrNeg("dev-train-target.csv");

    string buffer;
    string buffer1;
    getline(trainData, buffer); //gets the formatting row
    getline(trainPosOrNeg, buffer); //gets the formatting row
    int idNum;
    int rating;
    DSVector <tweet> tweets;
    for (int i = 0; i < 100; i++) {
        getline(trainData, buffer, ','); //gets row number
        getline(trainData, buffer, ','); //gets idNumber
        idNum = stringToInt(buffer);
        getline(trainData, buffer, ','); //gets username
        getline(trainData, buffer);
        DSString text(buffer);
        getline(trainPosOrNeg, buffer, ','); //gets row number
        getline(trainPosOrNeg, buffer, ','); //gets rating
        rating = stringToInt(buffer);
        getline(trainPosOrNeg, buffer);
        tweet tweet1(idNum, rating, text);
        tweets.push_back(tweet1);
    }
    for (int i = 0; i < tweets.getSize(); i ++) {
        if (tweets[i].getRating() == 4) {
            tweets[i].printWords();
        }
    }
}

int stringToInt(string s) {
    int x = atoi(s.c_str());
    return x;
}

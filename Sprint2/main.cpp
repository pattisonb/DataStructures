#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#define TEST true

#include "dsvector.h"
#include "dsstring.h"
#include <iostream>
#include <fstream>
#include "tweet.h"
#include "classifier.h"

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


    ifstream trainData(argv[1]);
    ifstream trainPosOrNeg(argv[2]);
//    ifstream testData(argv[3]);
//    ifstream testPosOrNeg(argv[4]);
    ofstream output(argv[3]);

    string buffer;
    getline(trainData, buffer); //gets the formatting row
    getline(trainPosOrNeg, buffer); //gets the formatting row
    int idNum;
    int rating;
    trainData.clear();
    trainData.seekg(0, ios::beg);
    trainPosOrNeg.clear();
    trainPosOrNeg.seekg(0, ios::beg);
    DSVector <Tweet> tweets;
    for (int i = 0; i < 10000; i++) {
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
        Tweet tweet1(idNum, rating, text);
        tweets.push_back(tweet1);
    }
//    for (int i = 0; i < tweets.getSize(); i ++) {
//        if (tweets[i].getRating() == 4) {
//            tweets[i].printWords();
//        }
//    }
    Classifier classify(tweets);
}

int stringToInt(string s) {
    int x = atoi(s.c_str());
    return x;
}

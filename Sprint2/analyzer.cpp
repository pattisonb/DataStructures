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
    ifstream testData(argv[3]);
    ifstream testPosOrNeg(argv[4]);
    ofstream output(argv[5]);

    string buffer;
    //trainign data
    getline(trainData, buffer); //gets the formatting row
    getline(trainPosOrNeg, buffer); //gets the formatting row
    getline(testData, buffer); //gets the formatting row
    getline(testPosOrNeg, buffer); //gets the formatting row
    int idNum;
    int rating;
    trainData.clear();
    trainData.seekg(0, ios::beg);
    trainPosOrNeg.clear();
    trainPosOrNeg.seekg(0, ios::beg);
    DSVector <Tweet> classifyingTweets;
    for (int i = 0; i < 5000; i++) {
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
        classifyingTweets.push_back(tweet1);
    }

    Classifier classify(classifyingTweets); //creating the classifier

    DSVector <Tweet> testTweets;
    /*for (int i = 0; i < 100000; i++)*/  while (!testData.eof()){
        getline(testData, buffer, ','); //gets row number
        getline(testData, buffer, ','); //gets idNumber
        idNum = stringToInt(buffer);
        getline(testData, buffer, ','); //gets username
        getline(testData, buffer);
        DSString text(buffer);
        getline(testPosOrNeg, buffer, ','); //gets row number
        getline(testPosOrNeg, buffer, ','); //gets rating
        rating = stringToInt(buffer);
        getline(testPosOrNeg, buffer);
        Tweet tweet1(idNum, rating, text);
        testTweets.push_back(tweet1);
    }
    int returnedRating = 0;
    double total = 0;
    double numCorrect = 0;
    for (int i = 0; i < testTweets.getSize(); i++) {
        total ++;
        returnedRating = classify.Classify(testTweets[i]);
        if (returnedRating == testTweets[i].getRating()) {
           numCorrect++;
        }
    }
    double accuracy = numCorrect/total;
    output << setprecision(3);
    output << accuracy << endl; //outputting accuracy at the start of the file
    for (int i = 0; i < testTweets.getSize(); i++) {
        returnedRating = classify.Classify(testTweets[i]);
        if (returnedRating == testTweets[i].getRating()) {
            output << testTweets[i].getID() << ",";
            output << "c" << endl;
        }
    }
    for (int i = 0; i < testTweets.getSize(); i++) {
        returnedRating = classify.Classify(testTweets[i]);
        if (returnedRating != testTweets[i].getRating()) {
            output << testTweets[i].getID() << ",";
            output << "i" << endl;
        }
    }
}

int stringToInt(string s) {
    int x = atoi(s.c_str());
    return x;
}

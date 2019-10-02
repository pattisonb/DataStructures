#ifndef TWEET_H
#define TWEET_H
#include "dsstring.h"
#include "dsvector.h"
#include "porter2_stemmer.h"
using namespace std;

class Tweet
{
private:
    int idNum;
    int rating;
    DSString contents;
    DSVector <DSString> words;

    friend class Classifier;
public:
    Tweet();
    Tweet(int, int, DSString);
    ~Tweet();
    int getID();
    int getRating();
    void createWords();
    void printWords();
};

#endif // TWEET_H

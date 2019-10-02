#ifndef TWEET_H
#define TWEET_H
#include "dsstring.h"
#include "dsvector.h"
using namespace std;

class tweet
{
private:
    int idNum;
    int rating;
    DSString contents;
    DSVector <DSString> words;
public:
    tweet();
    tweet(int, int, DSString);
    ~tweet();
    int getID();
    int getRating();
    void createWords();
    void printWords();
};

#endif // TWEET_H

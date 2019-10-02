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
    DSString stops [98] = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i", "it", "for", "not", "on", "with", "he", "as", "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her", "she", "or", "an", "will", "my", "one", "all", "would", "there", "their", "what", "so", "up", "out", "if", "about", "who", "get", "which", "go", "me", "when", "make", "can", "like", "time", "no", "just", "him", "know", "take", "people", "into", "year", "your", "some", "could", "them", "see", "other", "than", "then", "now", "look", "only", "come", "its", "over", "think", "also", "back", "after", "use", "two", "how", "our", "first", "well", "way", "even", "new", "want", "because", "any", "these", "give", "day", "most", "us"};

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

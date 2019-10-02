#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "dsvector.h"
#include "dsstring.h"
#include "tweet.h"


class Classifier
{
private:
    DSVector <DSString> allPositiveWords;
    DSVector <DSString> allNegativeWords;
    DSVector <DSString> PositiveWords;
    DSVector <DSString> NegativeWords;
    DSVector <DSString> veryPositiveWords;
    DSVector <DSString> veryNegativeWords;
    DSVector <DSString> veryVeryPositiveWords;
    DSVector <DSString> veryVeryNegativeWords;
    DSVector <Tweet> tweets;
public:
    Classifier();
    Classifier(DSVector <Tweet>);
    void populateVector();
    void quickSort(DSVector <DSString>&, int, int);
    void populateWordVectors();
    int Classify(Tweet);
};

#endif // CLASSIFIER_H

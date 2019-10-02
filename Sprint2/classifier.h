#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "dsvector.h"
#include "dsstring.h"
#include "tweet.h"


class Classifier
{
private:
    DSVector <DSString> positiveWords;
    DSVector <DSString> negativeWords;
    DSVector <Tweet> tweets;
public:
    Classifier();
    Classifier(DSVector <Tweet>);
    void populateVector();
    void quickSort(DSVector <DSString>&, int, int);
};

#endif // CLASSIFIER_H

#include "classifier.h"
using namespace std;

Classifier::Classifier()
{

}

Classifier::Classifier(DSVector <Tweet> data) {
    tweets = data;
    populateVector();
}
void Classifier::populateVector() {
    for (int i = 0; i < tweets.getSize(); i++) {
        if (tweets[i].getRating() == 4) {
            for (int j = 0; j < tweets[i].words.getSize(); j++) {
                DSString word = tweets[i].words[j];
                positiveWords.push_back(word);
            }
        }
        else if (tweets[i].getRating() == 0) {
            for (int j = 0; j < tweets[i].words.getSize(); j++) {
                DSString word = tweets[i].words[j];
                negativeWords.push_back(word);
            }
        }
    }
    quickSort(negativeWords, 0, negativeWords.getSize() - 1);
    quickSort(positiveWords, 0, positiveWords.getSize() - 1);
    positiveWords.print();
}

void Classifier::quickSort(DSVector <DSString>& V, int left, int right) {
    int x = left;
    int y = right;
    DSString temp;
    DSString pivot(V[(left + right) / 2]);
    while (x <= y) {
        while (V[x] < pivot) {
            x++;
        }
        while (V[y] > pivot) {
            y--;
        }
        if (x <= y) {
            temp = V[x];
            V[x] = V[y];
            V[y] = temp;
            x++;
            y--;
        }
    }
    if (left < y) {
        quickSort(V, left, y);
    }
    if (x < right) {
        quickSort(V, x, right);
    }
}

#include "classifier.h"
using namespace std;

Classifier::Classifier()
{

}

Classifier::Classifier(DSVector <Tweet> data) {
    tweets = data;
    populateVector();
}

int Classifier::Classify(Tweet tweet) {
    int total = 0;
    for (int i = 0; i < tweet.words.getSize(); i++) {
        if (NegativeWords.countDuplicate(tweet.words[i]) == 1) {
            total -= 3;
        }
        else if (veryNegativeWords.countDuplicate(tweet.words[i]) == 1) {
            total -= 6;
        }
        else if (veryVeryNegativeWords.countDuplicate(tweet.words[i]) == 1) {
            total -= 10;
        }
        if (PositiveWords.countDuplicate(tweet.words[i]) == 1) {
            total += 3;
        }
        else if (veryPositiveWords.countDuplicate(tweet.words[i]) == 1) {
            total += 6;
        }
        else if (veryVeryPositiveWords.countDuplicate(tweet.words[i]) == 1) {
            total += 10;
        }
    }
    if (total > 0) {
        return 4;
    }
    if (total < 0) {
        return 0;
    }
    if (total == 0) {
        return 4;
    }
}
void Classifier::populateVector() {
    for (int i = 0; i < tweets.getSize(); i++) {
        if (tweets[i].getRating() == 4) {
            for (int j = 0; j < tweets[i].words.getSize(); j++) {
                DSString word = tweets[i].words[j];
                allPositiveWords.push_back(word);
            }
        }
        else if (tweets[i].getRating() == 0) {
            for (int j = 0; j < tweets[i].words.getSize(); j++) {
                DSString word = tweets[i].words[j];
                allNegativeWords.push_back(word);
            }
        }
    }
    //quickSort(allNegativeWords, 0, allNegativeWords.getSize() - 1);
    //quickSort(allPositiveWords, 0, allPositiveWords.getSize() - 1);
    populateWordVectors();
    //NegativeWords.print();
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

void Classifier::populateWordVectors() {
    for (int i = 0; i < allPositiveWords.getSize(); i++) {
        int count = allPositiveWords.countDuplicate(allPositiveWords[i]);
        if (count >= 20) {
            int count2 = veryVeryPositiveWords.countDuplicate(allPositiveWords[i]);
            if (count2 < 1) {
                veryVeryPositiveWords.push_back(allPositiveWords[i]);
            }
        }
        else if (count >= 14) {
            int count2 = veryPositiveWords.countDuplicate(allPositiveWords[i]);
            if (count2 < 1) {
                veryPositiveWords.push_back(allPositiveWords[i]);
            }
        }
        else if (count >= 5) {
            int count2 = PositiveWords.countDuplicate(allPositiveWords[i]);
            if (count2 < 1) {
                PositiveWords.push_back(allPositiveWords[i]);
            }
        }
    }
    for (int i = 0; i < allNegativeWords.getSize(); i++) {
        int count = allNegativeWords.countDuplicate(allNegativeWords[i]);
        if (count >= 20) {
            int count2 = veryVeryNegativeWords.countDuplicate(allNegativeWords[i]);
            if (count2 < 1) {
                veryVeryNegativeWords.push_back(allNegativeWords[i]);
            }
        }
        else if (count >= 14) {
            int count2 = veryNegativeWords.countDuplicate(allNegativeWords[i]);
            if (count2 < 1) {
                veryNegativeWords.push_back(allNegativeWords[i]);
            }
        }
        else if (count >= 5) {
            int count2 = NegativeWords.countDuplicate(allNegativeWords[i]);
            if (count2 < 1) {
                NegativeWords.push_back(allNegativeWords[i]);
            }
        }
    }
}

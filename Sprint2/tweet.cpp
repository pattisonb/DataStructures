#include "tweet.h"

tweet::tweet()
{
    idNum = 0;
    rating = 0;
    contents = "";
}

tweet::tweet(int ID, int rate, DSString c) {
    if (ID <= 0) {
        ID *= -1;
    }
    idNum = ID;
    rating = rate;
    contents = c;
    createWords();
}

tweet::~tweet() {

}

int tweet::getID() {
    return idNum;
}

int tweet::getRating() {
    return rating;
}

void tweet::createWords() { //separates tweet into a vector of individual words
    char* token = strtok(contents.c_str(), " ");
    while (token != NULL) {
        DSString temp(token);
        words.push_back(temp);
        token = strtok(NULL, " ");
    }
}

void tweet::printWords() {
    for (int i = 0; i < words.getSize(); i++) {
         cout << words[i] << endl;;
    }
}

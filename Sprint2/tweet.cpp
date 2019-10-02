#include "tweet.h"
#include "porter2_stemmer.h"

Tweet::Tweet()
{
    idNum = 0;
    rating = 0;
    contents = "";
}

Tweet::Tweet(int ID, int rate, DSString c) {
    if (ID <= 0) {
        ID *= -1;
    }
    idNum = ID;
    rating = rate;
    contents = c;
    createWords();
}

Tweet::~Tweet() {

}

int Tweet::getID() {
    return idNum;
}

int Tweet::getRating() {
    return rating;
}

void Tweet::createWords() { //separates tweet into a vector of individual words
    char* token = strtok(contents.c_str(), " ");
    while (token != NULL) {
        if (token[0] != '@') {
            for (int i = 0; token[i]; i++) {
                if (!isalpha(token[i])) {
                    for (int j = i; token[j]; j++) {
                        token[j] = token[j + 1];
                    }
                }
                token[i] = tolower(token[i]);
            }
            string toStem = token;
            Porter2Stemmer::stem(toStem);
            DSString temp(toStem);
            if (temp.size() != 0 && token[0] != '@') {
                words.push_back(temp);
            }
        }
        token = strtok(NULL, " ");
    }
}

void Tweet::printWords() {
    for (int i = 0; i < words.getSize(); i++) {
         cout << words[i] << endl;;
    }
}

#include "dsstring.h"
#include <iostream>

using namespace std;

DSString::DSString() {
    data = nullptr;
}

DSString::DSString(const char* d){
    data = new char[strlen(d) + 1];
    strcpy(data, d);
}

DSString::DSString(const string d) {
    data = new char[d.size() + 1];
    strcpy(data, d.c_str()); //adding .c_str allows use of string copy here
}

DSString::DSString(const DSString& d){
    int length = 0;
    length = strlen(d.data);
    data = new char[length + 1];
    strcpy(data, d.data);
}

DSString::~DSString(){
    if (data != nullptr){
        delete [] data;
    }
}

DSString & DSString::operator= (const char* p) {
    if (data != nullptr){
        delete [] data;
    }
    this->data = new char[strlen(p) + 1];
    strcpy(this->data, p);
    return *this;
}

DSString & DSString::operator= (const DSString& p) {
    if (data != nullptr){
        delete [] data;
    }
    int length = 0;
    length = strlen(p.data);
    data = new char [length + 1];
    strncpy(data, p.data, length);
    return *this;
}

DSString DSString::operator+ (const DSString& p){
    char* temp = this->data;
    this->data = new char[strlen(p.data) + 1];
    strcat(data, temp);
    strcat(data, p.data);
    delete [] temp;
    return data;
}

DSString& DSString::operator+=(const DSString& p) {
    char* temp = this->data;
    this->data = new char[strlen(temp) + strlen(p.data) + 1];
    strcpy(this->data, temp);
    strcat(this->data, p.data);
    delete[] temp;
    return *this;
}

bool DSString::operator==(const char * p) {
    if (strcmp(data, p) == 0) {
        return true;
    }
    else {
       return false;
    }
}

bool DSString::operator==(const DSString & p) {
    if (strcmp(data, p.data) == 0) {
        return true;
    }
       return false; //fucntion reaches end without returning if the else block in included
}

bool DSString::operator<(const char * p) {
    if (strcmp(data, p) < 0) {
        return true;
    }
       return false;
}

bool DSString::operator<(const DSString & p) {
    if (strcmp(data, p.data) < 0) {
        return true;
    }
       return false;
}

char& DSString::operator[] (const int b) {
    return this->data[b];
}

int DSString::size() {
    return strlen(data);
}

DSString DSString::substring(int a, int b) {
    DSString returnString;
    char * temp = new char[strlen(this->data) + 1];
    int start = 0;
    if (b >= 0) {
        for (int i = a - 1; i < b; i++) {
            temp[start] = this->data[i];
            start++;
        }
        returnString.data = temp;
    }
    if (b < 0) {
        for (int i = (-1 * b); i <= a; i++) {
            temp[start] = this->data[i];
            start++;
        }
        returnString.data = temp;
    }
    return returnString;
}

char* DSString::c_str() {
    return data;
}


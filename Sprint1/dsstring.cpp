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
    data = new char[(strlen(d.data)) + 1];
    strcpy(data, d.data); //make sure to use .data when using string functions with DSString
}

DSString::~DSString(){
    delete [] data;
}

DSString & DSString::operator= (const char* p) {
    char* temp = this->data;
    this->data = new char[strlen(p) + 1];
    strcpy(this->data, p);
    delete[] temp;
    return *this;
}

DSString & DSString::operator= (const DSString& p) {
    char* temp = this->data;
    this->data = new char[strlen(p.data) + 1];
    strcpy(this->data, p.data);
    delete[] temp;
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
    char* temp = nullptr;
    if (b >=0) { //copying forwards
        temp[0] = this->data[a-1]; //setting first character in temp to the value of the DSString at a
        strncpy(returnString.data, temp, b+1);
        temp[b+1] = '\0'; //setting the null ptr at the end
        return returnString;
    }
    else {
        int start = (a-1) + b;
        temp[0] = this->data[start]; //setting first character in temp to the desired letter
        strncpy(returnString.data, temp, a+1);
        temp[a+1] = '\0'; //setting the null ptr at the end
        return returnString;
    }
}


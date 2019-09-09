#include "dsstring.h"

DSString::DSString() {
    data = nullptr;
}

DSString::DSString(const char* d){
    data = new char[strlen(d) + 1];
    strcpy(data, d);
}

DSString::DSString(const DSString& d){
    data = new char[(strlen(d.data)) + 1];
    strcpy(data, d);
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
    strcat(data, p);
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
    if (strcmp(data, p) == 0) {
        return true;
    }
    else {
       return false;
    }
}

bool DSString::operator<(const char * p) {
    if (strcmp(data, p) < 0) {
        return true;
    }
    else {
       return false;
    }
}

bool DSString::operator<(const DSString & p) {
    if (strcmp(data, p) < 0) {
        return true;
    }
    else {
       return false;
    }
}

char& DSString::operator[] (const int b) {
    return this->data[b];
}

int DSString::size() {
    return strlen(data);
}

DSString DSString::substring(int a, int b) {

}

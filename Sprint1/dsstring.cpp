#include "dsstring.h"

DSString::DSString() {
    data = nullptr;
}

DSString::DSString(const char* d){
    data = new char[strlen(d) + 1];
    strcpy(data, d);
}

DSString::DSString(const DSString& d){

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

DSString DSString::operator+ (const DSString&){

}

DSString& DSString::operator+=(const DSString& p) {
    char* temp = this->data;
    this->data = new char[strlen(temp) + strlen(p.data) + 1];
    strcpy(this->data, temp);
    strcat(this->data, p.data);
    delete[] temp;
    return *this;
}

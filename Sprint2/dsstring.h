#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>

using namespace std;


class DSString
{
private:
    char* data;
public:
    DSString();
    DSString(const char*);
    DSString(const string);
    DSString(const DSString&);
    ~DSString();

    DSString& operator= (const char*);
    DSString& operator= (const DSString&);
    DSString operator+ (const DSString&);
    DSString& operator += (const DSString&);
    bool operator== (const char*) const;
    bool operator== (const DSString&) const;
    bool operator< (const char*) const;
    bool operator< (const DSString&) const;
    char& operator[] (const int);

    int size();

    /*substring; paramter a represents where you start
     * b is the number of characters to copy into the substring
     * if b is positive count forward from position a, if negaive, count backwards
     */
    DSString substring(int a, int b);

    char* c_str();

    friend ostream& operator<< (std::ostream& stream, const DSString& string) {
        stream << string.data;
        return stream;
    }

};

#endif // DSSTRING_H

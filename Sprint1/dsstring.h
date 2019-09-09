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
	bool operator== (const char*);
	bool operator== (const DSString&);
	bool operator< (const char*);
	bool operator< (const DSString&);
	char& operator[] (const int);

	int size();

    /*substring; paramter a represents where you start
     * b is the number of characters to copy into the substring
     * if b is positive count forward from position a, if negaive, count backwards
     */
	DSString substring(int a, int b);
	
	char* c_str();

	friend ostream& operator<< (
        ostream&, const string&);

};

#endif // DSSTRING_H

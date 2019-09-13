#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"



class player
{
private:
    DSString m_name;
    int m_idNum;
    int m_points = 0;
    int tags = 0;
public:
    player();
    player(DSString, int);
    ~player();
    DSString getName();
    int getID();
    int getPoints();
    int getTags();
    void setTags(int a);
    void addTag(int);
};

#endif // PLAYER_H

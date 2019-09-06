#ifndef PLAYER_H
#define PLAYER_H

#include "dsstring.h"



class player
{
private:
    DSString m_name;
    int m_idNum;
    int m_points;
public:
    player();
    player(DSString, int);
    DSString getName();
    int getID();
    int getPoints();
};

#endif // PLAYER_H

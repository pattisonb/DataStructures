#ifndef TEAM_H
#define TEAM_H

#include "dsstring.h"
#include "player.h"
using namespace std;

class Team
{
private:
    int m_size;
    DSString m_name;
    int m_points;
    //player [];

public:
    Team();
    Team(int, DSString);
    DSString getName();
    int getNumPlayers();
    int getPoints();
};

#endif // TEAM_H

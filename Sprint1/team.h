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
    player * players;
    int numPlayersCreated = 0; //used to add players into the array and increment through the array

public:
    Team();
    Team(int, DSString);
    DSString getName();
    int getNumPlayers();
    int getPoints();
    void addPlayer(DSString playerName, int idNum);
};

#endif // TEAM_H

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
    int m_points = 0;
    int numPlayersCreated = 0; //used to add players into the array and increment through the array

public:
    Team();
    Team(int, DSString);
    ~Team();
    DSString getName();
    int getNumPlayers();
    int getPoints();
    void addPoints(int);
    player * players;
    void addPlayer(DSString playerName, int idNum);
};

#endif // TEAM_H

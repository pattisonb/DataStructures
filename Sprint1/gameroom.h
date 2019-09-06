#ifndef GAMEROOM_H
#define GAMEROOM_H

#include <fstream>
#include "dsstring.h"
#include "player.h"
#include "team.h"
using namespace std;


class GameRoom
{
private:
    Team team1;
    Team team2;
public:
    GameRoom();

};

#endif // GAMEROOM_H

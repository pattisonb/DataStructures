#include <iostream>
#include <fstream>
#include "dsstring.h"
#include "gameroom.h"
#include "team.h"
#include "player.h"
#include <string>

using namespace std;

void createTeams(ifstream t1_data, ifstream t2_data);

int main(int argc, char** argv)
{
    ifstream team1Data(argv[0]);
    ifstream team2Data(argv[1]);
    ifstream matchData(argv[2]);
    ofstream outputFile(argv[3]);
}

void createTeams(ifstream t1_data, ifstream t2_data) {
    char* teamName = new char[40];
    DSString team1Name;
    int team1Size;
    team1Name = teamName;
    t1_data >> team1Size;
    Team team1 = *new Team(team1Size, team1Name);

    DSString team2Name;
    int team2Size;
    t2_data >> teamName;
    team2Name = teamName;
    t2_data >> team2Size;
    Team team2 = *new Team(team2Size, team2Name);
}

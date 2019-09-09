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
    string name;
    getline(t1_data, name); //getting the team name into buffer string
    DSString team1Name(name);
    int team1Size;
    t1_data >> team1Size;
    Team team1 = *new Team(team1Size, team1Name);

    getline(t2_data, name); //getting the team name into buffers
    DSString team2Name(name);
    int team2Size;
    t2_data >> team2Size;
    Team team2 = *new Team(team2Size, team2Name);
}

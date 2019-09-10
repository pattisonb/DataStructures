#include <iostream>
#include <fstream>
#include "dsstring.h"
#include "gameroom.h"
#include "team.h"
#include "player.h"
#include <string>

using namespace std;

Team* createTeam(ifstream& teamData);

int main(int argc, char** argv)
{
    ifstream team1Data(argv[1]);
    ifstream team2Data(argv[2]);
    ifstream matchData(argv[3]);
    ofstream outputFile(argv[4]);
    char* verbosity = argv[5];

    Team* team1 = createTeam(team1Data);
    Team* team2 = createTeam(team2Data);
}

Team* createTeam(ifstream& teamData) {
    const bool DEBUG = true;
    string buffer;
    getline(teamData, buffer); //getting the team name into buffer string
    if(DEBUG) cout << buffer << endl;
    DSString teamName(buffer);
    int teamSize;
    teamData >> teamSize;
    if(DEBUG) cout << teamSize << endl;
    Team* team = new Team(teamSize, teamName);
    int idNum;
    for (int i = 0; i < teamSize; i++) {
        teamData >> idNum;
        getline(teamData, buffer);
        if(DEBUG) cout << idNum << endl;
        if(DEBUG) cout << buffer << endl;
        DSString name(buffer);
        team->addPlayer(name, idNum);
    }
    return team;
}

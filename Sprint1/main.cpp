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
    //ifstream team1Data(argv[0]);
    ifstream team1Data("cowboys.txt");
    //ifstream team2Data(argv[1]);
    //ifstream matchData(argv[2]);
    //ofstream outputFile(argv[3]);

    Team* team1 = createTeam(team1Data);
    //Team* team2 = createTeam(team2Data);
}

Team* createTeam(ifstream& teamData) {
    string buffer;
    getline(teamData, buffer); //getting the team name into buffer string
    cout << buffer << endl;
    DSString teamName(buffer);
    int teamSize;
    teamData >> teamSize;
    Team* team = new Team(teamSize, teamName);
    int idNum;
    for (int i = 0; i < teamSize; i++) {
        teamData >> idNum;
        teamData >> buffer;
        DSString name(buffer);
        team->addPlayer(name, idNum);
    }
    return team;
}

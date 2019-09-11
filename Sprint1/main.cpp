#include <iostream>
#include <fstream>
#include "dsstring.h"
#include "gameroom.h"
#include "team.h"
#include "player.h"
#include <string>

using namespace std;

Team createTeam(ifstream& teamData);
void lowVerbPrint(Team team1, Team team2, ifstream& data, ofstream& output);
void medVerbPrint(Team team1, Team team2, ifstream& data, ofstream& output);

int main(int argc, char** argv)
{
    ifstream team1Data(argv[1]);
    ifstream team2Data(argv[2]);
    ifstream matchData(argv[3]);
    ofstream outputFile(argv[4]);
    char* verbosity = argv[5];

    Team team1 = createTeam(team1Data);
    Team team2 = createTeam(team2Data);
    medVerbPrint(team1, team2, matchData, outputFile);
}

Team createTeam(ifstream& teamData) {
    const bool DEBUG = false;
    string buffer;
    getline(teamData, buffer); //getting the team name into buffer string
    if(DEBUG) cout << buffer << endl;
    DSString teamName(buffer);
    int teamSize;
    teamData >> teamSize;
    if(DEBUG) cout << teamSize << endl;
    Team team = Team(teamSize, teamName);
    int idNum;
    for (int i = 0; i < teamSize; i++) {
        teamData >> idNum;
        getline(teamData, buffer);
        if(DEBUG) cout << idNum << endl;
        if(DEBUG) cout << buffer << endl;
        DSString name(buffer);
        team.addPlayer(name, idNum);
    }
    return team;
}

void lowVerbPrint(Team team1, Team team2, ifstream& data, ofstream& output) {
    int numTags;
    int taggerID;
    int taggedID;
    int timeTag;
    int tagSpot;
    int tagPoints = 0;
    data >> numTags;
    for (int i = 0; i < numTags; i++) {
        data >> taggerID;
        data >> taggedID;
        data >> timeTag;
        data >> tagSpot;
        if (tagSpot == 1) {
            tagPoints = 5;
        }
        else if (tagSpot == 2) {
            tagPoints = 8;
        }
        else if (tagSpot == 3) {
            tagPoints = 7;
        }
        else if (tagSpot == 4) {
            tagPoints = 4;
        }
        for (int i = 0; i < team1.getNumPlayers(); i++) {
            if (team1.players[i].getID() == taggerID) {
                team1.addPoints(tagPoints);
            }
        }
        for (int i = 0; i < team2.getNumPlayers(); i++) {
            if (team2.players[i].getID() == taggerID) {
                team2.addPoints(tagPoints);
            }
        }
    }
    team1.sort();
    team2.sort();
    output << team1.getName() << ": " << team1.getPoints() << " points" << endl;
    output << team2.getName() << ": " << team2.getPoints() << " points" << endl;
    if (team1.getPoints() > team2.getPoints()) {
        output << "Overall Winners: " << team1.getName() << endl;
    }
    else if (team1.getPoints() < team2.getPoints()) {
        output << "Overall Winners: " << team2.getName() << endl;
    }
    else {
        output << "It's a tie." << endl;
    }
}

void medVerbPrint(Team team1, Team team2, ifstream& data, ofstream& output) {
    int numTags;
    int taggerID;
    int taggedID;
    int timeTag;
    int tagSpot;
    int tagPoints = 0;
    data >> numTags;
    for (int i = 0; i < numTags; i++) {
        data >> taggerID;
        data >> taggedID;
        data >> timeTag;
        data >> tagSpot;
        if (tagSpot == 1) {
            tagPoints = 5;
        }
        else if (tagSpot == 2) {
            tagPoints = 8;
        }
        else if (tagSpot == 3) {
            tagPoints = 7;
        }
        else if (tagSpot == 4) {
            tagPoints = 4;
        }
        for (int i = 0; i < team1.getNumPlayers(); i++) {
            if (team1.players[i].getID() == taggerID) {
                team1.players[i].addTag(tagPoints);
                team1.addPoints(tagPoints);
            }
        }
        for (int i = 0; i < team2.getNumPlayers(); i++) {
            if (team2.players[i].getID() == taggerID) {
                team2.players[i].addTag(tagPoints);
                team2.addPoints(tagPoints);
            }
        }
    }
    output << team1.getName() << endl;
    for (int i = 0; i < team1.getNumPlayers(); i++) {
        output << "\t" << team1.players[i].getName() << " had a total of "
               << team1.players[i].getTags() << " tags\n" << endl;
    }
    output << team2.getName() << endl;
    for (int i = 0; i < team2.getNumPlayers(); i++) {
        output << "\t" << team2.players[i].getName() << " had a total of "
               << team2.players[i].getTags() << " tags\n" << endl;
    }
    output << team1.getName() << ": " << team1.getPoints() << " points" << endl;
    output << team2.getName() << ": " << team2.getPoints() << " points" << endl;
    if (team1.getPoints() > team2.getPoints()) {
        output << "Overall Winners: " << team1.getName() << endl;
    }
    else if (team1.getPoints() < team2.getPoints()) {
        output << "Overall Winners: " << team2.getName() << endl;
    }
    else {
        output << "It's a tie." << endl;
    }
}

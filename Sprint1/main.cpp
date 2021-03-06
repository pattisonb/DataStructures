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
void highVerbPrint(Team team1, Team team2, ifstream& data, ofstream& output); //has to have two datas
//so that it can read the match files twice
void getTags(player, Team, ifstream&data, ostream&);

int main(int argc, char** argv)
{
    ifstream team1Data(argv[1]);
    ifstream team2Data(argv[2]);
    ifstream matchData(argv[3]);
    ofstream outputFile(argv[4]);
    char* verbosity = argv[5];

    Team team1 = createTeam(team1Data);
    Team team2 = createTeam(team2Data);
    if (strcmp(verbosity,"vlow") == 0) {
        lowVerbPrint(team1, team2, matchData, outputFile);
    }
    if (strcmp(verbosity,"vmed") == 0) {
        medVerbPrint(team1, team2, matchData, outputFile);
    }
    if (strcmp(verbosity,"vhigh") == 0) {
        highVerbPrint(team1, team2, matchData, outputFile);
    }
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
        data >> taggerID; //reading player info
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
    team1.sort(); //sorting the teams by tags
    team2.sort();
    output << team1.getName() << endl;
    for (int i = 0; i < team1.getNumPlayers(); i++) {
        if (team1.players[i].getTags() == 1) {
            output << "\t" << team1.players[i].getName() << " had a total of "
                   << team1.players[i].getTags() << " tag\n" << endl;
        }
        else
        output << "\t" << team1.players[i].getName() << " had a total of "
               << team1.players[i].getTags() << " tags\n" << endl;
    }
    output << team2.getName() << endl;
    for (int i = 0; i < team2.getNumPlayers(); i++) {
        if (team2.players[i].getTags() == 1) {
            output << "\t" << team2.players[i].getName() << " had a total of "
                   << team2.players[i].getTags() << " tag\n" << endl;
        }
        else
        output << "\t" << team2.players[i].getName() << " had a total of "
               << team2.players[i].getTags() << " tags\n" << endl;
    }
    team1.highScore(); //putting the player with the highest score into players[0]
    team2.highScore();
    output << "Best score from " << team1.getName() << ":" << team1.players[0].getName()
           << " (" << team1.players[0].getPoints() << " points)" << endl;
    if (team1.players[0].getPoints() == team1.players[1].getPoints()) {
        output << "Best score from " << team1.getName() << ":" << team1.players[1].getName()
               << " (" << team1.players[1].getPoints() << " points)" << endl;
    }
    output << "Best score from " << team2.getName() << ":" << team2.players[0].getName()
           << " (" << team2.players[0].getPoints() << " points)" << endl;
    if (team2.players[0].getPoints() == team2.players[1].getPoints()) {
        output << "Best score from " << team2.getName() << ":" << team2.players[1].getName()
               << " (" << team2.players[1].getPoints() << " points)" << endl;
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

void highVerbPrint(Team team1, Team team2, ifstream& data1, ofstream& output) {
    int numTags;
    int taggerID;
    int taggedID;
    int timeTag;
    int tagSpot;
    int tagPoints = 0;
    data1 >> numTags;
    for (int i = 0; i < numTags; i++) {
        data1 >> taggerID;
        data1 >> taggedID;
        data1 >> timeTag;
        data1 >> tagSpot;
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
                team1.players[i].addTag(1);
                team1.addPoints(tagPoints);
            }
        }
        for (int i = 0; i < team2.getNumPlayers(); i++) {
            if (team2.players[i].getID() == taggerID) {
                team2.players[i].addTag(1);
                team2.addPoints(tagPoints);
            }
        }
    }
    team1.sort();
    team2.sort();
    data1.clear();
    data1.seekg(0, ios::beg); //going back to the beginning of the file
    output << team1.getName() << endl;
    for (int i = 0; i < team1.getNumPlayers(); i++) {
        getTags(team1.players[i], team2, data1, output);
    }

    output << team1.getName() << ": " << team1.getPoints() << " points\n" << endl;
    output << team2.getName() << endl;
    for (int i = 0; i < team1.getNumPlayers(); i++) {
        getTags(team2.players[i], team1, data1, output);
    }
    output << team2.getName() << ": " << team2.getPoints() << " points\n" << endl;
    if (team1.getPoints() > team2.getPoints()) {
        output << "Winners: " << team1.getName() << endl;
    }
    if (team1.getPoints() < team2.getPoints()) {
        output << "Winners: " << team2.getName() << endl;
    }
    if (team1.getPoints() == team2.getPoints()) {
        output << "There was a ties" << endl;
    }
}

void getTags(player p, Team teamb, ifstream&data, ostream&output) { //player comes come from one team and the team is the other
    int numTags = 0;
    int totalTags = 0;
    int tagger;
    int tagged;
    int tags [100];
    int time;
    int shotPlace;
    int counter = 0;
    data >> numTags;
    for (int i = 0; i < numTags; i++) {
        data >> tagger;
        data >> tagged;
        data >> time;
        data >> shotPlace;
        if (p.getID() == tagger) {
            tags[i] = tagged;
            counter++;
        }
    }
        for (int j = 0; j < teamb.getNumPlayers(); j++) {
            for (int i = 0; i < numTags; i++) {
            if (teamb.players[j].getID() == tags[i]) {
                teamb.players[j].addTag(1);
                }
            }
        }
        teamb.sort();
        for (int j = 0; j < teamb.getNumPlayers(); j++) {
            output << "\t" << p.getName() << " tagged" << teamb.players[j].getName() << " " <<
                      teamb.players[j].getTags() << " times" << endl;
            totalTags += teamb.players[j].getTags();

        }
        output << "\t" << p.getName() << " had a total of " << totalTags << " tags" << endl;
        data.clear();
        data.seekg(0, ios::beg); //going to beginning of the file
        for (int j = 0; j < teamb.getNumPlayers(); j++) {
            teamb.players[j].setTags(0);
        }
}



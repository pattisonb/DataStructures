#include "team.h"

Team::Team() {
    players = nullptr;
}

Team::Team(int a, DSString b){
    m_size = a;
    m_name = b;
    players = new player[a];
}

Team::~Team() {
    //if (players != nullptr)
        //delete [] players;
}

DSString Team::getName() {
    return m_name;
}

int Team::getNumPlayers() {
    return m_size;
}

int Team::getPoints() {
    return m_points;
}

void Team::addPoints(int a) {
    m_points+=a;
}

void Team::addPlayer(DSString playerName, int idNum) {
    players[numPlayersCreated] = player(playerName, idNum);
    numPlayersCreated++;
}

void Team::sort() { //sorts by number of tags than by alph
    for (int i = 0; i < m_size - 1; i++) {
        int highScore = i;
        for (int x = i + 1; x < m_size; x++) {
            if (players[x].getTags() > players[i].getTags()) {
                highScore = x;
            }
            if (players[x].getTags() == players[i].getTags()) {
                if (players[i].getName() < players[x].getName()) {
                    highScore = x;
                }
            }
        }
        swap(players[i], players[highScore]);
    }
}

void Team::highScore() { // using because player with highest tags may not have highest score
    for (int i = 0; i < m_size - 1; i++) {
        int highScore = i;
        for (int x = i + 1; x < m_size; x++) {
            if (players[x].getPoints() > players[i].getPoints()) {
                highScore = x;
            }
            if (players[x].getPoints() == players[i].getPoints()) {
                if (players[i].getName() < players[x].getName()) {
                    highScore = x;
                }
            }
        }
        swap(players[i], players[highScore]);
    }
}

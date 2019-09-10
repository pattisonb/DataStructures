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
    delete [] players;
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

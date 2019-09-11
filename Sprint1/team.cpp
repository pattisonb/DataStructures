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

void Team::sort() {
    int counter; //using two counters for the two loops
    int counter1;
    int smallest;
    player temp;

    for (counter = 0; counter < m_size - 1; ++counter) {
        smallest = counter; //treat the newest player as the last in tag order and then check it
        for (counter1 = counter+1; counter1 < m_size; ++counter1) {
            if (players[counter1].getTags() < players[smallest].getTags()) {
                smallest = counter1;
            }
        }
    }
    //swap
    temp = players[counter];
    players[counter] = players[smallest];
    players[smallest] = temp;

}

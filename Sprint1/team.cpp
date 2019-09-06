#include "team.h"

Team::Team(int a, DSString b){
    m_size = a;
    m_name = b;
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

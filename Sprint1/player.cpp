#include "player.h"

player::player(){}

player::player(DSString n, int i) {
    m_name = n;
    m_idNum = i;
}

int player::getID() {
    return m_idNum;
}

DSString player::getName() {
    return m_name;
}

int player::getPoints() {
    return m_points;
}

#include "player.h"

player::player(){
    m_name = "";
    m_idNum = 0;
}

player::~player(){

}

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

int player::getTags() {
    return tags;
}

void player::addTag(int a) {
    tags++;
    m_points += a;
}

void player::setTags(int a) {
    tags = a;
}

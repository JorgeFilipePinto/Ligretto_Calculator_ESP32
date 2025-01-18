#include "Game.h"

void Game::init(int playersNumber) {
    this-> playersNumber = playersNumber;
    this-> players = new Player[playersNumber];
}


void Game::playersCreating() {
    for (int i = 0; i < playersNumber; i++) {
        players[i].name = "Player" + String(i + 1);
    }
    for(int i = 0; i < playersNumber; i++) {
        Serial.println("jogador: " + String(i + 1));
        Serial.println(players[i].name);
        playersCreated++;
    }
    Serial.println("Jogadores criados: " + String(playersCreated));
}
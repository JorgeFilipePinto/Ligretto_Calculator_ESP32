#include "Game.h"

void Game::init() {
    this-> players = new Player[playersNumber];
}


void Game::playersCreating() {
    for (int i = 0; i < playersNumber; i++) {
        players[i].name = "Player " + String(i + 1);
        Serial.println("Jogador: " + players[i].name + " criado");
        playersCreated++;
    }
    gameExist = true;
    Serial.println("Jogadores criados: " + String(playersCreated));
}

int Game::howIsWin() {
    int maxPoints = 0;
    int indexPlayer = 0;

    for(int i = 0; i < sizeof(players); i++) {
        if (players[i].points > maxPoints) {
            indexPlayer = i;
        }
    }

    return indexPlayer;
}

void Game::newRound() {
    round++;
    for (int i = 0; i < playersNumber; i++) {
        players[i].points += players[i].tempPoints;
        players[i].handCards = 0;
        players[i].tableCards = 0;
        players[i].tempPoints = 0;
        Serial.println(players[i].name + " está com " + String(players[i].points) + "pontos.");
    }
}

bool Game::roudIsFinish() {
    for (int i = 0; i < playersNumber; i++) {
        if (players[i].round != round) {
            return false;
        }
    }
    return true;
}

void Game::setPlayerRound(int index) {
    players[index].round = round;
}

int Game::pointsCalcule(int index) {
    int points = 0;
    points -= players[index].handCards * 2;
    points += players[index].tableCards;
    return points;
}


Player Game::winnerCalculation() {
    int maxPoints = 0;
    int playerIndex;

    for(int i = 0; i < playersNumber; i++) {
        
        if (players[i].points > maxPoints) {

            maxPoints = players[i].points;
            playerIndex = i;
        
        }

    }
    return players[playerIndex];
}
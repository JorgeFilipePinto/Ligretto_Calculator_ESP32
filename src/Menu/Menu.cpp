#include "Menu.h"


void Menu::init() {
    mainMenu = MAIN;
    lcd.init();
    lcd.apresentation();
    encoder.init();
    encoder.begin();
    encoder.setSelectorRange(1, 3, 1, 1, false);
}


void Menu::checkMainMenuImage() {
    switch(int(encoder.selectorState)) {
        case 1: {
            lcd.drawMenu1();
            break;
        }
        case 2: {
            lcd.drawMenu2();
            break;
        }
        case 3: {
            lcd.drawMenu3();
            break;
        }
    }
}


void Menu::checkMenu() {
    Serial.println("Menu Selected: " + String(encoder.selectorState));
    switch(int(encoder.selectorState)) {
        case 1: {
            mainMenu = NEWGAME;
            encoder.setSelectorRange(1, 12, 1, 1, false);
            break;
        }
        case 2: {
            game.gameExist ? mainMenu = CONTINUE : mainMenu = MAIN;
            break;
        }
        case 3: {
            mainMenu = QUIT;
            break;
        }
    }
}


void Menu::mainMenuNavigation() {
    checkMainMenuImage();
    if (encoder.hasChanged()) {
        encoder.getValue();
        Serial.println("Encoder State: " + String(encoder.selectorState));
    }
    if (encoder.isButtonClicked()) checkMenu();
}


bool Menu::newGameNavigation() {
    if (encoder.hasChanged()) {
        lcd.newData = true;
        encoder.getValue();
        game.playersNumber = int(encoder.selectorState);
    }

    if (lcd.newData) {
        lcd.write("Players?", 20, 10, 2);
        lcd.writeWithouClear(String(int(encoder.selectorState)), 55, 40, 3);
        lcd.newData = false;
    }

    if (encoder.isButtonClicked() && encoder.selectorState > 1) {
        Serial.println("Selecionado " + String(game.playersNumber) + " para jogar.");
        return true;
    }

    return false;
}


void Menu::gameMenuNavigation() {
    game.round++;
    lcd.newData = true;
    encoder.setSelectorRange(1, game.playersNumber, 1, 1, false);
    while(!game.isOver) {
        if (game.roudIsFinish()) {
            lcd.newData = true; 
            game.newRound();
            gameStatus();
            sleepMode = true;
        }

        if((millis() - lastTimer_ScreenStatus >= 10000) && !sleepMode) {
            sleepMode = true;
            lcd.newData = true;
            gameStatus();
        }

        if (encoder.hasChanged()) {
            sleepMode = false;
            lcd.newData = true;
            encoder.getValue();
            playerSelection();
            lastTimer_ScreenStatus = millis();
        }

        if (encoder.isButtonClicked()) {
            int index = encoder.selectorState;
            lcd.newData = true;
            encoder.setSelectorRange(-30, 60, 0, 1, false);
            playerData(index - 1);
        }
    }
}


void Menu::playerSelection() {
    if (lcd.newData) {
        lcd.write("Player", 20, 10, 2);
        lcd.writeWithouClear(String(int(encoder.selectorState)), 55, 40, 3);
        lcd.newData = false;
    }
}


void Menu::playerData(int index) {
    Serial.println(game.players[index].name);
    bool configured = false;
    bool handCards = false;
    bool tableCards = false;
    lcd.newData = true;
    encoder.setSelectorRange(0, game.maxCardsHand, 0, 1, false);

    while (!configured) {
        if (millis() - lastTimer_ScreenStatus >= 10000) {
            configured = true;
            handCards = true;
            tableCards = true;
            sleepMode = false;
        }

        if (lcd.newData) {
            lcd.write(game.players[index].name, 0, 0, 1);
            lcd.writeWithouClear(String(game.players[index].points), 100, 0, 1);
            lcd.writeWithouClear("Hand Cards: ", 0, 20, 1);
            lcd.writeWithouClear(String(game.players[index].handCards), 80, 20, 1);
            lcd.writeWithouClear("Table Cards: ", 0, 40, 1);
            lcd.writeWithouClear(String(game.players[index].tableCards), 80, 40, 1);
            lcd.newData = false;
        }

        if(encoder.hasChanged()) {
            encoder.getValue();
            lcd.newData = true;
        }

        if (!handCards) {
            lastTimer_ScreenStatus = millis();
            game.players[index].handCards = encoder.selectorState;
            }

        if (handCards) {
            lastTimer_ScreenStatus = millis();
            game.players[index].tableCards = encoder.selectorState;
            }


        if (encoder.isButtonClicked()) {
            if (!handCards) {
                handCards = true;
                encoder.setSelectorRange(0, game.maxCardsTable, 0, 1, false);
            } else {
                tableCards = true;
            }
            Serial.println("handcards: " + String(handCards));
            Serial.println("tableCards: " + String(tableCards));
        }

        if(tableCards && handCards) {
            game.players[index].tempPoints = game.pointsCalcule(index);
            Serial.println(game.players[index].name + " com " + String(game.players[index].tempPoints) + " pontos provisórios.");
            encoder.setSelectorRange(1, game.playersNumber, 1, 1, false);
            game.setPlayerRound(index);
            lcd.newData = true;
            gameStatus();
            configured = true;
        }
    }
}

void Menu::gameStatus() {
    
    if (lcd.newData) {
        /*
        lcd.write(String(game.players[game.howIsWin()].name), 0, 0, 2);
        lcd.writeWithouClear(String(game.players[game.howIsWin()].points), 100, 0, 2);
        */
       lcd.write("Status", 0, 0, 1);
       lcd.writeWithouClear("Round: " + String(game.round), 60, 0, 1);
        int posY = 3;
        for (int i = 0; i < game.playersNumber; i++) {
            posY += 10;
            lcd.writeWithouClear(String(game.players[i].name), 0, posY, 1);
            lcd.writeWithouClear(String(game.players[i].tempPoints + game.players[i].points), 100, posY, 1);
            if (game.players[i].round == game.round) {
                lcd.writeWithouClear("*", 80, posY, 1);
            }
        }
        lcd.newData = false;
    }
}

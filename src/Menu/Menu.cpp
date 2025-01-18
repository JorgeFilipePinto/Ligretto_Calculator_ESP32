#include "Menu.h"


void Menu::init() {
    mainMenu = NEWGAME;

    encoder.init();
    lcd.init();
}


void Menu::checkMainMenuImage() {
    switch(mainMenu) {
        case NEWGAME: {
            lcd.drawMenu1();
            break;
        }
        case CONTINUE: {
            lcd.drawMenu2();
            break;
        }
        case QUIT: {
            lcd.drawMenu3();
            break;
        }
    }
}


void Menu::nextMenu() {
    switch(mainMenu) {
        case NEWGAME: {
            mainMenu = CONTINUE;
            break;
        }
        case CONTINUE: {
            mainMenu = QUIT;
            break;
        }
        case QUIT: {
            mainMenu = NEWGAME;
            break;
        }
    }
}


void Menu::previousMenu() {
    switch(mainMenu) {
        case NEWGAME: {
            mainMenu = QUIT;
            break;
        }
        case CONTINUE: {
            mainMenu = NEWGAME;
            break;
        }
        case QUIT: {
            mainMenu = CONTINUE;
            break;
        }
    }
}




void Menu::mainMenuNavigation() {
    while(true) {
        checkMainMenuImage();
        encoder.isRotated() ? nextMenu() : void();
        encoder.last_CLK_estate = encoder.CLK_estate;
        if (encoder.buttonIsPressed()) {
            switch(mainMenu) {
                case NEWGAME: {
                    newGame = PLAYERS;
                    gameMenuNavigation();
                    break;
                }
                case CONTINUE: {
                    if (game.gameExist){
                        gameMode = PLAYERS_SELECTION;
                    }
                    break;
                }
                case QUIT: {

                    break;
                }
            }
        }
    }

}


void Menu::gameMenuNavigation() {
    while (!endGame) {
        switch (newGame) {
        case PLAYERS: {
            lcd.write("Players?", 20, 10, 2);
            if (encoder.isRotated()) {
                encoder.counterEncoder();
            } else {
                encoder.last_CLK_estate = encoder.readClk();
            }
            lcd.writeWithouClear(String(encoder.counter), 55, 40, 3);
            if (encoder.buttonIsPressed() && encoder.counter > 1) {
                newGame = NAMES;
                game.init(encoder.counter);
                encoder.counter = 0;
            }
            break;
        }

        case NAMES: {
            if(game.players > 0 && !(game.playersCreated > 0)) {
                game.playersCreating();
            }
            break;
            }
        }
    }
}


void Menu::getMenu() {
        
}



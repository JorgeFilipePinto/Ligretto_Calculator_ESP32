#pragma once
#include "LCD\Lcd.h"
#include "Encoder\Encoder.h"
#include "Game\Game.h"

enum MainMenu {
    NEWGAME,
    CONTINUE,
    QUIT
};

enum NewGame {
    PLAYERS,
    NAMES
};

enum GameMode {
    PLAYERS_SELECTION,
    TABLE_CARDS,
    HAND_CARDS
};



class Menu {
    public:
        MainMenu mainMenu;
        NewGame newGame;
        GameMode gameMode;

        Lcd lcd;
        Encoder encoder;
        Game game;

        bool endGame = false;

        void init();
        void checkMainMenuImage();
        void nextMenu();
        void previousMenu();
        void mainMenuNavigation();
        void gameMenuNavigation();
        void getMenu();
};
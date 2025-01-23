#pragma once
#include "LCD\Lcd.h"
#include "Encoder\Encoder.h"
#include "Game\Game.h"

enum MainMenu {
    MAIN,
    NEWGAME,
    CONTINUE,
    QUIT
};


class Menu {
    public:
        MainMenu mainMenu;
        Lcd lcd;
        Encoder encoder;
        Game game;

        bool endGame = false;
        bool sleepMode = false;
        unsigned long lastTimer_ScreenStatus = 10000;
        int delatyToNewRound = 2000;
        void init();
        void checkMainMenuImage();
        void checkMenu();
        void mainMenuNavigation();
        bool newGameNavigation();
        void gameMenuNavigation();
        void playerSelection();
        void playerData(int index);
        void gameStatus();

        void newGameStatus();
};
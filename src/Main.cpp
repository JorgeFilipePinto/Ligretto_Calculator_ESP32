#include <Arduino.h>
#include "Menu\Menu.h"

enum Device {
    MAIN_MENU,
    NEW_GAME,
    DEVICE_GAME,
    QUIT_DEVICE

};

Menu menu;
Device deviceState;

void setup() {
    Serial.begin(115200);
    menu.init();
    deviceState = MAIN_MENU;
}



void loop() {

    switch (deviceState) {
        case MAIN_MENU: {
            menu.mainMenuNavigation();
            if (menu.mainMenu == NEWGAME) deviceState = NEW_GAME;
            if (menu.mainMenu == CONTINUE) deviceState = DEVICE_GAME;
            if (menu.mainMenu == QUIT) deviceState = QUIT_DEVICE;
            break;
        }
        case NEW_GAME: {
            if (menu.newGameNavigation()) {
                menu.game.init();
                Serial.println("Criar jogadores.....");
                menu.game.playersCreating();
                Serial.println("Jogadores Criados com sucesso.....");
                deviceState = DEVICE_GAME;
            }
            break;
        }
        case DEVICE_GAME: {
            menu.gameStatus();
            menu.gameMenuNavigation();

            if (menu.encoder.isButtonClicked() && menu.game.isOver) {
                deviceState = MAIN_MENU;
            }
            break;
        }
        case QUIT_DEVICE: {

            break;
        }
    }

}



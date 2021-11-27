#pragma once


#include "Defines/playerafx.h"


#include "Entities/Character.h"
#include "Managers/InputManager.h"

namespace Entities {

    class Player : public Character {
    private:

        class PlayerControl {
            friend class Player;

        private:
            Managers::InputManager* pInputManager;
            std::map<std::string, std::string> controls;
            Entities::Player* player;
        public:
            PlayerControl(Entities::Player* p) {
                pInputManager = Managers::InputManager::getInstance();
                if (p)
                    player = p;
                if (player->getId() == Id::player1) {
                    controls["left"] = PLAYER1_LEFT;
                    controls["right"] = PLAYER1_RIGHT;
                    controls["jump"] = PLAYER1_JUMP;
                    controls["attack"] = PLAYER1_ATTACK;
                } else {
                    controls["left"] = PLAYER2_LEFT;
                    controls["right"] = PLAYER2_RIGHT;
                    controls["jump"] = PLAYER2_JUMP;
                    controls["attack"] = PLAYER2_ATTACK;
                }
            }

            ~PlayerControl() {
                pInputManager = NULL;
            }


            void notify() {
                player->setIsWalking(true);

                //Is walking?
                if (pInputManager->isKeyDown(controls.at("left")) || pInputManager->isKeyDown(controls.at("right"))) {
                    if (pInputManager->isKeyDown(controls.at("left")))
                        player->walk(true);
                    else
                        player->walk(false);
                } else
                    player->setIsWalking(false);

                //Jump
                if (pInputManager->wasKeyPressed(controls.at("jump")))
                    player->jump();

                if (pInputManager->wasKeyPressed(controls.at("attack")))
                    player->setIsAttacking(true);
            }

        };

    private:
        PlayerControl* playerControl;
        bool isPlayerOne;

    public:
        Player(bool isPlayerOne = true);

        ~Player();

        void walk(bool left);

        void jump();

        void attack(Character* pChar) override;

        void initializeSprite();

        void update(float dt) override;

        void saveEntity(std::ofstream& out) const;

        void reset();
    };

}
#pragma once

class Id {
public:
    enum ids {
        null = 0,

        player1 = 1,
        player2 = 2,
        smoker = 10,
        dog = 20,
        punk = 30,

        smoke = 88,
        projectile = 99,

        tile1 = 100,
        tile2 = 200,
        oilTile = 300,
        fire = 400,
        barrel = 500,
        sign = 600,


        background1 = 1000,
        background2 = 2000,
        menuBackground = 3000,
        button = 4000,
    };

    Id::ids enumOfIndex(int i) {
        ids castEnum = static_cast<ids>(i);
        return castEnum;
    }
};

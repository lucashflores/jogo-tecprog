#pragma once

class Id {
public:
    enum ids {
        null = 0,
        player1 = 1,
        player2 = 2,
        enemy1 = 10,
        enemy2 = 20,
        enemy3 = 30,
        tile1Bottom = 100,
        tile1BottomCornerLeft = 101,
        tile1BottomCornerRight = 102,
        tile1Top = 103,
        tile1TopCornerLeft = 104,
        tile1TopCornerRight = 105,
        tile1WallLeft = 106,
        tile1WallRight = 107,
        tile1Background = 108,
        tile2Bottom = 200,
        tile2BottomCornerLeft = 201,
        tile2BottomCornerRight = 202,
        tile2Top = 203,
        tile2TopCornerLeft = 204,
        tile2TopCornerRight = 205,
        tile2WallLeft = 206,
        tile2WallRight = 207,
        tile2Background = 208,
        oilTile = 300,
        fire = 400,
        barrel = 500,
        sign = 600,
        background1 = 1000,
        background2 = 2000,
    };
};

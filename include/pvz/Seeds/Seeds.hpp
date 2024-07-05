#ifndef SEEDS_HPP__
#define SEEDS_HPP__

#include <memory>
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/utils.hpp"


class Seed : public GameObject {
public:
    Seed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int price, int cd, pGameWorld game_world)
        : GameObject(imageID, x, y, layer, width, height, animID), m_price(price), m_cd(cd), m_GameWorld(game_world) {}

    int GetType() {return SEED;}
    void Update() {}

protected:
    int m_price;
    int m_cd;
    pGameWorld m_GameWorld;
};

class SunflowerSeed : public Seed {
public:
    SunflowerSeed(pGameWorld game_world)
        : Seed(IMGID_SEED_SUNFLOWER, 130, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 50, 240, game_world) {}
    void Click();
};

class PeashooterSeed : public Seed {
public:
    PeashooterSeed(pGameWorld game_world)
        : Seed(IMGID_SEED_PEASHOOTER, 130 + SEED_WIDTH, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 100, 240, game_world) {}
    void Click();
};

class WallnutSeed : public Seed {
public:
    WallnutSeed(pGameWorld game_world)
        : Seed(IMGID_SEED_WALLNUT, 130 + SEED_WIDTH * 2, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 50, 900, game_world) {}
    void Click();
};

class CherryBombSeed : public Seed {
public:
    CherryBombSeed(pGameWorld game_world)
        : Seed(IMGID_SEED_CHERRY_BOMB, 130 + SEED_WIDTH * 3, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 150, 1200, game_world) {}
    void Click();
};

class RepeaterSeed : public Seed {
public:
    RepeaterSeed(pGameWorld game_world)
        : Seed(IMGID_SEED_REPEATER, 130 + SEED_WIDTH * 4, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, 200, 240, game_world) {}
    void Click();
};

class Shovel : public Seed {
public:
    Shovel(pGameWorld game_world)
        : Seed(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, 0, 0, game_world) {}
    void Click();
};

#endif // SEEDS_HPP__

#ifndef PLANTS_HPP__
#define PLANTS_HPP__

#include <memory>
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/utils.hpp"

class Plant : public GameObject {
public:
    Plant(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld game_world, int cd)
        : GameObject(imageID, x, y, layer, width, height, animID), m_GameWorld(std::move(game_world)), m_cd(cd) {}

    int GetType() override {return PLANT;}

    void Click() override;
    void hit() {SetHp(GetHp() - 3);}

protected:
    pGameWorld m_GameWorld;
    int m_cd;
};

class Sunflower : public Plant {
public:
    Sunflower(int x, int y, pGameWorld game_world)
        : Plant(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, std::move(game_world), randInt(30, 600)) {SetHp(300);}

    void Update() override;
};

class Peashooter : public Plant {
public:
    Peashooter(int x, int y, pGameWorld game_world)
        : Plant(IMGID_PEASHOOTER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, std::move(game_world), 0) {SetHp(300);}

    void Update() override;
};

class Wallnut : public Plant {
public:
    Wallnut(int x, int y, pGameWorld game_world)
        : Plant(IMGID_WALLNUT, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, std::move(game_world), 0) {SetHp(4000);}

    void Update() override;
};

class CherryBomb : public Plant {
public:
    CherryBomb(int x, int y, pGameWorld game_world)
        : Plant(IMGID_CHERRY_BOMB, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, std::move(game_world), 15) {
        SetHp(4000);
    }

    void Update() override;
};

class Repeater : public Plant {
public:
    Repeater(int x, int y, pGameWorld game_world)
        : Plant(IMGID_REPEATER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, std::move(game_world), 0) {SetHp(300);}

    void Update() override;
};

#endif // PLANTS_HPP__

#ifndef ENVIRONMENT_HPP__
#define ENVIRONMENT_HPP__

#include "pvz/GameObject/GameObject.hpp"
#include "pvz/utils.hpp"

#include <memory>

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class Background : public GameObject {
public:
    Background()
        : GameObject(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION) {}

    void Click() override {}
    void Update() override {}
    int GetType() override {return ENVIRONMENT;}
};

class PlantingSpot : public GameObject {
public:
    PlantingSpot(int x, int y, pGameWorld game_world)
        : GameObject(IMGID_NONE, x, y, LAYER_UI, 60, 80, ANIMID_NO_ANIMATION), m_GameWorld(std::move(game_world)) {}

    void Click() override;
    void Update() override {}
    int GetType() override {return ENVIRONMENT;}

private:
    pGameWorld m_GameWorld;
};

class Sun : public GameObject {
public:
    Sun(int x, int y, bool isFromSky, pGameWorld game_world)
        : GameObject(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM), m_isFromSky(isFromSky), m_GameWorld(std::move(game_world)) {
        m_falltime = isFromSky ? randInt(63, 263) : 12;
    }

    void Click() override;
    void Update() override;
    int GetType() override {return ENVIRONMENT;}

private:
    int m_falltime;
    bool m_isFromSky;
    pGameWorld m_GameWorld;
};

class CooldownMask : public GameObject {
public:
    CooldownMask(int x, int y, int cdtime)
        : GameObject(IMGID_COOLDOWN_MASK, x, y, LAYER_COOLDOWN_MASK, 50, 70, ANIMID_NO_ANIMATION) {
        SetHp(cdtime);
    }

    void Click() {}
    void Update() {SetHp(GetHp() - 1);}
    int GetType() {return -1;}
};

#endif // ENVIRONMENT_HPP__

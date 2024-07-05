#ifndef PROJECTILE_HPP__
#define PROJECTILE_HPP__

#include <memory>
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/utils.hpp"

class Projectile : public GameObject {
public:
    Projectile(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
        : GameObject(imageID, x, y, layer, width, height, animID), m_damage(0), m_GameWorld(nullptr) {}

    int GetType() override {return PROJECTILE;}
    void Click() override {}
    int GetDamage() override {return m_damage;}

protected:
    int m_damage;
    pGameWorld m_GameWorld;
};

class Pea : public Projectile {
public:
    Pea(int x, int y, pGameWorld game_world)
        : Projectile(IMGID_PEA, x, y, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION) {m_damage = 20; m_GameWorld = std::move(game_world);}

    void Update() override;
    void hit() override {SetHp(0);}
};

class Explosion : public Projectile {
public:
    Explosion(int x, int y, pGameWorld game_world)
        : Projectile(IMGID_EXPLOSION, x, y, LAYER_PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION),
          m_cd(3) {m_damage = 2000; m_GameWorld = std::move(game_world);}

    void Update() override;
    void hit() override {}

private:
    int m_cd = 3;
};



#endif // PROJECTILE_HPP__

#ifndef ZOMBIES_HPP__
#define ZOMBIES_HPP__

#include <memory>
#include "pvz/GameObject/GameObject.hpp"

class Zombie : public GameObject {
public:
    Zombie(int x, int y, pGameWorld game_world, AnimID animID)
        : GameObject(IMGID_REGULAR_ZOMBIE, x, y, LAYER_ZOMBIES, 20, 80, animID), m_GameWorld(game_world) {}

    int GetType() override {return ZOMBIE;}
    void Click() {}
    void Update() {}
    void hit() {status = ZombieStatus::EAT;}
    void hit(int damage) {SetHp(GetHp() - damage);}
    void ZombieWalk() {status = ZombieStatus::WALK;}
    
protected:
    pGameWorld m_GameWorld;
    ZombieStatus status = ZombieStatus::WALK;
};

class RegularZombie : public Zombie {
public:
    RegularZombie(int x, int y, pGameWorld game_world)
        : Zombie(x, y, game_world, ANIMID_WALK_ANIM) {SetHp(200);}
    
    void Update() override;
};

class BucketHeadZombie : public Zombie {
public:
    BucketHeadZombie(int x, int y, pGameWorld game_world)
        : Zombie(x, y, game_world, ANIMID_WALK_ANIM) {
        SetHp(1300);
        ChangeImage(IMGID_BUCKET_HEAD_ZOMBIE);
    }

    void Update() override;
};

class PoleVaultingZombie : public Zombie {
public:
    PoleVaultingZombie(int x, int y, pGameWorld game_world)
        : Zombie(x, y, game_world, ANIMID_RUN_ANIM), m_cd(-1) {
        SetHp(340);
        ChangeImage(IMGID_POLE_VAULTING_ZOMBIE);
    }

    void Update() override;
    void ready() {m_cd = 42;}

private:
    int m_cd;
};

#endif // !ZOMBIES_HPP__

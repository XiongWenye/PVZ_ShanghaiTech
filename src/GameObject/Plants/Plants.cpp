#include "pvz/Plants/Plants.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/Environment/Environment.hpp"
#include "pvz/Projectile/Projectile.hpp"
#include "pvz/utils.hpp"

void Plant::Click() {
    if (m_GameWorld->GetHand() == SHOVEL) {
        SetHp(0);
        m_GameWorld->SetHand(NOTHING);
    }
}

void Sunflower::Update() {
    if (GetHp() == 0) return;
    if (m_cd <= 0) {
        m_GameWorld->addGameobj(std::make_shared<Sun>(GetX(), GetY(), 0, m_GameWorld));
        m_cd = 600;
    }
    m_cd--;
}

void Peashooter::Update() {
    if (GetHp() == 0) return;
    if (m_cd <= 0 && m_GameWorld->DetectZombie(shared_from_this())) {
        m_GameWorld->addGameobj(std::make_shared<Pea>(GetX() + 30, GetY() + 20, m_GameWorld));
        m_cd = 30;
    }
    m_cd--;
}

void Repeater::Update() {
    if (GetHp() == 0) return;
    if (m_cd <= 0 && m_GameWorld->DetectZombie(shared_from_this())) {
        m_GameWorld->addGameobj(std::make_shared<Pea>(GetX() + 30, GetY() + 20, m_GameWorld));
        m_cd = 30;
    }
    if (m_cd == 25 && m_GameWorld->DetectZombie(shared_from_this())) {
        m_GameWorld->addGameobj(std::make_shared<Pea>(GetX() + 30, GetY() + 20, m_GameWorld));
    }
    m_cd--;
}

void Wallnut::Update() {
    if (GetHp() == 0) return;
    if (GetHp() < 4000 / 3) {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}

void CherryBomb::Update()
{
    if (GetHp() == 0) return;
    if (m_cd == 0) {
        m_GameWorld->addGameobj(std::make_shared<Explosion>(GetX(), GetY(), m_GameWorld));
        SetHp(0);
    }
    m_cd--;
}
#include "pvz/Seeds/Seeds.hpp"
#include "pvz/utils.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/Plants/Plants.hpp"



void SunflowerSeed::Click() {
    if (m_GameWorld->GetHand() != NOTHING) return;
    if (m_GameWorld->GetSun() < m_price) return;

    m_GameWorld->SubSun(m_price);
    m_GameWorld->SetHand(SUNFLOWERSEED);
    m_GameWorld->coolingdown(GetX(), GetY(), m_cd);
}

void PeashooterSeed::Click() {
    if (m_GameWorld->GetHand() != NOTHING) return;
    if (m_GameWorld->GetSun() < m_price) return;

    m_GameWorld->SubSun(m_price);
    m_GameWorld->SetHand(PEASHOOTERSEED);
    m_GameWorld->coolingdown(GetX(), GetY(), m_cd);
}

void WallnutSeed::Click() {
    if (m_GameWorld->GetHand() != NOTHING) return;
    if (m_GameWorld->GetSun() < m_price) return;

    m_GameWorld->SubSun(m_price);
    m_GameWorld->SetHand(WALLNUTSEED);
    m_GameWorld->coolingdown(GetX(), GetY(), m_cd);
}

void CherryBombSeed::Click() {
    if (m_GameWorld->GetHand() != NOTHING) return;
    if (m_GameWorld->GetSun() < m_price) return;

    m_GameWorld->SubSun(m_price);
    m_GameWorld->SetHand(CHERRYBOMBSEED);
    m_GameWorld->coolingdown(GetX(), GetY(), m_cd);
}

void RepeaterSeed::Click() {
    if (m_GameWorld->GetHand() != NOTHING) return;
    if (m_GameWorld->GetSun() < m_price) return;

    m_GameWorld->SubSun(m_price);
    m_GameWorld->SetHand(REPEATERSEED);
    m_GameWorld->coolingdown(GetX(), GetY(), m_cd);
}

void Shovel::Click() {
    if (m_GameWorld->GetHand() == SHOVEL) {
        m_GameWorld->SetHand(NOTHING);
        return;
    }
    else if (m_GameWorld->GetHand() == NOTHING) {
        m_GameWorld->SetHand(SHOVEL);
        return;
    }
    else {
        return;
    }
}




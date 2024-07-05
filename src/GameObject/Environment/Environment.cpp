#include "pvz/Environment/Environment.hpp"
#include "pvz/utils.hpp"
#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/Plants/Plants.hpp"
#include <map>
#include <functional>

void Sun::Click() {
    m_GameWorld->SetSun(m_GameWorld->GetSun() + 25);
    SetHp(0);
}

void Sun::Update() {
    if (m_falltime > 0) {
        if (m_isFromSky) MoveTo(GetX(), GetY() - 2);
        else MoveTo(GetX() - 1, GetY() + 4 - (12 - m_falltime));
    }
    if (m_falltime < -300) SetHp(0);
    m_falltime--;
}

void PlantingSpot::Click() {
    std::map<Type, std::function<void()>> actions = {
        { SUNFLOWERSEED, [this]() {
            m_GameWorld->addGameobj(std::make_shared<Sunflower>(GetX(), GetY(), m_GameWorld));
            m_GameWorld->SetHand(NOTHING);
        }},
        { PEASHOOTERSEED, [this]() {
            m_GameWorld->addGameobj(std::make_shared<Peashooter>(GetX(), GetY(), m_GameWorld));
            m_GameWorld->SetHand(NOTHING);
        }},
        { WALLNUTSEED, [this]() {
            m_GameWorld->addGameobj(std::make_shared<Wallnut>(GetX(), GetY(), m_GameWorld));
            m_GameWorld->SetHand(NOTHING);
        }},
        { CHERRYBOMBSEED, [this]() {
            m_GameWorld->addGameobj(std::make_shared<CherryBomb>(GetX(), GetY(), m_GameWorld));
            m_GameWorld->SetHand(NOTHING);
        }},
        { REPEATERSEED, [this]() {
            m_GameWorld->addGameobj(std::make_shared<Repeater>(GetX(), GetY(), m_GameWorld));
            m_GameWorld->SetHand(NOTHING);
        }}
    };

    Type hand = m_GameWorld->GetHand();
    if (actions.find(hand) != actions.end()) {
        actions[hand]();
    }
}

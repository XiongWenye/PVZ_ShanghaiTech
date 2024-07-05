#include "pvz/Projectile/Projectile.hpp"

void Pea::Update() {
    if (GetHp() == 0) return;
    MoveTo(GetX() + 8, GetY());
    if (GetX() >= WINDOW_WIDTH) {
        SetHp(0);
    }
}

void Explosion::Update() {
    if (GetHp() == 0) return;
    if (m_cd == 0) SetHp(0);
    m_cd--;
}
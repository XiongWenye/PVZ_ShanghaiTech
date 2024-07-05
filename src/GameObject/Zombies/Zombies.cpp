#include "pvz/Zombies/Zombies.hpp"
#include "pvz/GameWorld/GameWorld.hpp"

void RegularZombie::Update() {
    if (GetHp() == 0) return;
    if ((status == ZombieStatus::EAT && GetCurrentAnimation() == ANIMID_WALK_ANIM) || (status == ZombieStatus::WALK && GetCurrentAnimation() == ANIMID_EAT_ANIM))
        PlayAnimation(abs(3-GetCurrentAnimation()));
    if (GetCurrentAnimation() == ANIMID_WALK_ANIM) MoveTo(GetX() - 1, GetY());
}

void BucketHeadZombie::Update()
{
    if (GetHp() == 0) return;
    if ((status == ZombieStatus::EAT && GetCurrentAnimation() == ANIMID_WALK_ANIM) || (status == ZombieStatus::WALK && GetCurrentAnimation() == ANIMID_EAT_ANIM))
        PlayAnimation(abs(3-GetCurrentAnimation()));
    if (GetCurrentAnimation() == ANIMID_WALK_ANIM) MoveTo(GetX() - 1, GetY());
    if (GetHp() <= 200) ChangeImage(IMGID_REGULAR_ZOMBIE);
}

void PoleVaultingZombie::Update()
{
    if (GetHp() == 0) return;
    if ((status == ZombieStatus::EAT && GetCurrentAnimation() == ANIMID_WALK_ANIM) || (status == ZombieStatus::WALK && GetCurrentAnimation() == ANIMID_EAT_ANIM))
        PlayAnimation(abs(3-GetCurrentAnimation()));
    if (GetCurrentAnimation() == ANIMID_RUN_ANIM) MoveTo(GetX() - 2, GetY());
    if (m_cd == -1) {
        MoveTo(GetX() - 40, GetY());
        m_GameWorld->PVcheck(shared_from_this());
        MoveTo(GetX() + 40, GetY());
    }
    else if (m_cd > 0) m_cd -= 1;
    else if (m_cd == 0) {
        MoveTo(GetX() - 150, GetY());
        PlayAnimation(ANIMID_WALK_ANIM);
        m_cd = -2;
    }

    if (GetCurrentAnimation() == ANIMID_WALK_ANIM) MoveTo(GetX() - 1, GetY());
}
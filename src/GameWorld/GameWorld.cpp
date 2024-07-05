#include "pvz/GameWorld/GameWorld.hpp"
#include "pvz/Environment/Environment.hpp"
#include "pvz/GameObject/GameObject.hpp"
#include "pvz/Plants/Plants.hpp"
#include "pvz/Seeds/Seeds.hpp"
#include "pvz/Zombies/Zombies.hpp"
#include "pvz/Framework/TextBase.hpp"
#include <algorithm>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
    SetWave(0);
    SetSun(50);
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j) {
            addGameobj(std::make_shared<PlantingSpot>(
                FIRST_COL_CENTER + j * LAWN_GRID_WIDTH,
                FIRST_ROW_CENTER + i * LAWN_GRID_HEIGHT,
                shared_from_this()
            ));
        }
    }

    addGameobj(std::make_shared<Background>());
    addGameobj(std::make_shared<SunflowerSeed>(shared_from_this()));
    addGameobj(std::make_shared<PeashooterSeed>(shared_from_this()));
    addGameobj(std::make_shared<WallnutSeed>(shared_from_this()));
    addGameobj(std::make_shared<CherryBombSeed>(shared_from_this()));
    addGameobj(std::make_shared<RepeaterSeed>(shared_from_this()));
    addGameobj(std::make_shared<Shovel>(shared_from_this()));

    m_sun_text = std::make_shared<TextBase>(60, 520, std::to_string(m_sun));
    m_wave_text = nullptr;
    dawn = randInt(0, 250);
}

inline void GameWorld::UpdateObjects() {
    for (auto &object : m_GameObject) {
        object->Update();
    }
    m_sun_text = std::make_shared<TextBase>(60, 520, std::to_string(m_sun));
}

inline void GameWorld::Mambaout() {
    m_GameObject.erase(
        std::remove_if(m_GameObject.begin(), m_GameObject.end(),
            [](const auto& obj) {return obj->GetHp() <= 0;}),
        m_GameObject.end());
}


inline void GameWorld::ZombieComing() {
    if (m_nextwave == 0) {
        SetWave(GetWave() + 1);
        m_zombie = (15 + GetWave()) / 10;
        m_nextwave = std::max(150, 600 - 20 * GetWave());
    } else {
        m_nextwave--;
    }
    
    if (m_zombie > 0) {
        int P1 = 20;
        int P2 = 2 * std::max(GetWave() - 8, 0);
        int P3 = 3 * std::max(GetWave() - 15, 0);

        while (m_zombie) {
            int P0 = randInt(0, P1 + P2 + P3);
            if (P0 <= P1) {
                addGameobj(std::make_shared<RegularZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0,4) * LAWN_GRID_HEIGHT, shared_from_this()));
            } else if (P0 <= P1 + P2) {
                addGameobj(std::make_shared<PoleVaultingZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0,4) * LAWN_GRID_HEIGHT, shared_from_this()));
            } else {
                addGameobj(std::make_shared<BucketHeadZombie>(randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), FIRST_ROW_CENTER + randInt(0,4) * LAWN_GRID_HEIGHT, shared_from_this()));
            }

            m_zombie--;
        }
    }
}

void GameWorld::CleanUp() {
    m_GameObject.clear();
    m_hand = 0;
    m_time = 0;
    m_nextwave = 1200;
    m_zombie = 0;
    m_wave_text = nullptr;
}

void GameWorld::coolingdown(int x, int y, int cd) {
    addGameobj(std::make_shared<CooldownMask>(x, y, cd));
}

void GameWorld::PVcheck(pGameObject &&PVZ) {
    for (auto &plant : m_GameObject) {
        if (plant->GetType() == PLANT && CheckCollision(plant, PVZ)) {
            PVZ->PlayAnimation(ANIMID_JUMP_ANIM);
            PVZ->ready();
            return;
        }
    }
}

bool GameWorld::DetectZombie(pGameObject &&obj) {
    for (auto &zombie : m_GameObject) {
        if (zombie->GetType() == ZOMBIE && zombie->GetY() == obj->GetY() && zombie->GetX() > obj->GetX()) {
            return true;
        }
    }
    return false;
}


bool GameWorld::CheckCollision(const pGameObject &obj1, const pGameObject &obj2) {
  int obj1_x1 = obj1->GetX() + obj1->GetWidth() / 2;
  int obj1_x2 = obj1->GetX() - obj1->GetWidth() / 2;
  int obj1_y1 = obj1->GetY() + obj1->GetHeight() / 2;
  int obj1_y2 = obj1->GetY() - obj1->GetHeight() / 2;

  int obj2_x1 = obj2->GetX() + obj2->GetWidth() / 2;
  int obj2_x2 = obj2->GetX() - obj2->GetWidth() / 2;
  int obj2_y1 = obj2->GetY() + obj2->GetHeight() / 2;
  int obj2_y2 = obj2->GetY() - obj2->GetHeight() / 2;

  return obj1_x1 > obj2_x2 && obj1_x2 < obj2_x1 && obj1_y1 > obj2_y2 && obj1_y2 < obj2_y1;
}

LevelStatus GameWorld::Update() {
    m_time++;
    if ((m_time - dawn) % 300 == 0) {
        addGameobj(std::make_shared<Sun>(randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, 1, shared_from_this()));
    }
    
    ZombieComing();
    UpdateObjects();
    static int ZombieWalk = 1;
    for (auto &zombie : m_GameObject) {
        if (zombie->GetType() == ZOMBIE) {
            for (auto &projectile : m_GameObject) {
                if (projectile->GetType() == PROJECTILE) {
                    if (CheckCollision(projectile, zombie)) {
                        projectile->hit();
                        zombie->hit(projectile->GetDamage());
                    }
                }
            }

            for (auto &plant : m_GameObject) {
                if (plant->GetType() == PLANT) {
                    if (CheckCollision(plant, zombie)) {
                        plant->hit();
                        zombie->hit();
                        break;
                    }
                }
            }

            if (zombie->GetCurrentAnimation() == ANIMID_EAT_ANIM) {
                ZombieWalk = 1;
                for (auto &plant : m_GameObject) {
                    if (plant->GetType() == PLANT && CheckCollision(plant, zombie)) {
                        ZombieWalk = 0;
                        break;
                    }
                }
                if (ZombieWalk) zombie->ZombieWalk();
            }
        }
    }
    Mambaout();
    m_sun_text = std::make_shared<TextBase>(60, 520, std::to_string(m_sun));
    return CheckGameStatus();
}

LevelStatus GameWorld::CheckGameStatus() {
    for (auto &zombie : m_GameObject) {
        if (zombie->GetType() == ZOMBIE) {
            if (zombie->GetX() < 0) {
                m_wave_text = std::make_shared<TextBase>(330, 50, std::to_string(m_wave - 1), 1, 1, 1);
                return LevelStatus::LOSING;
            }
            
        }
    }
    return LevelStatus::ONGOING;
}


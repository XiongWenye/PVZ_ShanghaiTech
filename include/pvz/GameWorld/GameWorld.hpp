#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>
#include "pvz/Framework/WorldBase.hpp"
#include "pvz/Framework/TextBase.hpp"
#include "pvz/utils.hpp"

class GameObject;
using pGameObject = std::shared_ptr<GameObject>;

class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
    GameWorld();
    virtual ~GameWorld();

    void Init() override;
    LevelStatus Update() override;
    void CleanUp() override;

    inline void addGameobj(pGameObject object) {m_GameObject.push_back(std::move(object));}
    inline void UpdateObjects();

    inline int GetHand() const {return m_hand;}
    inline void SetHand(int hand) {m_hand = hand;}

    inline int GetSun() const {return m_sun;}
    inline void SetSun(int sun) {m_sun = sun;}
    inline void AddSun(int sun) {m_sun += sun;}
    inline void SubSun(int sun) {m_sun -= sun;}

    inline int GetWave() const {return m_wave;}
    inline void SetWave(int wave) {m_wave = wave;}

    void coolingdown(int x, int y, int cdtime);
    inline void Mambaout();
    inline void ZombieComing();
    bool DetectZombie(pGameObject &&obj);
    void PVcheck(pGameObject &&zombie);
    bool CheckCollision(const pGameObject &obj1, const pGameObject &obj2);
    LevelStatus CheckGameStatus();

private:
    std::list<pGameObject> m_GameObject;
    int m_hand = 0;
    int m_time = 0;
    int m_nextwave = 1200;
    int m_zombie = 0;
    int m_sun = 50;
    int m_wave = 0;
    std::shared_ptr<TextBase> m_sun_text;
    std::shared_ptr<TextBase> m_wave_text;
};

#endif // GAMEWORLD_HPP__

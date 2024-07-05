#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "pvz/Framework/ObjectBase.hpp"
#include "pvz/utils.hpp"

class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
    using std::enable_shared_from_this<GameObject>::shared_from_this; // Use shared_from_this() instead of "this".

    GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID)
        : ObjectBase(imageID, x, y, layer, width, height, animID), m_hp(1) {}

    GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int hp)
        : ObjectBase(imageID, x, y, layer, width, height, animID), m_hp(hp) {}

    void SetHp(int hp) {m_hp = hp;}

    int GetHp() const {return m_hp;}

    virtual int GetType() = 0;
    virtual void hit() {}
    virtual void hit(int) {}
    virtual void ZombieWalk() {}
    virtual int GetDamage() {return 0;}
    virtual void ready() {}

protected:
    int m_hp;
};

#endif // GAMEOBJECT_HPP__

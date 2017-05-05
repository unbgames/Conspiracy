#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "player.hpp"

using namespace engine;

class GameScene: public Scene{
public:
    GameScene(int id): Scene::Scene(id){}
    ~GameScene();
    void load();
    void draw();
    void update(int timeElapsed);
    void init();
    void unload();
private:
    Player* player;
};
#endif

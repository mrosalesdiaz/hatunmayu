#include "GarageScene.h"

#include "../../commons/Resources.h"
#include "../LobbyScene/LobbyScene.h"
#include "commons/DevelopmentUtils.h"

USING_NS_CC;

bool GarageScene::init() {
  if (!Scene::init()) {
    return false;
  }

  DEV_LABEL("Garage Scene");

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;
  BTN_REPLACE_SCENE(testButton, LobbyScene, Back Lobby Scene)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y - 60));

  return true;
}

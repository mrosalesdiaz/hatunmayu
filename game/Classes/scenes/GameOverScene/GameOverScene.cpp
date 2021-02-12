#include "GameOverScene.h"

#include "../../commons/DevelopmentUtils.h"
#include "../../commons/Resources.h"
#include "../LobbyScene/LobbyScene.h"

USING_NS_CC;

bool GameOverScene::init() {
  if (!Scene::init()) {
    return false;
  }

  DEV_LABEL("GameOver Scene");

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  BTN_REPLACE_SCENE(testButton, LobbyScene, Back to Lobby)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y));

  return true;
}

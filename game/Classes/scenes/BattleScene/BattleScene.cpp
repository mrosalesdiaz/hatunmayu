
#include "BattleScene.h"

#include "../../commons/Resources.h"
#include "../GameScene/GameScene.h"
#include "../TravelScene/TravelScene.h"
#include "commons/DevelopmentUtils.h"

USING_NS_CC;

bool BattleScene::init() {
  if (!Scene::init()) {
    return false;
  }

  DEV_LABEL("Battle Scene");

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  BTN_REPLACE_SCENE(testButton, GameScene, Back Game Scene)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y));

  BTN_REPLACE_SCENE(testButton3, TravelScene, Flee got to travel scene)
  testButton3->setPosition(Vec2(centerVec.x, centerVec.y - 60));

  return true;
}

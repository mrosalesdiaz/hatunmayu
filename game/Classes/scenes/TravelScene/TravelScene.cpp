#include "TravelScene.h"

#include "../../commons/Resources.h"
#include "../BattleScene/BattleScene.h"
#include "../GameScene/GameScene.h"
#include "../RepairStationScene/RepairStationScene.h"
#include "commons/DevelopmentUtils.h"

USING_NS_CC;

bool TravelScene::init() {
  if (!Scene::init()) {
    return false;
  }

  DEV_LABEL("TravelScene Scene");

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  BTN_REPLACE_SCENE(testButton, GameScene, Back to game scene)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y));

  BTN_REPLACE_SCENE(testButton2, RepairStationScene, Travel to repair station)
  testButton2->setPosition(Vec2(centerVec.x, centerVec.y - 60));

  BTN_REPLACE_SCENE(testButton3, BattleScene, Interrump by a battle)
  testButton3->setPosition(Vec2(centerVec.x, centerVec.y - 120));

  return true;
}

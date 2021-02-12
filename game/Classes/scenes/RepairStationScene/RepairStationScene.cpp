#include "RepairStationScene.h"

#include "../../commons/Resources.h"
#include "../TravelScene/TravelScene.h"
#include "commons/DevelopmentUtils.h"

USING_NS_CC;

bool RepairStationScene::init() {
  if (!Scene::init()) {
    return false;
  }

  DEV_LABEL("Repair Station Scene");

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  BTN_REPLACE_SCENE(testButton, TravelScene, Back to travel scene)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y - 30));

  return true;
}

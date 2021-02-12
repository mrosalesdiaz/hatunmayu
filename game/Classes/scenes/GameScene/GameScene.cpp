#include "GameScene.h"

#include "../../commons/Resources.h"
#include "../BattleScene/BattleScene.h"
#include "../GameOverScene/GameOverScene.h"
#include "../TravelScene/TravelScene.h"
#include "commons/DevelopmentUtils.h"

USING_NS_CC;

bool GameScene::init() {
  if (!Scene::init()) {
    return false;
  }

  DEV_LABEL("Game Scene");

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  BTN_REPLACE_SCENE(testButton, TravelScene, Travel Scence)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y));

  BTN_REPLACE_SCENE(testButton2, BattleScene, Battle Scene)
  testButton2->setPosition(Vec2(centerVec.x, centerVec.y - 60));

  BTN_REPLACE_SCENE(testButton3, GameOverScene, Game Over Scene)
  testButton3->setPosition(Vec2(centerVec.x, centerVec.y - 120));

  return true;
}

#include "LobbyScene.h"

#include "../../commons/DevelopmentUtils.h"
#include "../../commons/Resources.h"
#include "../GameScene/GameScene.h"
#include "../GarageScene/GarageScene.h"
#include "../TrainingScene/TrainingScene.h"


USING_NS_CC;

bool LobbyScene::init() {
  if (!Scene::init()) {
    return false;
  }

  // Reload resources
  auto spritecache = SpriteFrameCache::getInstance();
  spritecache->removeSpriteFrames();
  spritecache->addSpriteFramesWithFile(RES_BASIC_UI_PLIST);
  spritecache->addSpriteFramesWithFile(TEXTURE_SCENE_LOBBY_PLIST);

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  auto sceneBackgroung =
      Sprite::createWithSpriteFrameName("scene-background.png");
  sceneBackgroung->setPosition(centerVec);
  this->addChild(sceneBackgroung);

  DEV_LABEL("Lobby Scene");

  BTN_REPLACE_SCENE(testButton, TrainingScene, Training)
  testButton->setPosition(Vec2(centerVec.x, centerVec.y - 60));

  BTN_REPLACE_SCENE(testButton2, GarageScene, Garage Scene)
  testButton2->setPosition(Vec2(centerVec.x, centerVec.y - 120));

  BTN_REPLACE_SCENE(testButton3, GameScene, Game Scene)
  testButton3->setPosition(Vec2(centerVec.x, centerVec.y - 180));

  PlayerSlot* playerSlot[9];

  auto origin = Vec2(centerVec);
  for (int i = 0; i < 9; i++) {
    int x = i % 3;
    int y = round(i / 3);
    CCLOG("x:%d y:%d", x, y);

    playerSlot[i] = PlayerSlot::create();

    playerSlot[i]->setPosition(Vec2(origin.x + x * 120, origin.y - 120 * y));

    this->addChild(playerSlot[i]);
  }

    this->initPlayerSlots();
    
  return true;
}

void LobbyScene::initPlayerSlots(){
    for (int i=0; i< this->playerSlots->size();i++) {
        CCLOG("%d",i);
    }
}

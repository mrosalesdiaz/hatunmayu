#include "StartScene.h"

#include "../../commons/DevelopmentUtils.h"
#include "../../commons/ProjectMacros.h"
#include "../../commons/Resources.h"
#include "../LobbyScene/LobbyScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

bool StartScene::init() {
  if (!Scene::init()) {
    return false;
  }
  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  // BTN_REPLACE_SCENE(testButton, LobbyScene, Start game)
  // testButton->setPosition(Vec2(centerVec.x, centerVec.y - 60));

  // DEV_LABEL("Start Scene!!!!");

  // testButton->getVirtualRenderer()->setContentSize(Size(300, 300));

  auto spritecache = SpriteFrameCache::getInstance();
  spritecache->removeSpriteFrames();
  spritecache->addSpriteFramesWithFile(RES_BASIC_UI_PLIST);
  spritecache->addSpriteFramesWithFile(TEXTURE_SCENE_START_PLIST);

  auto backgroundScene =
      Sprite::createWithSpriteFrameName("background-scene.png");
  backgroundScene->setPosition(centerVec);
  this->addChild(backgroundScene);

  auto enterLabel = Label::createWithBMFont(BMFONT_NORMAL, "[ enter ]");
  enterLabel->setPosition(Vec2(centerVec.x, centerVec.y - 60));
  enterLabel->setAnchorPoint(Vec2(.5, .5));
  this->addChild(enterLabel);

  auto listener1 = EventListenerTouchOneByOne::create();

  listener1->onTouchBegan = [](Touch* touch, Event* event) { return true; };
  listener1->onTouchMoved = [](Touch* touch, Event* event) {};
  listener1->onTouchEnded = [=](Touch* touch, Event* event) {
    auto lobbyScene = LobbyScene::create();
    Director::getInstance()->replaceScene(lobbyScene);
  };

  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1,
                                                           enterLabel);

  // testButton->addChild(gameTitle);

  return true;
}

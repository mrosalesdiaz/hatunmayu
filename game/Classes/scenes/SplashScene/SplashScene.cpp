#include "SplashScene.h"

#include "../../commons/Resources.h"
#include "../StartScene/StartScene.h"
#include "commons/DevelopmentUtils.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

namespace {

  void initializeSpriteFrameCache() {
    auto spritecache = SpriteFrameCache::getInstance();

    spritecache->addSpriteFramesWithFile(RES_BASIC_UI_PLIST);

    spritecache->addSpriteFramesWithFile(TEXTURE_SCENE_SPLASH_PLIST);
  }

}  // namespace

bool SplashScene::init() {
  if (!Scene::init()) {
    return false;
  }

  initializeSpriteFrameCache();

  auto winSize = Director::getInstance()->getWinSize();
  auto centerVec = Vec2(winSize.width, winSize.height) * 0.5;

  auto bgSprite = Sprite::createWithSpriteFrameName("background-scene.png");
  bgSprite->setPosition(centerVec);
  this->addChild(bgSprite);

  auto loadingPosition = Vec2(30, 30);

  auto labelLoadingDark =
      Sprite::createWithSpriteFrameName("label-loading-dark.png");
  labelLoadingDark->setPosition(loadingPosition);
  labelLoadingDark->setAnchorPoint(Vec2(0, 0));
  this->addChild(labelLoadingDark);

  auto labelLoadingLight =
      Sprite::createWithSpriteFrameName("label-loading-light.png");
  labelLoadingLight->setPosition(loadingPosition);
  labelLoadingLight->setAnchorPoint(Vec2(0, 0));
  this->addChild(labelLoadingLight);
  labelLoadingLight->runAction(RepeatForever::create(
      Sequence::create(FadeOut::create(1.0f), FadeIn::create(1.0f), nullptr)));

  DEV_LABEL("Splash Scene");

  this->scheduleOnce(CC_SCHEDULE_SELECTOR(SplashScene::navigateStartScene),
                     1.0f);

  return true;
}

void SplashScene::navigateStartScene(float dt) {
  auto scene = StartScene::create();

  Director::getInstance()->replaceScene(scene);
}

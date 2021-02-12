#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

class SplashScene : public cocos2d::Scene {
 public:
  virtual bool init();

  void navigateStartScene(float dt);

  CREATE_FUNC(SplashScene);
};

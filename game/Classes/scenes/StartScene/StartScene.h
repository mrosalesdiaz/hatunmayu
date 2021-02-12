#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

class StartScene : public cocos2d::Scene {
 public:
  virtual bool init();

  void click_enterGame(Ref*, Widget::TouchEventType);

  CREATE_FUNC(StartScene);
};

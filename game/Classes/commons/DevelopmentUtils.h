#pragma once
#include "ui/CocosGUI.h"

#define ENABLE_DEV = 1

#define DEV_LABEL(__text__)                                       \
  auto label = Label::create();                                   \
  label->setPosition(                                             \
      Director::getInstance()->getVisibleSize().width / 2,        \
      Director::getInstance()->getVisibleSize().height / 2 + 60); \
  label->setString(__text__);                                     \
  label->setSystemFontSize(60);                                   \
  this->addChild(label);

#define BTN_REPLACE_SCENE(__buttonName__, __sceneName__, __label__)            \
  auto __buttonName__ = ui::Button::create(BASIC_UI_RED_BUTTON, "", "",        \
                                           ui::Widget::TextureResType::PLIST); \
  __buttonName__->setTitleText(#__label__);                                    \
  __buttonName__->addTouchEventListener(                                       \
      [](Ref* ref, ui::Widget::TouchEventType eventType) {                     \
        if (ui::Widget::TouchEventType::ENDED == eventType) {                  \
          return;                                                              \
        }                                                                      \
        auto lobbyScene = __sceneName__::create();                             \
        Director::getInstance()->replaceScene(lobbyScene);                     \
      });                                                                      \
  this->addChild(__buttonName__);

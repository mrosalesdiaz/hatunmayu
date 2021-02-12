#include "PlayerSlot.h"

USING_NS_CC;

bool PlayerSlot::init() {
  if (!Node::init()) {
    return false;
  }

  auto nodeBackground = Sprite::createWithSpriteFrameName("player-slot.png");

  this->addChild(nodeBackground);

  return true;
}

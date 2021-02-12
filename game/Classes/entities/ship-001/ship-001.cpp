#include "ship-001.h"

#include "../../commons/Resources.h"

USING_NS_CC;

bool Ship001::init() {
  if (!Node::init()) {
    return false;
  }

  auto sprite = Sprite::create(RES_ENTITIES_SHIP001);

  sprite->setPosition(Vec2(200, 200));

  this->addChild(sprite);

  return true;
}

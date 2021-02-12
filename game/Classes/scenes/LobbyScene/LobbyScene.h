#pragma once

#include "array"
#include "cocos2d.h"

#include "PlayerSlot.h"

class LobbyScene : public cocos2d::Scene {

public:
  virtual bool init();
    CREATE_FUNC(LobbyScene);
private:
    std::array<PlayerSlot, 9> * playerSlots;
    void initPlayerSlots();
};

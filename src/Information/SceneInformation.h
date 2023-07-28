#pragma once
#ifndef __SCENEINFORMATION_H__
#define __SCENEINFORMATION_H__

#include "Scene/GameScene/GameScene__1_1/RoomLayer__1_1_1.h"
#include "Scene/GameScene/GameScene__1_1/RoomLayer__1_1_6.h"
#include "Scene/GameScene/GameScene__1_1/HallLayer__1_1_level.h"

std::vector<cocos2d::Layer*> vecLayer;
int nextLayerNumber = 0;
std::string initialLocation;
#endif // !__SCENEINFORMATION_H__
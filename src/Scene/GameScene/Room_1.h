#pragma once
#ifndef __ROOM_1_H__
#define __ROOM_1_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Role/RoleFile.h"

class Room_1 :public BasicScene
{
public:
	virtual bool init();
	virtual void update(float delta);
	CREATE_FUNC(Room_1);
};

#endif // !__ROOM_1_H__
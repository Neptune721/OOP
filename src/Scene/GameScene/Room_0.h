#pragma once
#ifndef __ROOM_0_H__
#define __ROOM_0_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Role/RoleFile.h"

class Room_0 :public BasicScene
{
public:
	virtual bool init();
	virtual void update(float delta);
	CREATE_FUNC(Room_0);
};
#endif // !__ROOM_0_H__
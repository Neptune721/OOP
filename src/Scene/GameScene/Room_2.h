#pragma once
#ifndef __ROOM_2_H__
#define __ROOM_2_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Role/RoleFile.h"

class Room_2 :public BasicScene
{
public:
	virtual bool init();
	virtual void update(float delta);
	CREATE_FUNC(Room_2);
};
#endif // !__ROOM_2_H__
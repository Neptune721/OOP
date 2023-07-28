#pragma once
#ifndef __ROOM_3_H__
#define __ROOM_3_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Role/RoleFile.h"
#include "Scene/GameEndScene/GameWinScene.h"

class Room_3 :public BasicScene
{
public:

	virtual bool init();
	virtual void update(float delta);
	CREATE_FUNC(Room_3);
private:
	cocos2d::Rect rectTransfer;
	cocos2d::Vec2 textPosition;
	cocos2d::Label* label;
};

#endif // !__ROOM_3_H__
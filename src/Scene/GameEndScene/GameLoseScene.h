#pragma once
#ifndef __GAMELOSESCENE_H__
#define __GAMELOSESCENE_H__

#include "cocos2d.h"

class GameLose :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameLose);
};

#endif // !__GAMELOSESCENE_H__

#pragma once
#ifndef __GAMEWINSCENE_H__
#define __GAMEWINSCENE_H__

#include "cocos2d.h"

class GameWin :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameWin);
};

#endif // !__GAMEWINSCENE_H__

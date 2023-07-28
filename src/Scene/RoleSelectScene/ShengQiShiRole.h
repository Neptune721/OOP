#pragma once
#ifndef __SHENGQISHI_ROLE_H__
#define __SHENGQISHI_ROLE_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Scene/GameScene/GameSceneInfo.h"

class ShengQiShiSelected :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(ShengQiShiSelected);
};

#endif // !__SHENGQISHI_ROLE_H_
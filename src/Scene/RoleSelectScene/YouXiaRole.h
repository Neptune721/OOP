#pragma once
#ifndef __YOUXIA_ROLE_H__
#define __YOUXIA_ROLE_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Scene/GameScene/GameSceneInfo.h"

class YouXiaSelected :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(YouXiaSelected);
};

#endif // !__YOUXIA_ROLE_H_
#pragma once
#ifndef __SHOWPRODUCERSINFORMATION_SCENE_H__
#define __SHOWPRODUCERSINFORMATION_SCENE_H__

#include "cocos2d.h"

class ShowProducersInformation :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(ShowProducersInformation);
};

#endif // !__STARTGAME_SCENE_H__

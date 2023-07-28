#pragma once
#ifndef _SUSPENSIONSCENE_H__
#define _SUSPENSIONSCENE_H__

#include "cocos2d.h"
#include "Scene/StartGameScene/SetGameStyleScene.h"
#include "Music/Music.h"

class SuspensionScene :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(SuspensionScene);
};

#endif // !_SUSPENSIONSCENE_H__

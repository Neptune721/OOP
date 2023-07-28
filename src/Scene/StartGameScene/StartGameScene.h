#pragma once
#ifndef __STARTGAMESCENE_H__
#define __STARTGAMESCENE_H__

#include "cocos2d.h"
#include "Music/Music.h"
#include "Scene/GameScene/GameSceneInfo.h"
#include "Scene/StartGameScene/SetGameStyleScene.h"
#include "Scene/StartGameScene/ShowProducerInformationScene.h"
#include "Scene/RoleSelectScene/RoleSelectScene.h"

class StartGame :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(StartGame);
};

#endif // !__STARTGAMESCENE_H__

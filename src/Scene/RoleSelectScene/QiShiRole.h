#pragma once
#ifndef __QISHI_ROLE_H__
#define __QISHI_ROLE_H__

#include "cocos2d.h"
#include "Scene/GameScene/GameSceneFile.h"
#include "Scene/GameScene/GameSceneInfo.h"

class QiShiSelected :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(QiShiSelected);
};


#endif // !__QISHI_ROLE_H_

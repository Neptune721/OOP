#pragma once
#ifndef __ROLESELECT_SCENE_H__
#define __ROLESELECT_SCENE_H__

#include "cocos2d.h"

class RoleSelect :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(RoleSelect);
};

#endif // !__ROLESELECTING_SCENE_H_
#pragma once
#ifndef __ROUNDBULLET_H__
#define __ROUNDBULLET_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"

class RoundBullet :public BasicWeapon
{
public:
	static RoundBullet* create(const std::string& filename);
	cocos2d::Vec2 getMoveVector();//获取每一帧移动的向量
	float getSpeed();
	void setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);
	//virtual bool init();
	//CREATE_FUNC(RoundBullet);
	//createfunc是用以能够create()的时候执行init()函数
	//但此处没有用到create()或init()，而是重写了Sprite的create函数
	//故猜测这地方不用这两行代码
private:
	float _speed = 5.0f;
	cocos2d::Vec2 _moveVector;
};

#endif // !__ROUNDBULLET_H__

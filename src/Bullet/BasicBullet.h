#pragma once
#ifndef __BASICBULLET_H__
#define __BASICBULLET_H__

#include "cocos2d.h"

class BasicBullet : public cocos2d::Sprite
{
public:
	//获取每一帧移动的向量
	cocos2d::Vec2 getMoveVector()const;

	//根据鼠标的落点和人物的初始位置设置子弹每一帧移动的向量
	void setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);

	//三个子弹属性的get函数
	float getSpeed()const;
	int getDamage()const;
	int getBlueComsumption()const;

protected:
	//基类全部不设置初始值，因为基类有纯虚函数，在派生类的initbullet()更新子弹属性
	float _speed;//子弹（武器）速度
	int _damage;//子弹（武器）攻击力
	int _blueComsumption;//子弹（武器）耗蓝量
	cocos2d::Vec2 _moveVector;//每一帧移动的向量
	virtual void initBullet() = 0;//纯虚函数
};

#endif
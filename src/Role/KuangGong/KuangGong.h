#pragma once
#ifndef __KUANGGONG_H__
#define __KUANGGONG_H__

#include "cocos2d.h"
#include "Role/BasicRole.h"
#include "Weapon/CommonWeapon/CommonWeapon.h"

class KuangGong :public BasicRole
{
public:
	static KuangGong* create(const std::string& filename);
	virtual void initRole();

	//获取每一帧移动的向量
	cocos2d::Vec2 getMoveVector()const;

	//根据鼠标的落点和人物的初始位置设置子弹每一帧移动的向量
	void setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);
	virtual void useRoleSkill();
	virtual void stopRoleSkill();
private:
	cocos2d::Vec2 _moveVector;
};

#endif // !__KUANGGONG_H__

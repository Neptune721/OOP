#pragma once
#ifndef __POJIUDESHOUQIANG_H__
#define __POJIUDESHOUQIANG_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"
#include "Bullet/BulletOfPoJiuDeShouQiang.h"

class PoJiuDeShouQiang :public BasicWeapon
{
public:
	static PoJiuDeShouQiang* create(const std::string& filename);
	virtual BasicBullet* createBullet();
protected:
	void initWeapon();
};

#endif // !__POJIUDESHOUQIANG_H__

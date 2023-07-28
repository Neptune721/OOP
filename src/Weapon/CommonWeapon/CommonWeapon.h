#pragma once
#ifndef __COMMONWEAPON_H__
#define __COMMONWEAPON_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"
#include "Bullet/CommonBullet.h"

class CommonWeapon :public BasicWeapon
{
public:
	static CommonWeapon* create(const std::string& filename);
	virtual BasicBullet* createBullet();
protected:
	void initWeapon();
};

#endif // !__COMMONWEAPON_H__

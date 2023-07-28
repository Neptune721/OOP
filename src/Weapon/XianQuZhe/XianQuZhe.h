#pragma once
#ifndef __XIANQUZHE_H__
#define __XIANQUZHE_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"
#include "Bullet/BulletOfXianQuZhe.h"

class XianQuZhe :public BasicWeapon
{
public:
	static XianQuZhe* create(const std::string& filename);
	virtual BasicBullet* createBullet();
protected:
	void initWeapon();
};

#endif // !__XIANQUZHE_H__

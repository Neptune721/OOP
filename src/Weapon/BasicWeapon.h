#pragma once
#include "cocos2d.h"
#include "Bullet/BasicBullet.h"

#ifndef __BASICWEAPON_H__
#define __BASICWEAPON_H__

class BasicWeapon : public cocos2d::Sprite
{
public:
	BasicBullet* getBullet();////得到子弹的类型，要先在派生类中初始化
	virtual BasicBullet* createBullet() = 0;
	float getBulletSpeed()const;
	int getBulletDamage()const;
	int getBlueConsumption()const;
protected:
	BasicBullet* _bullet;//武器的子弹
	float _bulletSpeed;//子弹速度
	int _bulletDamage;//子弹伤害
	int _blueConsumption;//武器耗蓝量
};

#endif // !__BASICWEAPON_H__
#pragma once
#include "cocos2d.h"
#include "Bullet/BasicBullet.h"

#ifndef __BASICWEAPON_H__
#define __BASICWEAPON_H__

class BasicWeapon : public cocos2d::Sprite
{
public:
	BasicBullet* getBullet();////�õ��ӵ������ͣ�Ҫ�����������г�ʼ��
	virtual BasicBullet* createBullet() = 0;
	float getBulletSpeed()const;
	int getBulletDamage()const;
	int getBlueConsumption()const;
protected:
	BasicBullet* _bullet;//�������ӵ�
	float _bulletSpeed;//�ӵ��ٶ�
	int _bulletDamage;//�ӵ��˺�
	int _blueConsumption;//����������
};

#endif // !__BASICWEAPON_H__
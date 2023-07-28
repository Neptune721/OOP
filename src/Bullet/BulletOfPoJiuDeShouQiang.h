#pragma once
#ifndef __BULLETOFPOJIUDESHOUQIANG_H__
#define __BULLETOFPOJIUDESHOUQIANG_H__

#include "cocos2d.h"
#include "Bullet/BasicBullet.h"

class BulletOfPoJiuDeShouQiang :public BasicBullet
{
public:
	static BulletOfPoJiuDeShouQiang* create(const std::string& filename);
protected:
	virtual void initBullet();
};

#endif // !__BULLETOFPOJIUDESHOUQIANG_H__

#pragma once
#ifndef __BULLETOFXIANQUZHE_H__
#define __BULLETOFXIANQUZHE_H__

#include "cocos2d.h"
#include "Bullet/BasicBullet.h"

class BulletOfXianQuZhe :public BasicBullet
{
public:
	static BulletOfXianQuZhe* create(const std::string& filename);
protected:
	virtual void initBullet();
};

#endif // !__BULLETOFXIANQUZHE_H__

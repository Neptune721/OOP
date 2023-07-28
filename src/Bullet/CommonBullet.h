#pragma once
#ifndef __COMMONBULLET_H__
#define __COMMONBULLET_H__

#include "cocos2d.h"
#include "Bullet/BasicBullet.h"

class CommonBullet :public BasicBullet
{
public:
	static CommonBullet* create(const std::string& filename);
protected:
	virtual void initBullet();
};

#endif // !__COMMONBULLET_H__

#pragma once
#ifndef __QISHI_H__
#define __QISHI_H__

#include "cocos2d.h"
#include "Role/BasicRole.h"
#include "Weapon/PoJiuDeShouQiang/PoJiuDeShouQiang.h"
#include "Bullet/BulletOfXianQuZhe.h"

class QiShi :public BasicRole
{
public:
	static QiShi* create(const std::string& filename);
	virtual void useRoleSkill();
	virtual void stopRoleSkill();
private:
	virtual void initRole();
};

#endif // !__QISHI_H__
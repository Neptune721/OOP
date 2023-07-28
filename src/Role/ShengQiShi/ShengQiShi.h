#pragma once
#ifndef __SHENGQISHI_H__
#define __SHENGQISHI_H__

#include "cocos2d.h"
#include "Role/BasicRole.h"
#include "Weapon/PoJiuDeShouQiang/PoJiuDeShouQiang.h"

class ShengQiShi :public BasicRole
{
public:
	static ShengQiShi* create(const std::string& filename);
	virtual void useRoleSkill();
	virtual void stopRoleSkill();
private:
	virtual void initRole();
};

#endif // !__SHENGQISHI_H__
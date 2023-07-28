#pragma once
#ifndef __YOUXIA_H__
#define __YOUXIA_H__

#include "cocos2d.h"
#include "Role/BasicRole.h"
#include "Weapon/XianQuZhe/XianQuZhe.h"

class YouXia :public BasicRole
{
public:
	static YouXia* create(const std::string& filename);
	virtual void useRoleSkill();
	virtual void stopRoleSkill();
private:
	virtual void initRole();
};

#endif // !__YOUXIA_H_


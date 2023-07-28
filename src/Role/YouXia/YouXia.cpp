#include "Role/YouXia/YouXia.h"
USING_NS_CC;

YouXia* YouXia::create(const std::string& filename)
{
	YouXia* sprite = new YouXia();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initRole();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void YouXia::useRoleSkill()
{
	this->startCalculateSkillCD = true;
	this->_speed = _normalSpeed * 4.0f;
}

void YouXia::stopRoleSkill()
{
	this->startCalculateSkillCD = false;
	this->_speed = _normalSpeed;
}

void YouXia::initRole()
{
	BasicRole::initRole();

	this->_timeDelay = 60;
	this->_maxTimeDelay = 60;

	this->_blood = 50;
	this->_blue = 200;
	this->_shield = 100;
	this->_maxBlood = 50;
	this->_maxBlue = 200;
	this->_maxShield = 100;

	this->_speed = 10.0f;
	this->_normalSpeed = 10.0f;

	this->_skillTimeMaxAddition = 10;
	this->_skillTimeAddition = 0;
	this->startCalculateSkillCD = false;

	this->_ifRoleCollided = false;

	//这里创建了youxia的武器
	this->_weapon = XianQuZhe::create("Weapon/XianQuZhe/XianQuZhe.png");
}

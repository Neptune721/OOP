#include "Role/ShengQiShi/ShengQiShi.h"
USING_NS_CC;

ShengQiShi* ShengQiShi::create(const std::string& filename)
{
	ShengQiShi* sprite = new ShengQiShi();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initRole();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void ShengQiShi::useRoleSkill()
{
	this->startCalculateSkillCD = true;
	this->_speed = _normalSpeed * 1.5f;
}

void ShengQiShi::stopRoleSkill()
{
	this->startCalculateSkillCD = false;
	this->setNormalSpeed();
}

void ShengQiShi::initRole()
{
	BasicRole::initRole();

	this->_timeDelay = 60;
	this->_maxTimeDelay = 60;

	this->_blood = 30;
	this->_blue = 200;
	this->_shield = 200;
	this->_maxBlood = 30;
	this->_maxBlue = 200;
	this->_maxShield = 200;

	this->_speed = 7.0f;
	this->_normalSpeed = 10.0f;

	this->_skillTimeMaxAddition = 180;

	this->_ifRoleCollided = false;

	this->_weapon = PoJiuDeShouQiang::create("Weapon/PoJiuDeShouQiang/PoJiuDeShouQiang.png");
}
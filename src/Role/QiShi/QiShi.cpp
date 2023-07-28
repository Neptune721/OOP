#include "Role/QiSHi/QiShi.h"
USING_NS_CC;

QiShi* QiShi::create(const std::string& filename)
{
	QiShi* sprite = new QiShi();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initRole();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void QiShi::useRoleSkill()
{

}

void QiShi::stopRoleSkill()
{

}

void QiShi::initRole()
{
	BasicRole::initRole();

	this->_timeDelay = 60;
	this->_maxTimeDelay = 60;

	this->_blood = 40;
	this->_blue = 200;
	this->_shield = 150;
	this->_maxBlood = 40;
	this->_maxBlue = 200;
	this->_maxShield = 200;
	
	this->_speed = 9.0f;
	this->_normalSpeed = 9.0f;

	this->_skillTimeMaxAddition = 180;
	this->_skillTimeAddition = 0;
	this->startCalculateSkillCD = false;

	this->_ifRoleCollided = false;

	this->_weapon = PoJiuDeShouQiang::create("Weapon/PoJiuDeShouQiang/PoJiuDeShouQiang.png");
}
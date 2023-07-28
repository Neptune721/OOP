#include "Role/BasicRole.h"
USING_NS_CC;

void BasicRole::initRole()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->rectRole = Rect(this->getPosition() - this->getContentSize() / 2, this->getContentSize());
}

void BasicRole::setSpeed(float speed)
{
	this->_speed = speed;
}

float BasicRole::getSpeed()const
{
	return this->_speed;
}
float BasicRole::getNormalSpeed() const
{
	return this->_normalSpeed;
}
void BasicRole::setNormalSpeed()
{
	this->_speed = this->_normalSpeed;
}
int BasicRole::getBlood()const
{
	return this->_blood;
}
int BasicRole::getMaxBlood() const
{
	return this->_maxBlood;
}
int BasicRole::getBlue() const
{
	return this->_blue;
}
int BasicRole::getMaxBlue() const
{
	return this-> _maxBlue;
}
int BasicRole::getShield() const
{
	return this->_shield;
}
int BasicRole::getMaxShield() const
{
	return this->_maxShield;
}
cocos2d::Rect BasicRole::getRect()const
{
	return this->rectRole;
}
void BasicRole::setRect(cocos2d::Rect& rect)
{
	this->rectRole = rect;
}

void BasicRole::alterBloodOrShield(int damage)
{
	if (this->_shield - damage >= 0)
	{
		this->_shield -= damage;
	}
	else if (this->_shield == 0)
	{
		this->_blood -= damage;
	}
	else
	{
		this->_blood -= damage - this->_shield;
		this->_shield = 0;
	}
}

void BasicRole::alterBlue(int consumption)
{
	this->_blue -= consumption;
}

int BasicRole::getCollisionDamage()const
{
	return this->_collisionDamage;
}

bool BasicRole::timeDelay()
{
	this->_timeDelay++;
	if (_timeDelay > _maxTimeDelay)
	{
		_timeDelay = 0;
		return true;
	}
	return false;
}

void BasicRole::increaseShieldWithTime()
{
	this->_shield += 5;
	if (_shield > _maxShield)
	{
		_shield = _maxShield;
	}
}

void BasicRole::increaseBlueWithTime()
{
	this->_blue += 10;
	if (_blue > _maxBlue)
	{
		_blue = _maxBlue;
	}
}

void BasicRole::setRoleAttribution(int blood, int shield, int blue)
{
	this->_blood = blood;
	this->_shield = shield;
	this->_blue = blue;
}

void BasicRole::stopRoleSkill()
{
}

float BasicRole::getSkillCD() const
{
	return this->_skillTimeMaxAddition;
}

void BasicRole::addSkillCD()
{
	_skillTimeAddition++;
	if (_skillTimeAddition >= _skillTimeMaxAddition)
	{
		_skillTimeAddition = 0;
		this->stopRoleSkill();
	}
}

BasicWeapon* BasicRole::getWeapon()const
{
	return this->_weapon;
}

void BasicRole::setWeapon(BasicWeapon* weapon)
{
	this->_weapon = weapon;
}

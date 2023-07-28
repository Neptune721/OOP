#include "Role/ShuiJingChong/ShuiJingChong.h"
USING_NS_CC;

ShuiJingChong* ShuiJingChong::create(const std::string& filename)
{
	ShuiJingChong* sprite = new ShuiJingChong();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initRole();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void ShuiJingChong::initRole()
{
	BasicRole::initRole();
	std::srand(time(NULL));
	this->_maxTimeDelay = 120;
	this->_timeDelay = rand() % (2 * _maxTimeDelay + 1);
	if (this->_timeDelay < _maxTimeDelay / 2)
	{
		this->_ifMove = 1;
	}
	this->_speed = 4.0f;
	this->_blood = 30;
	this->_collisionDamage = 2;
	this->_weapon = NULL;//该类没有武器一说，依靠碰撞伤害来攻击主角
	this->_timeDelay = 60;
	this->_maxTimeDelay = 60;
	this->_blood = 30;
	this->_blue = 0;
	this->_shield = 0;
	this->_maxBlood = 30;
	this->_maxBlue = 0;
	this->_maxShield = 0;
}

cocos2d::Vec2 ShuiJingChong::getMoveVector() const
{
	return this->_moveVector;
}

void ShuiJingChong::setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition)
{
	Vec2 directionVector = endPosition - startPosition;
	this->_moveVector = directionVector.getNormalized() * this->_speed;
}

bool ShuiJingChong::timeDelay()
{
	if (_ifMove)
	{
		if (this->_timeDelay++ >= 2 * _maxTimeDelay / 3)
		{
			_ifMove = false;
		}
		return true;
	}
	else
	{
		if (this->_timeDelay++ >= _maxTimeDelay)
		{
			_ifMove = true;
			_timeDelay = 0;
		}
		return false;
	}
}

void ShuiJingChong::useRoleSkill()
{
}

void ShuiJingChong::stopRoleSkill()
{
}

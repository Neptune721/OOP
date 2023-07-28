#include "KuangGong.h"
USING_NS_CC;

KuangGong* KuangGong::create(const std::string& filename)
{
	KuangGong* sprite = new KuangGong();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initRole();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void KuangGong::initRole()
{
	//其实基类的initRole()有些东西对于敌人类来讲是没有用处的
	//比如初始位置设置为中央，这没有什么大的意义，因为每个敌人的位置都在tileMap上标出
	//再比如设置_collisionTime，60这个值这实际上只为主角每秒只受一次碰撞伤害服务
	//但我在这里重新赋值并重写函数，可以将其改为敌人的攻击速度
	BasicRole::initRole();
	this->_blood = 15;
	this->_blue = 0;
	this->_shield = 0;
	this->_maxBlood = 15;
	this->_maxBlue = 0;
	this->_maxShield = 0;
	this->_speed = 2.0f;
	this->_blood = 15;
	this->_collisionDamage = 1;
	//这里虽然用不到武器本身，但是可以用到这个武器里面产生子弹的函数
	//并且初始化时是在游戏开始的时候，不会引起卡顿
	this->_weapon = CommonWeapon::create("Weapon/XianQuZhe/XianQuZhe.png");
	this->_timeDelay = 120;
	this->_maxTimeDelay = 120;
}

cocos2d::Vec2 KuangGong::getMoveVector() const
{
	return this->_moveVector;
}

void KuangGong::setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition)
{
	Vec2 directionVector = endPosition - startPosition;
	this->_moveVector = directionVector.getNormalized() * this->_speed;
}

void KuangGong::useRoleSkill()
{
}

void KuangGong::stopRoleSkill()
{
}

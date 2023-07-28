#include "Bullet/BulletOfPoJiuDeShouQiang.h"
USING_NS_CC;

BulletOfPoJiuDeShouQiang* BulletOfPoJiuDeShouQiang::create(const std::string& filename)
{
	BulletOfPoJiuDeShouQiang* sprite = new BulletOfPoJiuDeShouQiang();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initBullet();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void BulletOfPoJiuDeShouQiang::initBullet()
{
	this->_speed = 18.0f;
	this->_damage = 7;
	this->_blueComsumption = 2;
}
#include "Weapon/PoJiuDeShouQiang/PoJiuDeShouQiang.h"
USING_NS_CC;

PoJiuDeShouQiang* PoJiuDeShouQiang::create(const std::string& filename)
{
	PoJiuDeShouQiang* sprite = new PoJiuDeShouQiang();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initWeapon();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void PoJiuDeShouQiang::initWeapon()
{
	this->_bullet = BulletOfPoJiuDeShouQiang::create("Bullet/BulletOfPoJiuDeShouQiang.png");
	this->_bulletSpeed = _bullet->getSpeed();
	this->_bulletDamage = _bullet->getDamage();
	this->_blueConsumption = _bullet->getBlueComsumption();
}

BasicBullet* PoJiuDeShouQiang::createBullet()
{
	return BulletOfPoJiuDeShouQiang::create("Bullet/BulletOfPoJiuDeShouQiang.png");
}

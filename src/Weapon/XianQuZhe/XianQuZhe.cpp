#include "Weapon/XianQuZhe/XianQuZhe.h"
USING_NS_CC;

XianQuZhe* XianQuZhe::create(const std::string& filename)
{
	XianQuZhe* sprite = new XianQuZhe();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initWeapon();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void XianQuZhe::initWeapon()
{
	this->_bullet = BulletOfXianQuZhe::create("Bullet/BulletOfXianQuZhe.png");
	this->_bulletSpeed = _bullet->getSpeed();
	this->_bulletDamage = _bullet->getDamage();
	this->_blueConsumption = _bullet->getBlueComsumption();
}

BasicBullet* XianQuZhe::createBullet()
{
	return BulletOfXianQuZhe::create("Bullet/BulletOfXianQuZhe.png");
}
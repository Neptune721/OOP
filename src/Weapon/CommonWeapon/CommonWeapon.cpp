#include "Weapon/CommonWeapon/CommonWeapon.h"
USING_NS_CC;

CommonWeapon* CommonWeapon::create(const std::string& filename)
{
	CommonWeapon* sprite = new CommonWeapon();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initWeapon();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void CommonWeapon::initWeapon()
{
	this->_bullet = CommonBullet::create("Bullet/CommonBullet.png");
	this->_bulletSpeed = _bullet->getSpeed();
	this->_bulletDamage = _bullet->getDamage();
	this->_blueConsumption = _bullet->getBlueComsumption();
}

BasicBullet* CommonWeapon::createBullet()
{
	return CommonBullet::create("Bullet/CommonBullet.png");
}
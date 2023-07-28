#include "Weapon/BasicWeapon.h"
USING_NS_CC;

BasicBullet* BasicWeapon::getBullet()
{
	return this->_bullet;
}

float BasicWeapon::getBulletSpeed() const
{
	return this->_bulletSpeed;
}

int BasicWeapon::getBulletDamage() const
{
	return this->_bulletDamage;
}

int BasicWeapon::getBlueConsumption() const
{
	return this->_blueConsumption;
}
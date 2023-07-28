#include "Bullet/BulletOfXianQuZhe.h"
USING_NS_CC;

BulletOfXianQuZhe* BulletOfXianQuZhe::create(const std::string& filename)
{
	BulletOfXianQuZhe* sprite = new BulletOfXianQuZhe();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initBullet();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void BulletOfXianQuZhe::initBullet()
{
	this->_speed = 32.0f;
	this->_damage = 15;
	this->_blueComsumption = 4;
}
#include "Bullet/CommonBullet.h"
USING_NS_CC;

CommonBullet* CommonBullet::create(const std::string& filename)
{
	CommonBullet* sprite = new CommonBullet();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->initBullet();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void CommonBullet::initBullet()
{
	this->_speed = 10.0f;
	this->_damage = 10;
	this->_blueComsumption = 0;
}
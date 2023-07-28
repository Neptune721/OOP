#include "Bullet/RoundBullet.h"
USING_NS_CC;

RoundBullet* RoundBullet::create(const std::string& filename)
{
	RoundBullet* sprite = new RoundBullet();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Vec2 RoundBullet::getMoveVector()
{
	return this->_moveVector;
}

float RoundBullet::getSpeed()
{
	return this->_speed;
}

void RoundBullet::setMoveVector(Vec2 startPosition,Vec2 endPosition)
{
	Vec2 directionVector = endPosition - startPosition;
	this->_moveVector=directionVector.getNormalized()*this->_speed;
}

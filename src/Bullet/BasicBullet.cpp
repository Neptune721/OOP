#include "Bullet/BasicBullet.h"
USING_NS_CC;

Vec2 BasicBullet::getMoveVector()const
{
	return this->_moveVector;
}

float BasicBullet::getSpeed()const
{
	return this->_speed;
}

int BasicBullet::getDamage()const
{
	return this->_damage;
}

int BasicBullet::getBlueComsumption() const
{
	return this->_blueComsumption;
}

void BasicBullet::setMoveVector(Vec2 startPosition, Vec2 endPosition)
{
	Vec2 directionVector = endPosition - startPosition;
	this->_moveVector = directionVector.getNormalized() * this->_speed;
}

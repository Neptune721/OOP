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
	//��ʵ�����initRole()��Щ�������ڵ�����������û���ô���
	//�����ʼλ������Ϊ���룬��û��ʲô������壬��Ϊÿ�����˵�λ�ö���tileMap�ϱ��
	//�ٱ�������_collisionTime��60���ֵ��ʵ����ֻΪ����ÿ��ֻ��һ����ײ�˺�����
	//�������������¸�ֵ����д���������Խ����Ϊ���˵Ĺ����ٶ�
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
	//������Ȼ�ò��������������ǿ����õ����������������ӵ��ĺ���
	//���ҳ�ʼ��ʱ������Ϸ��ʼ��ʱ�򣬲������𿨶�
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

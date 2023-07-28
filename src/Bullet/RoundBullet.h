#pragma once
#ifndef __ROUNDBULLET_H__
#define __ROUNDBULLET_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"

class RoundBullet :public BasicWeapon
{
public:
	static RoundBullet* create(const std::string& filename);
	cocos2d::Vec2 getMoveVector();//��ȡÿһ֡�ƶ�������
	float getSpeed();
	void setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);
	//virtual bool init();
	//CREATE_FUNC(RoundBullet);
	//createfunc�������ܹ�create()��ʱ��ִ��init()����
	//���˴�û���õ�create()��init()��������д��Sprite��create����
	//�ʲ²���ط����������д���
private:
	float _speed = 5.0f;
	cocos2d::Vec2 _moveVector;
};

#endif // !__ROUNDBULLET_H__

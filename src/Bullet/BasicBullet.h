#pragma once
#ifndef __BASICBULLET_H__
#define __BASICBULLET_H__

#include "cocos2d.h"

class BasicBullet : public cocos2d::Sprite
{
public:
	//��ȡÿһ֡�ƶ�������
	cocos2d::Vec2 getMoveVector()const;

	//����������������ĳ�ʼλ�������ӵ�ÿһ֡�ƶ�������
	void setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);

	//�����ӵ����Ե�get����
	float getSpeed()const;
	int getDamage()const;
	int getBlueComsumption()const;

protected:
	//����ȫ�������ó�ʼֵ����Ϊ�����д��麯�������������initbullet()�����ӵ�����
	float _speed;//�ӵ����������ٶ�
	int _damage;//�ӵ���������������
	int _blueComsumption;//�ӵ���������������
	cocos2d::Vec2 _moveVector;//ÿһ֡�ƶ�������
	virtual void initBullet() = 0;//���麯��
};

#endif
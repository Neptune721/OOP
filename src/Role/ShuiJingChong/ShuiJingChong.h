#pragma once
#ifndef __SHUIJINGCHONG_H__
#define __SHUIJINGCHONG_H__

#include "cocos2d.h"
#include "Role/BasicRole.h"

class ShuiJingChong :public BasicRole
{
public:
	static ShuiJingChong* create(const std::string& filename);
	virtual void initRole();

	//��ȡÿһ֡�ƶ�������
	cocos2d::Vec2 getMoveVector()const;

	//����������������ĳ�ʼλ�������ӵ�ÿһ֡�ƶ�������
	void setMoveVector(cocos2d::Vec2 startPosition, cocos2d::Vec2 endPosition);
	virtual bool timeDelay();
	virtual void useRoleSkill();
	virtual void stopRoleSkill();
private:
	cocos2d::Vec2 _moveVector;
	bool _ifMove;
};
#endif // !__SHUIJINGCHONG_H__

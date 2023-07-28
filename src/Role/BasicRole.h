#pragma once
#ifndef __ROLEBASIC_H__
#define __ROLEBASIC_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"
#include "Bullet/BasicBullet.h"

class BasicRole :public cocos2d::Sprite
{
public:
	BasicWeapon* getWeapon()const;//����֮��ֻ����BasicWeapon*���ͱ�ʾ��������Ϊ��֪�����ĸ���ɫ�޷�ƥ���������
	void setWeapon(BasicWeapon* weapon);//������������
	void setSpeed(float speed);//���������ٶȣ����ٴ�ɶ��
	float getSpeed()const;//��ȡ�����ٶ�
	float getNormalSpeed()const;//��ȡ�����ʼ�ٶ�
	int getBlood()const;//��ȡ����Ѫ��
	int getMaxBlood()const;//��ȡ����Ѫ��
	int getBlue()const;//��ȡ��������
	int getMaxBlue()const;//��ȡ��������
	int getShield()const;//��ȡ���ﻤ��
	int getMaxShield()const;//��ȡ���ﻤ��
	cocos2d::Rect getRect()const;//��ȡ�������
	void setRect(cocos2d::Rect& rect);//�����������
	void alterBloodOrShield(int damage);//��Ѫ��Ѫ����Ϊ��Ѫ����Ϊ��Ѫ���ȿۻ��ܣ��ٿ�Ѫ
	void alterBlue(int consumption);//����
	int getCollisionDamage()const;//��ȡ��ײ�˺�
	virtual void setNormalSpeed();//��ʼ���ٶ�
	virtual bool timeDelay();//��ʱ����
	virtual void increaseShieldWithTime();//�Զ��ض�
	virtual void increaseBlueWithTime();//�Զ�����
	virtual void setRoleAttribution(int blood, int shield, int blue);//ʹ��ȫ�ֱ�����ʼ����������
	
	//�������＼�ܣ�����ʹ�ô��麯��
	//�ŵ��Ǽ�ʹ�û���ָ�룬Ҳ�ܵ���ÿ�������಻ͬ�ļ��ܺ���
	//ȱ���������������Ҳ�����˼̳��ˣ������˲�û�����ü��ܣ�����ڵ������б�������һ���յļ��ܺ������ܽ�������
	virtual void useRoleSkill() = 0;
	virtual void stopRoleSkill() = 0;

	float getSkillCD()const;
	bool _ifRoleCollided;//�Ƿ���ǽ����ײ

	void addSkillCD();
	bool startCalculateSkillCD;
protected:
	virtual void initRole();
	cocos2d::Rect rectRole;//�������
	BasicWeapon* _weapon;//����
	int _blood,_maxBlood;//Ѫ��
	int _blue,_maxBlue;//����
	int _shield,_maxShield;//����
	int _collisionDamage;//��ײ�˺�ֵ
	float _speed;//�ƶ��ٶ�
	float _normalSpeed;//����ƶ��ٶȣ���Ϊһ����ֵ�������������
	int _timeDelay,_maxTimeDelay;//��ʱ������ʱ����ܻ�ĳ��µ�update����
	float _skillTimeAddition;//����cd��������
	float _skillTimeMaxAddition;//����cd��������
};

#endif // !__BASICROLE_H_
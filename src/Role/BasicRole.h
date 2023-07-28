#pragma once
#ifndef __ROLEBASIC_H__
#define __ROLEBASIC_H__

#include "cocos2d.h"
#include "Weapon/BasicWeapon.h"
#include "Bullet/BasicBullet.h"

class BasicRole :public cocos2d::Sprite
{
public:
	BasicWeapon* getWeapon()const;//基类之中只能用BasicWeapon*类型表示武器，因为不知道是哪个角色无法匹配具体武器
	void setWeapon(BasicWeapon* weapon);//设置武器类型
	void setSpeed(float speed);//设置人物速度，加速带啥的
	float getSpeed()const;//获取人物速度
	float getNormalSpeed()const;//获取人物初始速度
	int getBlood()const;//获取人物血量
	int getMaxBlood()const;//获取人物血量
	int getBlue()const;//获取人物蓝条
	int getMaxBlue()const;//获取人物蓝条
	int getShield()const;//获取人物护盾
	int getMaxShield()const;//获取人物护盾
	cocos2d::Rect getRect()const;//获取人物矩形
	void setRect(cocos2d::Rect& rect);//设置人物矩形
	void alterBloodOrShield(int damage);//加血扣血，正为扣血，负为加血；先扣护盾，再扣血
	void alterBlue(int consumption);//扣蓝
	int getCollisionDamage()const;//获取碰撞伤害
	virtual void setNormalSpeed();//初始化速度
	virtual bool timeDelay();//延时函数
	virtual void increaseShieldWithTime();//自动回盾
	virtual void increaseBlueWithTime();//自动回蓝
	virtual void setRoleAttribution(int blood, int shield, int blue);//使用全局变量初始化人物属性
	
	//调用人物技能，这里使用纯虚函数
	//优点是即使用基类指针，也能调用每个派生类不同的技能函数
	//缺点是由于人物基类也给敌人继承了，而敌人并没有设置技能，因此在敌人类中必须设置一个空的既能函数才能建立对象
	virtual void useRoleSkill() = 0;
	virtual void stopRoleSkill() = 0;

	float getSkillCD()const;
	bool _ifRoleCollided;//是否与墙壁碰撞

	void addSkillCD();
	bool startCalculateSkillCD;
protected:
	virtual void initRole();
	cocos2d::Rect rectRole;//人物矩形
	BasicWeapon* _weapon;//武器
	int _blood,_maxBlood;//血条
	int _blue,_maxBlue;//蓝条
	int _shield,_maxShield;//护盾
	int _collisionDamage;//碰撞伤害值
	float _speed;//移动速度
	float _normalSpeed;//最大移动速度，作为一个定值来衡量加速情况
	int _timeDelay,_maxTimeDelay;//延时函数有时间可能会改成新的update函数
	float _skillTimeAddition;//技能cd辅助变量
	float _skillTimeMaxAddition;//技能cd辅助变量
};

#endif // !__BASICROLE_H_
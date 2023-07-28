#pragma once
#ifndef __BASICSCENE_H__
#define __BASICSCENE_H__

#include "cocos2d.h"
#include "Music/Music.h"
#include "Role/RoleFile.h"
#include "Bullet/BasicBullet.h"
#include "Scene/GameScene/GameSceneInfo.h"
#include "Scene/GameEndScene/GameLoseScene.h"
#include "Scene/SuspensionScene/SuspensionScene.h"


class BasicScene :public cocos2d::Scene
{
public:
	/**创建一个类型为Scene*的场景
	*/
	static cocos2d::Scene* createScene();

	/**设置人物出现的初始位置
	* 目前而言，切换场景的时候，主角都是重新生成的，这个问题后期会解决
	* 然后后期需要修改一下很多函数的参数类型、返回值类型，加上const等等
	*/
	void setInitialLocation(const std::string& strLocation);

protected:
	//总屏幕尺寸
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	/**父类的初始化函数，重写的时候要先调用父类的初始函数
	* 这个init里面包含了所有room会用到的公共初始内容
	*/
	virtual bool init();

	/**
	* 角色技能函数
	*/

	void stopRoleSkill(float delta);
	void useRoleSkill();
	/**update函数
	*/
	virtual void update();//这个函数还是需要的，很多东西都需要一秒60帧地更新

	inline void updateRole(float delta);//每帧都执行，更新人物
	inline void iteratingShuiJingChong(float delta);//遍历水晶虫
	inline void iteratingKuangGong(float delta);//遍历旷工
	inline void iteratingBulletOfRole(float delta);//遍历人物子弹
	//inline void iteratingObstacle(float delta);//遍历障碍物
	inline void iteratingBulletOfKuangGong(float delta);//遍历旷工子弹
	inline void addRoleShield(float delta);//自动回复护盾
	inline void addRoleBlue(float delta);//自动回复蓝量
	inline void moveRole(float delta);//人物移动，每帧都执行
	inline bool ifRectCollideObstacles(cocos2d::Rect &nextRect);

	//监听事件
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);


	/******以下函数都放在update里面，每一帧都会去调用******/

	/**子弹移动函数 调用此函数会将vecBullet中所有子弹全部移动
	* 原本我是想设个起点和终点让它自己runAction()的，后来发现终点并非鼠标点击的终点，所以放弃
	* 后来采用了唐奥翔的方法，即根据鼠标点击位置endPosition和人物的位置startPosition，设置一个向量vector，并将其模长设为RoundBullet类中的speed
	* 在每一帧去重新设置其位置，这样就能实现其移动了，由于子弹位置的更新调用非常频繁，将其设置为inline函数
	*/
	inline void bulletMoveTogether();

	/**怪物自动移动函数 调用次函数只会将特定敌人移动
	* 此处的移动函数和子弹的移动实现方式基本一样
	* 区别在于子弹的移动与鼠标点击位置有关
	* 而怪物的移动和人物的位置有关
	*/
	inline void enemyMoveOneByOne(std::vector<ShuiJingChong*>::iterator& iter);

	/**碰撞函数
	* 这里面实际上是个双重循环，即遍历vecObstacle和vecBullet并判断bullet是否与obstacle碰撞
	* 为了节省时间，在update()中循环障碍物的时候不断调用它，并将其设置为inline函数以减少调用时的消耗
	*/
	//inline bool ifBulletCollided(cocos2d::Rect& rect);

	/**检测游戏是否结束
	* 元气骑士游戏的机制。关卡有1-1 1-2 1-3 1-4 1-5 2-1...2-5 3-1...3-6这么多个，每个关卡会有4到5个场景
	* 进入每个场景的时候都会出现很多怪，我们需要打败这些怪，这样这个场景就结束了
	* 这个函数就是检测怪是否打完，或者我们主角是否死亡的函数，目前还写不了
	*/
	inline void ifRoleDead();
	inline void ifEnemiesAllDead();

	//inline void gameStart();//游戏开始函数，放在init()中，可以稍微把init函数整理一下
	bool _ifGameEnd = 0;//游戏结束标志

	void updateRoleAttribution(int blood, int shield, int blue);

	/**主角
	* 声明人物基类指针，可以指向其派生类的对象
	* 在BasicScene会定义_role指向某个具体人物，形成多态
	*/
	BasicRole* _role;

	/**子弹
	* 将子弹类型定义在场景类中，从而有利于多个子弹的生成
	* 当然这里子弹的类型是BasicBullet*,因此有需要的时候可以重新赋值，即切换武器
	*/
	cocos2d::Layer* roleBulletLayer = cocos2d::Layer::create();
	cocos2d::Layer* propertiesLayer = cocos2d::Layer::create();
	inline void initPropertiesLayer();

	//设置监听器
	cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	//键盘
	cocos2d::EventListenerKeyboard* keyListener = cocos2d::EventListenerKeyboard::create();
	//鼠标
	cocos2d::EventListenerTouchOneByOne* mouseListener = cocos2d::EventListenerTouchOneByOne::create();

	/*场景类的辅助变量*/
	std::map<cocos2d::EventKeyboard::KeyCode, bool>_keyMap;
	std::vector<cocos2d::Rect>vecObstacle;//障碍物组成的vector
	std::vector<BasicBullet*>vecBulletOfRole;//主角子弹组成的vector
	std::vector<BasicBullet*>vecBulletOfKuangGong;//旷工子弹组成的vector
	std::vector<ShuiJingChong*>vecEnemyOfShuiJingChong;//水晶虫敌人组成的vector
	std::vector<KuangGong*>vecEnemyOfKuangGong;//旷工敌人组成的vector
	cocos2d::Rect rectDoor_left, rectDoor_right;//左右门，在切换场景的时候用到
	cocos2d::Vec2 Vec2LeftPosition, Vec2RightPosition;//左右初始位置，在进入新的场景、设置人物初始位置时用到

	cocos2d::Label* labelOfRoleBlood, * labelOfRoleMaxBlood, * labelOfRoleShield, * labelOfRoleMaxShield, * labelOfRoleBlue, * labelOfRoleMaxBlue, * labelOfXieXian_1, * labelOfXieXian_2, * labelOfXieXian_3;
};

#endif // !__BASICSCENE_H__

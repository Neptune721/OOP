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
	/**����һ������ΪScene*�ĳ���
	*/
	static cocos2d::Scene* createScene();

	/**����������ֵĳ�ʼλ��
	* Ŀǰ���ԣ��л�������ʱ�����Ƕ����������ɵģ����������ڻ���
	* Ȼ�������Ҫ�޸�һ�ºܶຯ���Ĳ������͡�����ֵ���ͣ�����const�ȵ�
	*/
	void setInitialLocation(const std::string& strLocation);

protected:
	//����Ļ�ߴ�
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	/**����ĳ�ʼ����������д��ʱ��Ҫ�ȵ��ø���ĳ�ʼ����
	* ���init�������������room���õ��Ĺ�����ʼ����
	*/
	virtual bool init();

	/**
	* ��ɫ���ܺ���
	*/

	void stopRoleSkill(float delta);
	void useRoleSkill();
	/**update����
	*/
	virtual void update();//�������������Ҫ�ģ��ܶණ������Ҫһ��60֡�ظ���

	inline void updateRole(float delta);//ÿ֡��ִ�У���������
	inline void iteratingShuiJingChong(float delta);//����ˮ����
	inline void iteratingKuangGong(float delta);//��������
	inline void iteratingBulletOfRole(float delta);//���������ӵ�
	//inline void iteratingObstacle(float delta);//�����ϰ���
	inline void iteratingBulletOfKuangGong(float delta);//���������ӵ�
	inline void addRoleShield(float delta);//�Զ��ظ�����
	inline void addRoleBlue(float delta);//�Զ��ظ�����
	inline void moveRole(float delta);//�����ƶ���ÿ֡��ִ��
	inline bool ifRectCollideObstacles(cocos2d::Rect &nextRect);

	//�����¼�
	virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);


	/******���º���������update���棬ÿһ֡����ȥ����******/

	/**�ӵ��ƶ����� ���ô˺����ὫvecBullet�������ӵ�ȫ���ƶ�
	* ԭ����������������յ������Լ�runAction()�ģ����������յ㲢����������յ㣬���Է���
	* �����������ư���ķ����������������λ��endPosition�������λ��startPosition������һ������vector��������ģ����ΪRoundBullet���е�speed
	* ��ÿһ֡ȥ����������λ�ã���������ʵ�����ƶ��ˣ������ӵ�λ�õĸ��µ��÷ǳ�Ƶ������������Ϊinline����
	*/
	inline void bulletMoveTogether();

	/**�����Զ��ƶ����� ���ôκ���ֻ�Ὣ�ض������ƶ�
	* �˴����ƶ��������ӵ����ƶ�ʵ�ַ�ʽ����һ��
	* ���������ӵ����ƶ��������λ���й�
	* ��������ƶ��������λ���й�
	*/
	inline void enemyMoveOneByOne(std::vector<ShuiJingChong*>::iterator& iter);

	/**��ײ����
	* ������ʵ�����Ǹ�˫��ѭ����������vecObstacle��vecBullet���ж�bullet�Ƿ���obstacle��ײ
	* Ϊ�˽�ʡʱ�䣬��update()��ѭ���ϰ����ʱ�򲻶ϵ�����������������Ϊinline�����Լ��ٵ���ʱ������
	*/
	//inline bool ifBulletCollided(cocos2d::Rect& rect);

	/**�����Ϸ�Ƿ����
	* Ԫ����ʿ��Ϸ�Ļ��ơ��ؿ���1-1 1-2 1-3 1-4 1-5 2-1...2-5 3-1...3-6��ô�����ÿ���ؿ�����4��5������
	* ����ÿ��������ʱ�򶼻���ֺܶ�֣�������Ҫ�����Щ�֣�������������ͽ�����
	* ����������Ǽ����Ƿ���꣬�������������Ƿ������ĺ�����Ŀǰ��д����
	*/
	inline void ifRoleDead();
	inline void ifEnemiesAllDead();

	//inline void gameStart();//��Ϸ��ʼ����������init()�У�������΢��init��������һ��
	bool _ifGameEnd = 0;//��Ϸ������־

	void updateRoleAttribution(int blood, int shield, int blue);

	/**����
	* �����������ָ�룬����ָ����������Ķ���
	* ��BasicScene�ᶨ��_roleָ��ĳ����������γɶ�̬
	*/
	BasicRole* _role;

	/**�ӵ�
	* ���ӵ����Ͷ����ڳ������У��Ӷ������ڶ���ӵ�������
	* ��Ȼ�����ӵ���������BasicBullet*,�������Ҫ��ʱ��������¸�ֵ�����л�����
	*/
	cocos2d::Layer* roleBulletLayer = cocos2d::Layer::create();
	cocos2d::Layer* propertiesLayer = cocos2d::Layer::create();
	inline void initPropertiesLayer();

	//���ü�����
	cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
	//����
	cocos2d::EventListenerKeyboard* keyListener = cocos2d::EventListenerKeyboard::create();
	//���
	cocos2d::EventListenerTouchOneByOne* mouseListener = cocos2d::EventListenerTouchOneByOne::create();

	/*������ĸ�������*/
	std::map<cocos2d::EventKeyboard::KeyCode, bool>_keyMap;
	std::vector<cocos2d::Rect>vecObstacle;//�ϰ�����ɵ�vector
	std::vector<BasicBullet*>vecBulletOfRole;//�����ӵ���ɵ�vector
	std::vector<BasicBullet*>vecBulletOfKuangGong;//�����ӵ���ɵ�vector
	std::vector<ShuiJingChong*>vecEnemyOfShuiJingChong;//ˮ���������ɵ�vector
	std::vector<KuangGong*>vecEnemyOfKuangGong;//����������ɵ�vector
	cocos2d::Rect rectDoor_left, rectDoor_right;//�����ţ����л�������ʱ���õ�
	cocos2d::Vec2 Vec2LeftPosition, Vec2RightPosition;//���ҳ�ʼλ�ã��ڽ����µĳ��������������ʼλ��ʱ�õ�

	cocos2d::Label* labelOfRoleBlood, * labelOfRoleMaxBlood, * labelOfRoleShield, * labelOfRoleMaxShield, * labelOfRoleBlue, * labelOfRoleMaxBlue, * labelOfXieXian_1, * labelOfXieXian_2, * labelOfXieXian_3;
};

#endif // !__BASICSCENE_H__

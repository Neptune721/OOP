#include "Scene/GameScene/Room_2.h"
USING_NS_CC;

bool Room_2::init()
{
	if (!BasicScene::init())
	{
		return false;
	}

	auto tileMap = TMXTiledMap::create("GameScene/Room_2/Room_2.tmx");
	this->addChild(tileMap,0);

	auto objectsLayer = tileMap->getObjectGroup("objectsLayer");

	if (!ifRoom2Ended)
	{
		auto objectShuiJingChong_1 = objectsLayer->getObject("shuijingchong_1");
		auto objectShuiJingChong_2 = objectsLayer->getObject("shuijingchong_2");
		auto objectShuiJingChong_3 = objectsLayer->getObject("shuijingchong_3");
		auto objectShuiJingChong_4 = objectsLayer->getObject("shuijingchong_4");
		auto objectShuiJingChong_5 = objectsLayer->getObject("shuijingchong_5");
		auto objectShuiJingChong_6 = objectsLayer->getObject("shuijingchong_6");
		auto objectKuangGong_1 = objectsLayer->getObject("kuanggong_1");
		auto objectKuangGong_2 = objectsLayer->getObject("kuanggong_2");
		auto objectKuangGong_3 = objectsLayer->getObject("kuanggong_3");
		auto objectKuangGong_4 = objectsLayer->getObject("kuanggong_4");

		//加入敌人，水晶虫，旷工
		auto shuijingchong_1 = ShuiJingChong::create("Role/ShuiJingChong.png");
		auto shuijingchong_2 = ShuiJingChong::create("Role/ShuiJingChong.png");
		auto shuijingchong_3 = ShuiJingChong::create("Role/ShuiJingChong.png");
		auto shuijingchong_4 = ShuiJingChong::create("Role/ShuiJingChong.png");
		auto shuijingchong_5 = ShuiJingChong::create("Role/ShuiJingChong.png");
		auto shuijingchong_6 = ShuiJingChong::create("Role/ShuiJingChong.png");
		auto kuanggong_1 = KuangGong::create("Role/KuangGong.png");
		auto kuanggong_2 = KuangGong::create("Role/KuangGong.png");
		auto kuanggong_3 = KuangGong::create("Role/KuangGong.png");
		auto kuanggong_4 = KuangGong::create("Role/KuangGong.png");

		shuijingchong_1->setPosition(Vec2(objectShuiJingChong_1["x"].asFloat(), objectShuiJingChong_1["y"].asFloat()));
		shuijingchong_2->setPosition(Vec2(objectShuiJingChong_2["x"].asFloat(), objectShuiJingChong_2["y"].asFloat()));
		shuijingchong_3->setPosition(Vec2(objectShuiJingChong_3["x"].asFloat(), objectShuiJingChong_3["y"].asFloat()));
		shuijingchong_4->setPosition(Vec2(objectShuiJingChong_4["x"].asFloat(), objectShuiJingChong_4["y"].asFloat()));
		shuijingchong_5->setPosition(Vec2(objectShuiJingChong_5["x"].asFloat(), objectShuiJingChong_5["y"].asFloat()));
		shuijingchong_6->setPosition(Vec2(objectShuiJingChong_6["x"].asFloat(), objectShuiJingChong_6["y"].asFloat()));
		kuanggong_1->setPosition(Vec2(objectKuangGong_1["x"].asFloat(), objectKuangGong_1["y"].asFloat()));
		kuanggong_2->setPosition(Vec2(objectKuangGong_2["x"].asFloat(), objectKuangGong_2["y"].asFloat()));
		kuanggong_3->setPosition(Vec2(objectKuangGong_3["x"].asFloat(), objectKuangGong_3["y"].asFloat()));
		kuanggong_4->setPosition(Vec2(objectKuangGong_4["x"].asFloat(), objectKuangGong_4["y"].asFloat()));

		shuijingchong_1->setRect(Rect(shuijingchong_1->getPosition() - shuijingchong_1->getContentSize() / 2, shuijingchong_1->getContentSize()));
		shuijingchong_2->setRect(Rect(shuijingchong_2->getPosition() - shuijingchong_2->getContentSize() / 2, shuijingchong_2->getContentSize()));
		shuijingchong_3->setRect(Rect(shuijingchong_3->getPosition() - shuijingchong_3->getContentSize() / 2, shuijingchong_3->getContentSize()));
		shuijingchong_4->setRect(Rect(shuijingchong_4->getPosition() - shuijingchong_4->getContentSize() / 2, shuijingchong_4->getContentSize()));
		shuijingchong_5->setRect(Rect(shuijingchong_5->getPosition() - shuijingchong_5->getContentSize() / 2, shuijingchong_5->getContentSize()));
		shuijingchong_6->setRect(Rect(shuijingchong_6->getPosition() - shuijingchong_6->getContentSize() / 2, shuijingchong_6->getContentSize()));
		kuanggong_1->setRect(Rect(kuanggong_1->getPosition() - kuanggong_1->getContentSize() / 2, kuanggong_1->getContentSize()));
		kuanggong_2->setRect(Rect(kuanggong_2->getPosition() - kuanggong_2->getContentSize() / 2, kuanggong_2->getContentSize()));
		kuanggong_3->setRect(Rect(kuanggong_3->getPosition() - kuanggong_3->getContentSize() / 2, kuanggong_3->getContentSize()));
		kuanggong_4->setRect(Rect(kuanggong_4->getPosition() - kuanggong_4->getContentSize() / 2, kuanggong_4->getContentSize()));

		vecEnemyOfShuiJingChong.push_back(shuijingchong_1);
		vecEnemyOfShuiJingChong.push_back(shuijingchong_2);
		vecEnemyOfShuiJingChong.push_back(shuijingchong_3);
		vecEnemyOfShuiJingChong.push_back(shuijingchong_4);
		vecEnemyOfShuiJingChong.push_back(shuijingchong_5);
		vecEnemyOfShuiJingChong.push_back(shuijingchong_6);
		vecEnemyOfKuangGong.push_back(kuanggong_1);
		vecEnemyOfKuangGong.push_back(kuanggong_2);
		vecEnemyOfKuangGong.push_back(kuanggong_3);
		vecEnemyOfKuangGong.push_back(kuanggong_4);
		this->addChild(shuijingchong_1, 3);
		this->addChild(shuijingchong_2, 3);
		this->addChild(shuijingchong_3, 3);
		this->addChild(shuijingchong_4, 3);
		this->addChild(shuijingchong_5, 3);
		this->addChild(shuijingchong_6, 3);
		this->addChild(kuanggong_1, 3);
		this->addChild(kuanggong_2, 3);
		this->addChild(kuanggong_3, 3);
		this->addChild(kuanggong_4, 3);
		this->addChild(kuanggong_1->getWeapon(), 3);
		this->addChild(kuanggong_2->getWeapon(), 3);
		this->addChild(kuanggong_3->getWeapon(), 3);
		this->addChild(kuanggong_4->getWeapon(), 3);
	}
	auto objectWall_1 = objectsLayer->getObject("wall_1");
	auto objectWall_2 = objectsLayer->getObject("wall_2");
	auto objectWall_3 = objectsLayer->getObject("wall_3");
	auto objectWall_4 = objectsLayer->getObject("wall_4");
	auto objectWall_5 = objectsLayer->getObject("wall_5");
	auto objectWall_6 = objectsLayer->getObject("wall_6");
	auto objectWall_7 = objectsLayer->getObject("wall_7");
	auto objectWall_8 = objectsLayer->getObject("wall_8");
	auto objectWall_9 = objectsLayer->getObject("wall_9");
	auto objectWall_10 = objectsLayer->getObject("wall_10");
	auto objectWall_11 = objectsLayer->getObject("wall_11");
	auto objectWall_12 = objectsLayer->getObject("wall_12");
	auto objectWall_13 = objectsLayer->getObject("wall_13");
	auto objectWall_14 = objectsLayer->getObject("wall_14");
	auto objectWall_15 = objectsLayer->getObject("wall_15");
	auto objectWall_16 = objectsLayer->getObject("wall_16");
	auto objectWall_17 = objectsLayer->getObject("wall_17");
	auto objectWall_18 = objectsLayer->getObject("wall_18");
	auto objectWall_19 = objectsLayer->getObject("wall_19");
	auto objectDoor_left = objectsLayer->getObject("door_left");
	auto objectDoor_right = objectsLayer->getObject("door_right");
	auto objectLeftPosition = objectsLayer->getObject("left_position");
	auto objectRightPosition = objectsLayer->getObject("right_position");
	this->vecObstacle.push_back(Rect::Rect(objectWall_1["x"].asFloat(), objectWall_1["y"].asFloat(), objectWall_1["Length"].asFloat(), objectWall_1["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_2["x"].asFloat(), objectWall_2["y"].asFloat(), objectWall_2["Length"].asFloat(), objectWall_2["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_3["x"].asFloat(), objectWall_3["y"].asFloat(), objectWall_3["Length"].asFloat(), objectWall_3["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_4["x"].asFloat(), objectWall_4["y"].asFloat(), objectWall_4["Length"].asFloat(), objectWall_4["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_5["x"].asFloat(), objectWall_5["y"].asFloat(), objectWall_5["Length"].asFloat(), objectWall_5["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_6["x"].asFloat(), objectWall_6["y"].asFloat(), objectWall_6["Length"].asFloat(), objectWall_6["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_7["x"].asFloat(), objectWall_7["y"].asFloat(), objectWall_7["Length"].asFloat(), objectWall_7["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_8["x"].asFloat(), objectWall_8["y"].asFloat(), objectWall_8["Length"].asFloat(), objectWall_8["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_9["x"].asFloat(), objectWall_9["y"].asFloat(), objectWall_9["Length"].asFloat(), objectWall_9["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_10["x"].asFloat(), objectWall_10["y"].asFloat(), objectWall_10["Length"].asFloat(), objectWall_10["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_11["x"].asFloat(), objectWall_11["y"].asFloat(), objectWall_11["Length"].asFloat(), objectWall_11["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_12["x"].asFloat(), objectWall_12["y"].asFloat(), objectWall_12["Length"].asFloat(), objectWall_12["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_13["x"].asFloat(), objectWall_13["y"].asFloat(), objectWall_13["Length"].asFloat(), objectWall_13["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_14["x"].asFloat(), objectWall_14["y"].asFloat(), objectWall_14["Length"].asFloat(), objectWall_14["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_15["x"].asFloat(), objectWall_15["y"].asFloat(), objectWall_15["Length"].asFloat(), objectWall_15["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_16["x"].asFloat(), objectWall_16["y"].asFloat(), objectWall_16["Length"].asFloat(), objectWall_16["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_17["x"].asFloat(), objectWall_17["y"].asFloat(), objectWall_17["Length"].asFloat(), objectWall_17["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_18["x"].asFloat(), objectWall_18["y"].asFloat(), objectWall_18["Length"].asFloat(), objectWall_18["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_19["x"].asFloat(), objectWall_19["y"].asFloat(), objectWall_19["Length"].asFloat(), objectWall_19["Width"].asFloat()));
	
	this->rectDoor_left = Rect::Rect(objectDoor_left["x"].asFloat(), objectDoor_left["y"].asFloat(), objectDoor_left["Length"].asFloat(), objectDoor_left["Width"].asFloat());
	this->rectDoor_right = Rect::Rect(objectDoor_right["x"].asFloat(), objectDoor_right["y"].asFloat(), objectDoor_right["Length"].asFloat(), objectDoor_right["Width"].asFloat());
	this->vecObstacle.push_back(rectDoor_left);
	this->vecObstacle.push_back(rectDoor_right);

	this->Vec2LeftPosition = Vec2(objectLeftPosition["x"].asFloat() + 4.0f, objectLeftPosition["y"].asFloat());
	this->Vec2RightPosition = Vec2(objectRightPosition["x"].asFloat() - 4.0f, objectRightPosition["y"].asFloat());

	return true;
}

void Room_2::update(float delta)
{
	BasicScene::update();
	if (!this->_ifGameEnd)
	{
		return;
	}
	ifRoom2Ended = 1;
	//判断是否进入门
	//if (_role->getRect().intersectsRect(rectDoor_left))
	if (Rect(_role->getRect().origin + Vec2(-11, 0), _role->getRect().size).intersectsRect(rectDoor_left))
		
	{
		_role->stopActionByTag(103);
		_role->setPosition(Vec2(_role->getPosition().x + 6.67f, _role->getPosition().y));
		updateRoleAttribution(this->_role->getBlood(), this->_role->getShield(), this->_role->getBlue());
		auto nextScene = Room_3::create();//这个地方不能用用createScene()
		nextScene->setInitialLocation("right");//从左边的门进就在右边出现
		Director::getInstance()->replaceScene(nextScene);
	}

	if (Rect(_role->getRect().origin + Vec2(11, 0), _role->getRect().size).intersectsRect(rectDoor_right))
	{
		_role->stopActionByTag(104);
		_role->setPosition(Vec2(_role->getPosition().x - 6.67f, _role->getPosition().y));
		updateRoleAttribution(this->_role->getBlood(), this->_role->getShield(), this->_role->getBlue());
		auto nextScene = Room_1::create();
		nextScene->setInitialLocation("left");
		Director::getInstance()->replaceScene(nextScene);
	}
}
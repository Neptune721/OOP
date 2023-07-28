#include "Scene/GameScene/Room_0.h"
USING_NS_CC;

bool Room_0::init()
{
	if (!BasicScene::init())
	{
		return false;
	}
	auto tileMap = TMXTiledMap::create("GameScene/Room_0/Room_0.tmx");
	this->addChild(tileMap,0);

	auto objectsLayer = tileMap->getObjectGroup("objectsLayer");

	auto objectWall_1 = objectsLayer->getObject("wall_1");
	auto objectWall_2 = objectsLayer->getObject("wall_2");
	auto objectWall_3 = objectsLayer->getObject("wall_3");
	auto objectWall_4 = objectsLayer->getObject("wall_4");
	auto objectWall_5 = objectsLayer->getObject("wall_5");
	auto objectWall_6 = objectsLayer->getObject("wall_6");
	auto objectWall_7 = objectsLayer->getObject("wall_7");
	auto objectDoor_left = objectsLayer->getObject("door_left");
	auto objectLeftPosition = objectsLayer->getObject("left_position");
	this->vecObstacle.push_back(Rect::Rect(objectWall_1["x"].asFloat(), objectWall_1["y"].asFloat(), objectWall_1["Length"].asFloat(), objectWall_1["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_2["x"].asFloat(), objectWall_2["y"].asFloat(), objectWall_2["Length"].asFloat(), objectWall_2["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_3["x"].asFloat(), objectWall_3["y"].asFloat(), objectWall_3["Length"].asFloat(), objectWall_3["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_4["x"].asFloat(), objectWall_4["y"].asFloat(), objectWall_4["Length"].asFloat(), objectWall_4["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_5["x"].asFloat(), objectWall_5["y"].asFloat(), objectWall_5["Length"].asFloat(), objectWall_5["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_6["x"].asFloat(), objectWall_6["y"].asFloat(), objectWall_6["Length"].asFloat(), objectWall_6["Width"].asFloat()));
	this->vecObstacle.push_back(Rect::Rect(objectWall_7["x"].asFloat(), objectWall_7["y"].asFloat(), objectWall_7["Length"].asFloat(), objectWall_7["Width"].asFloat()));
	this->rectDoor_left = Rect::Rect(objectDoor_left["x"].asFloat(), objectDoor_left["y"].asFloat(), objectDoor_left["Length"].asFloat(), objectDoor_left["Width"].asFloat());
	this->Vec2LeftPosition = Vec2(objectLeftPosition["x"].asFloat(), objectLeftPosition["y"].asFloat());
	return true;
}

void Room_0::update(float delta)
{
	BasicScene::update();
	//判断是否进入门
	if (_role->getRect().intersectsRect(rectDoor_left))
	{
		_role->stopActionByTag(103);
		_role->setPosition(Vec2(_role->getPosition().x + 6.67f, _role->getPosition().y));
		updateRoleAttribution(this->_role->getBlood(), this->_role->getShield(), this->_role->getBlue());
		auto nextScene = Room_1::create();//这个地方不能用用createScene()
		nextScene->setInitialLocation("right");//从左边的门进就在右边出现
		Director::getInstance()->replaceScene(nextScene);
	}
}
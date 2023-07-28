#include "Scene/GameScene/Room_3.h"
USING_NS_CC;

bool Room_3::init()
{
	if (!BasicScene::init())
	{
		return false;
	}

	//使用Tiled生成的.tmx文件去创建一个TMXTiledMap类的对象，然后将这个tileMap直接addChild，这样.tmx文件里面的图块内容就都进去了
	auto tileMap = TMXTiledMap::create("GameScene/Room_3/Room_3.tmx");
	this->addChild(tileMap,0);

	//Tiled可以设置对象层，objectsLayer是一个对象层，可以将其提取
	auto objectsLayer = tileMap->getObjectGroup("objectsLayer");

	//将对象层里面的对象提取出来
	auto objectWall_1 = objectsLayer->getObject("wall_1");
	auto objectWall_2 = objectsLayer->getObject("wall_2");
	auto objectWall_3 = objectsLayer->getObject("wall_3");
	auto objectWall_4 = objectsLayer->getObject("wall_4");
	auto objectWall_5 = objectsLayer->getObject("wall_5");
	auto objectWall_6 = objectsLayer->getObject("wall_6");
	auto objectWall_7 = objectsLayer->getObject("wall_7");
	auto objectDoor_right = objectsLayer->getObject("door_right");
	auto objectRightPosition = objectsLayer->getObject("right_position");
	auto objectTransfer = objectsLayer->getObject("transfer");
	auto objectTextPosition = objectsLayer->getObject("text");

	//可以自行设置对象的某些属性，其中"x","y"是自带的属性，"width"和"height"是我自行添加的属性
	this->vecObstacle.push_back(Rect(objectWall_1["x"].asFloat(), objectWall_1["y"].asFloat(), objectWall_1["Length"].asFloat(), objectWall_1["Width"].asFloat()));
	this->vecObstacle.push_back(Rect(objectWall_2["x"].asFloat(), objectWall_2["y"].asFloat(), objectWall_2["Length"].asFloat(), objectWall_2["Width"].asFloat()));
	this->vecObstacle.push_back(Rect(objectWall_3["x"].asFloat(), objectWall_3["y"].asFloat(), objectWall_3["Length"].asFloat(), objectWall_3["Width"].asFloat()));
	this->vecObstacle.push_back(Rect(objectWall_4["x"].asFloat(), objectWall_4["y"].asFloat(), objectWall_4["Length"].asFloat(), objectWall_4["Width"].asFloat()));
	this->vecObstacle.push_back(Rect(objectWall_5["x"].asFloat(), objectWall_5["y"].asFloat(), objectWall_5["Length"].asFloat(), objectWall_5["Width"].asFloat()));
	this->vecObstacle.push_back(Rect(objectWall_6["x"].asFloat(), objectWall_6["y"].asFloat(), objectWall_6["Length"].asFloat(), objectWall_6["Width"].asFloat()));
	this->vecObstacle.push_back(Rect(objectWall_7["x"].asFloat(), objectWall_7["y"].asFloat(), objectWall_7["Length"].asFloat(), objectWall_7["Width"].asFloat()));
	this->rectDoor_right = Rect(objectDoor_right["x"].asFloat(), objectDoor_right["y"].asFloat(), objectDoor_right["Length"].asFloat(), objectDoor_right["Width"].asFloat());
	this->Vec2RightPosition = Vec2(objectRightPosition["x"].asFloat(), objectRightPosition["y"].asFloat());
	this->rectTransfer = Rect(objectTransfer["x"].asFloat(), objectTransfer["y"].asFloat(), objectTransfer["Length"].asFloat(), objectTransfer["Width"].asFloat());
	this->label = Label::createWithTTF("press E to transfer", "fonts/Marker Felt.ttf", 40);
	this->label->setPosition(Vec2(objectTextPosition["x"].asFloat(), objectTextPosition["y"].asFloat()));
	this->addChild(label);
	return true;
}

void Room_3::update(float delta)
{
	BasicScene::update();

	if (_role->getRect().intersectsRect(rectDoor_right))
	{
		//_role->stopActionByTag(104);
		_role->setPosition(Vec2(_role->getPosition().x - 6.67f, _role->getPosition().y));
		updateRoleAttribution(this->_role->getBlood(), this->_role->getShield(), this->_role->getBlue());
		auto nextScene = Room_2::create();
		nextScene->setInitialLocation("left");
		Director::getInstance()->replaceScene(nextScene);
	}

	if (this->_role->getRect().intersectsRect(this->rectTransfer) && _keyMap[cocos2d::EventKeyboard::KeyCode::KEY_E])
	{
		Director::getInstance()->pushScene(GameWin::create());
	}
}
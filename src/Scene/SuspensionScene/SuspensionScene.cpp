#include "Scene/SuspensionScene/SuspensionScene.h"

USING_NS_CC;

cocos2d::Scene* SuspensionScene::createScene()
{
	return Scene::create();
}

bool SuspensionScene::init()
{
	//暂停画面，默认情况下背景板全黑
	if (!Scene::init()) {
		return false;
	}
	auto tileMap = TMXTiledMap::create("SuspensionRelated/SuspensionScene.tmx");
	//this->addChild(tileMap);

	TMXObjectGroup* objectsLayer = tileMap->getObjectGroup("objectsLayer");

	auto spriteMenuPosition = objectsLayer->getObject("menu");
	auto homeItemPosition = objectsLayer->getObject("home");
	auto continueItemPosition = objectsLayer->getObject("continue");
	auto styleItemPosition = objectsLayer->getObject("style");

	auto homeItem = MenuItem::create([](Ref* pSender)->void {
		playClickMusic();
		Director::getInstance()->popToRootScene();
		});
	auto continueItem = MenuItem::create([](Ref* pSender)->void {
		playClickMusic();
		Director::getInstance()->popScene();
		});
	auto styleItem = MenuItem::create([](Ref* pSender)->void {
		playClickMusic();
		Director::getInstance()->pushScene(SetGameStyle::create());
		});
	homeItem->setAnchorPoint(Vec2::ZERO);
	homeItem->setContentSize(Size(homeItemPosition["width"].asFloat(), homeItemPosition["height"].asFloat()));
	homeItem->setPosition(Vec2(homeItemPosition["x"].asFloat(), homeItemPosition["y"].asFloat()));
	continueItem->setAnchorPoint(Vec2::ZERO);
	continueItem->setContentSize(Size(continueItemPosition["width"].asFloat(), continueItemPosition["height"].asFloat()));
	continueItem->setPosition(Vec2(continueItemPosition["x"].asFloat(), continueItemPosition["y"].asFloat()));
	styleItem->setAnchorPoint(Vec2::ZERO);
	styleItem->setContentSize(Size(styleItemPosition["width"].asFloat(), styleItemPosition["height"].asFloat()));
	styleItem->setPosition(Vec2(styleItemPosition["x"].asFloat(), styleItemPosition["y"].asFloat()));

	auto spriteMenu = Sprite::create("SuspensionRelated/SuspensionMenu.png");
	spriteMenu->setPosition(spriteMenuPosition["x"].asFloat(), spriteMenuPosition["y"].asFloat());
	this->addChild(spriteMenu);

	auto menu = Menu::create(homeItem, continueItem, styleItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;
}

#include "Scene/GameEndScene/GameWinScene.h"
USING_NS_CC;
cocos2d::Scene* GameWin::createScene()
{
	return Scene::create();
}

bool GameWin::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto tileMap = TMXTiledMap::create("GameScene/GameWinScene/GameWinScene.tmx");
	this->addChild(tileMap);
	auto objectsLayer = tileMap->getObjectGroup("item");
	auto backItemPosition = objectsLayer->getObject("back");

	auto backItem = MenuItem::create([](Ref* pSender)->void {
		Director::getInstance()->popToRootScene();
		});
	backItem->setAnchorPoint(Vec2::ZERO);
	backItem->setContentSize(Size(backItemPosition["Length"].asFloat(), backItemPosition["Width"].asFloat()));
	backItem->setPosition(Vec2(backItemPosition["x"].asFloat(), backItemPosition["y"].asFloat()));
	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	return true;
}

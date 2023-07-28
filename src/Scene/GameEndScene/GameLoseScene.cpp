#include "Scene/GameEndScene/GameLoseScene.h"
#include "Music/Music.h"

USING_NS_CC;
cocos2d::Scene* GameLose::createScene()
{
	return Scene::create();
}

bool GameLose::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto tileMap = TMXTiledMap::create("GameScene/GameLoseScene/GameLoseScene.tmx");
	this->addChild(tileMap);
	auto objectsLayer = tileMap->getObjectGroup("item");
	auto backItemPosition = objectsLayer->getObject("back");

	auto backItem = MenuItem::create([](Ref* pSender)->void {	
		if (musicIfOpen == true)
		{
			beginMainMusic();
		}
		Director::getInstance()->popToRootScene();
		});
	backItem->setAnchorPoint(Vec2::ZERO);
	backItem->setContentSize(Size(backItemPosition["Length"].asFloat(), backItemPosition["Width"].asFloat()));
	backItem->setPosition(Vec2(backItemPosition["x"].asFloat(), backItemPosition["y"].asFloat()));
	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	//πÿ±’±≥æ∞“Ù¿÷
	stopMainMusic();

	playLosekMusic();


	return true;
}

#include "Scene/StartGameScene/StartGameScene.h"

USING_NS_CC;

Scene* StartGame::createScene()
{
	return StartGame::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames\n");
}

bool StartGame::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//StartGameScene
	auto backGround = Sprite::create("StartGameScene/StartGameScene.png");
	if (backGround == nullptr)
	{
		problemLoading("'StartGameScene.png'");
	}
	else
	{
		backGround->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
		this->addChild(backGround, 0);
		backGround->setName("background");
	}

	//menu
	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);

	//closeGameItem
	auto closeGameItem = MenuItemImage::create("StartGameScene/CloseNormal.png", "StartGameScene/CloseSelected.png",
		[](Ref* pSender)->void {Director::getInstance()->end(); });
	if (closeGameItem == nullptr || closeGameItem->getContentSize().width <= 0 || closeGameItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeGameItem->getContentSize().width / 2;
		float y = origin.y + closeGameItem->getContentSize().height / 2;
		closeGameItem->setPosition(Vec2(x, y));
	}
	menu->addChild(closeGameItem);

	
	//SetStyleItem
	auto setGameStyleItem = MenuItemImage::create("StartGameScene/SetStyleItem.png", "StartGameScene/SetStyleItem.png",
		[](Ref* pSender)->void {
			playClickMusic();
			Director::getInstance()->pushScene(SetGameStyle::create());
		});
	if (setGameStyleItem == nullptr || setGameStyleItem->getContentSize().width <= 0 || setGameStyleItem->getContentSize().height <= 0)
	{
		problemLoading("'SetStyleItem.png'");
	}
	else
	{
		float x = origin.x + setGameStyleItem->getContentSize().width * 0.65f;
		float y = origin.y + setGameStyleItem->getContentSize().height * 1.25f;
		setGameStyleItem->setPosition(Vec2(x, y));
		menu->addChild(setGameStyleItem);
	}
	

	//ShowProducersInformationItem
	auto showProducersInformationItem = MenuItemImage::create("StartGameScene/ShowProducersInformationItem.png", "StartGameScene/ShowProducersInformationItem.png",
		[](Ref* pSender)->void {Director::getInstance()->pushScene(ShowProducersInformation::createScene()); });
	if (showProducersInformationItem == nullptr || showProducersInformationItem->getContentSize().width <= 0 || showProducersInformationItem->getContentSize().height <= 0)
	{
		problemLoading("'SetStyleItem.png'");
	}
	else
	{
		float x = origin.x + showProducersInformationItem->getContentSize().width * 0.65f;
		float y = origin.y + showProducersInformationItem->getContentSize().height * 2.5f;
		showProducersInformationItem->setPosition(Vec2(x, y));
		menu->addChild(showProducersInformationItem);
	}

	
	//startGameItem
	auto startGameItem = MenuItemImage::create("StartGameScene/StartGameItem.png", "StartGameScene/StartGameItem.png",
		[](Ref* pSender) ->void {
			playClickMusic();
			//ÖØÖÃ¹Ø¿¨¹ÖÎï
			ifRoom1Ended = false;
			ifRoom2Ended = false;
			Director::getInstance()->pushScene(TransitionCrossFade::create(0.5f, RoleSelect::createScene()));
		});
	if (startGameItem == nullptr || startGameItem->getContentSize().width <= 0 || startGameItem->getContentSize().height <= 0)
	{
		problemLoading("'StartGameItem.png'");
	}
	else
	{
		float x = origin.x + startGameItem->getContentSize().width * 265.0f / 1932.0f;
		float y = origin.y + startGameItem->getContentSize().height * 34.0f / 192.0f;
		startGameItem->setPosition(Vec2(x, y));
		startGameItem->setAnchorPoint(Vec2::ZERO);
		menu->addChild(startGameItem);
	}

	this->addChild(menu, 1);

	ifRoom1Ended = false;
	ifRoom2Ended = false;

	beginMainMusic();
	CCLOG("MUSIC Begin");

	return true;
}
#include "Scene/StartGameScene/ShowProducerInformationScene.h"
USING_NS_CC;

Scene* ShowProducersInformation::createScene()
{
	return ShowProducersInformation::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in ShowProducersInformationScene.cpp\n");
}

bool ShowProducersInformation::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto spriteShowProducersInformationBackGround = Sprite::create("ShowProducersInformationScene/ShowProducersInformationBackGround.png");
	spriteShowProducersInformationBackGround->setPosition(origin.x + visibleSize.width * 0.5, origin.y + visibleSize.height * 0.5);

	auto layerShowProducersInformationBackGround = Layer::create();
	layerShowProducersInformationBackGround->addChild(spriteShowProducersInformationBackGround);

	this->addChild(layerShowProducersInformationBackGround);



	auto layerOfProducersInformation = Layer::create();

	auto labelOfProducersInformation = Label::createWithTTF("Producers Information:", "fonts/Marker Felt.ttf", 96);
	labelOfProducersInformation->setPosition(origin.x + visibleSize.width * 0.5, origin.y + visibleSize.height * 0.7);
	layerOfProducersInformation->addChild(labelOfProducersInformation);

	auto labelOfNameAndNum = Label::createWithTTF("LiuChang 2054164\nWangHui 2052082\nTangAoXiang 2052143\nCaoXiaoCi 2052844", "fonts/Marker Felt.ttf", 72);
	labelOfNameAndNum->setPosition(origin.x + visibleSize.width * 0.5, origin.y + visibleSize.height * 0.45);
	layerOfProducersInformation->addChild(labelOfNameAndNum);

	this->addChild(layerOfProducersInformation);

	auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	auto backItem = MenuItemImage::create("ShowProducersInformationScene/backItem.png", "ShowProducersInformationScene/backItem.png",
		[](Ref* pSender)->void {Director::getInstance()->popScene(); });
	if (backItem == nullptr || backItem->getContentSize().width <= 0 || backItem->getContentSize().height <= 0)
	{
		problemLoading("'backItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width * 0.5 + spriteShowProducersInformationBackGround->getContentSize().width * 0.5;
		float y = origin.y + visibleSize.height * 0.5 + spriteShowProducersInformationBackGround->getContentSize().height * 0.5;
		backItem->setAnchorPoint(Vec2(1, 1));
		backItem->setPosition(Vec2(x, y));
		menu->addChild(backItem);
	}
	this->addChild(menu);
	return true;
}
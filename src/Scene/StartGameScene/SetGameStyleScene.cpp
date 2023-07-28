#include "Scene/StartGameScene/SetGameStyleScene.h"

USING_NS_CC;

Scene* SetGameStyle::createScene()
{
	return Scene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames\n");
}

bool SetGameStyle::init()
{
	if (!Scene::init())
	{
		return false;
	}

	huakuai= Sprite::create("game_picture/slidButton.png");
	menu1 = Menu::create();
	menu2 = Menu::create();

	Size visibleSize = Director::getInstance()->getWinSize();

	auto tileMap = TMXTiledMap::create("SuspensionRelated/SuspensionScene.tmx");
	//this->addChild(tileMap);

	TMXObjectGroup* objectsLayer = tileMap->getObjectGroup("objectsLayer");

	auto spriteMenuPosition = objectsLayer->getObject("menu");
	auto homeItemPosition = objectsLayer->getObject("home");
	auto continueItemPosition = objectsLayer->getObject("continue");
	auto styleItemPosition = objectsLayer->getObject("style");

	auto styleItem = MenuItem::create([](Ref* pSender)->void {
		playClickMusic();
		Director::getInstance()->popScene();
		});

	styleItem->setAnchorPoint(Vec2::ZERO);
	styleItem->setContentSize(Size(styleItemPosition["width"].asFloat(), styleItemPosition["height"].asFloat()));
	styleItem->setPosition(Vec2(styleItemPosition["x"].asFloat(), styleItemPosition["y"].asFloat()));

	//亮一点的按钮图片
	auto styleItemSelected = Sprite::create("SuspensionRelated/StyleButtonSelected.png");
	styleItemSelected->setAnchorPoint(Vec2::ZERO);
	styleItemSelected->setPosition(Vec2(styleItemPosition["x"].asFloat() - 11.0f, styleItemPosition["y"].asFloat() - 21.0f));
	this->addChild(styleItemSelected, 2);

	auto spriteMenu = Sprite::create("SuspensionRelated/SuspensionMenu.png");
	spriteMenu->setPosition(spriteMenuPosition["x"].asFloat(), spriteMenuPosition["y"].asFloat());
	this->addChild(spriteMenu);

	auto menu = Menu::create(styleItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	auto blackcover = Sprite::create("SuspensionRelated/blackcover.png");
	blackcover->setOpacity(150);
	blackcover->setScale(1.4f);
	blackcover->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(blackcover, 1);

	//上面是原来的图像，下面是音乐的设置

	//下层图片
	auto musicSetBackground = Sprite::create("game_picture/musicSetting.png");
	musicSetBackground->setPosition(Vec2(visibleSize.width / 2 - 50.0f, musicSetBackground->getContentSize().height / 2 + 15.0f));
	this->addChild(musicSetBackground, 2);

	musicButtonPos = Vec2(visibleSize.width / 3 - 131.0f, musicSetBackground->getContentSize().height / 2 + 10.0f);

	//音乐按钮
	auto musicCloseButton = MenuItemImage::create("game_picture/musicButton.png", "game_picture/musicButton.png", CC_CALLBACK_1(SetGameStyle::musicCloseCallback, this));
	musicCloseButton->setPosition(musicButtonPos);

	menu1 = Menu::create(musicCloseButton, NULL);
	menu1->setPosition(Vec2::ZERO);


	//第二个音乐按钮
	auto musicOpenButton = MenuItemImage::create("game_picture/musicButtonClose.png", "game_picture/musicButtonClose.png", CC_CALLBACK_1(SetGameStyle::musicOpenCallback, this));
	musicOpenButton->setPosition(musicButtonPos);

	menu2 = Menu::create(musicOpenButton, NULL);
	menu2->setPosition(Vec2::ZERO);

	//根据声音开关，决定放上那个按钮		这样每次生成这个场景的时候，就对应了声音的开关

	if (musicIfOpen)
		this->addChild(menu1, 3);
	else
		this->addChild(menu2, 3);


	//滑块
	LeftPosition = Vec2(visibleSize.width / 3 + 160.0f, musicSetBackground->getContentSize().height / 2 + 15.0f);
	RightPosition = Vec2(visibleSize.width / 3 * 2 + 80.0f, musicSetBackground->getContentSize().height / 2 + 15.0f);
	huakuaiPosition = RightPosition;
	huakuaiPosition = Vec2(LeftPosition.x + (RightPosition.x - LeftPosition.x) * musicVolume, RightPosition.y);

	huakuai->setPosition(huakuaiPosition);
	huakuai->setScale(0.3f);
	huakuai->setTag(0);
	this->addChild(huakuai, 2);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SetGameStyle::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SetGameStyle::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SetGameStyle::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, huakuai);

	return true;
}

// a selector callback
void SetGameStyle::musicCloseCallback(cocos2d::Ref* pSender)
{
	CCLOG("music close");

	musicresumeOrpausePlaying();
	menu1->removeFromParent();

	//打开音乐按钮
	auto musicOpenButton = MenuItemImage::create("game_picture/musicButtonClose.png", "game_picture/musicButtonClose.png", CC_CALLBACK_1(SetGameStyle::musicOpenCallback, this));
	musicOpenButton->setPosition(musicButtonPos.x - 1.0f, musicButtonPos.y);

	menu2 = Menu::create(musicOpenButton, NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2, 3);

	musicIfOpen = false;
}

void SetGameStyle::musicOpenCallback(cocos2d::Ref* pSender)
{

	//此动作的作用是考虑到若角色死亡，同时BGM静音
	if (ifBGMPlaying == false)
	{
		beginMainMusic();
	}
	else
		musicresumeOrpausePlaying();

	CCLOG("music open");
	
	menu2->removeFromParent();

	//关闭音乐按钮
	auto musicCloseButton = MenuItemImage::create("game_picture/musicButton.png", "game_picture/musicButton.png", CC_CALLBACK_1(SetGameStyle::musicCloseCallback, this));
	musicCloseButton->setPosition(musicButtonPos);

	menu1 = Menu::create(musicCloseButton, NULL);
	menu1->setPosition(Vec2::ZERO);
	this->addChild(menu1, 3);

	musicIfOpen = true;

}

bool SetGameStyle::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 position = touch->getLocation();
	Vec2 positionToSprite = event->getCurrentTarget()->convertToNodeSpace(position); //相对精灵的位置
	Rect rect(0, 0, event->getCurrentTarget()->getContentSize().width,
		event->getCurrentTarget()->getContentSize().height);
	if (rect.containsPoint(positionToSprite))	//如果矩形包含  相对点  这个不是很完全懂，但是加上这个才能区分是哪个个Tag
	{
		CCLOG("Began");
		if (event->getCurrentTarget()->getTag() == 0)		//然后才有判断...
		{
			CCLOG("Mid");
			return true;
		}

	}

	return false;

}
void SetGameStyle::onTouchMoved(Touch* touch, Event* event)
{
	auto target = event->getCurrentTarget();
	if (target->getTag() == 0)
	{
		CCLOG("moved");
		Vec2 vec_move = touch->getDelta();
		Vec2 vec_move_x = Vec2(vec_move.x, 0);
		huakuaiPosition = huakuaiPosition + vec_move_x;//分情况，选用哪个

		//判断越界

		if (huakuaiPosition.x < LeftPosition.x)
		{
			huakuaiPosition.x = LeftPosition.x;
		}
		else if (huakuaiPosition.x > RightPosition.x)
		{
			huakuaiPosition.x = RightPosition.x;
		}


		huakuai->setPosition(huakuaiPosition);

		//移动后，调整声音大小。
		musicVolume = (huakuaiPosition.x - LeftPosition.x) / (RightPosition.x - LeftPosition.x);
		setMusicVolume();
	}

}
void SetGameStyle::onTouchEnded(Touch* touch, Event* event)
{

}
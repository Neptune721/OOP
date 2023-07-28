#include "Scene/RoleSelectScene/ShengQiShiRole.h"

USING_NS_CC;

Scene* ShengQiShiSelected::createScene()
{
    return ShengQiShiSelected::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in ShengQiShiRole.cpp\n");
}

bool ShengQiShiSelected::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto labelOfRoleSelect = Label::createWithTTF("shengqishi", "fonts/Marker Felt.ttf", 72);
    labelOfRoleSelect->setPosition(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height - labelOfRoleSelect->getContentSize().height * 0.6f);
    this->addChild(labelOfRoleSelect);

    auto tileMap = TMXTiledMap::create("RoleSelectScene/shengqishiSelectedScene/shengqishiSelectedScene.tmx");
    this->addChild(tileMap);

    auto objectsLayer = tileMap->getObjectGroup("objectsLayer");

    auto startItemPosition = objectsLayer->getObject("startItemPosition");
    auto startItem = MenuItem::create([](Ref* pSender)->void {
        selected_role = "ShengQiShi";
        role_blood = 30;
        role_shield = 200;
        role_blue = 200;
        Director::getInstance()->popToRootScene();
        playClickMusic();
        Director::getInstance()->pushScene(Room_0::create());
        });
    startItem->setAnchorPoint(Vec2(0, 0));
    startItem->setContentSize(Size(startItemPosition["width"].asFloat(), startItemPosition["height"].asFloat()));
    startItem->setPosition(Vec2(startItemPosition["x"].asFloat(), startItemPosition["y"].asFloat()));

    auto backItemPosition = objectsLayer->getObject("backItemPosition");
    auto backItem = MenuItem::create([](Ref* pSender)->void {Director::getInstance()->popScene(); });
    backItem->setAnchorPoint(Vec2(0, 0));
    backItem->setContentSize(Size(backItemPosition["width"].asFloat(), backItemPosition["height"].asFloat()));
    backItem->setPosition(Vec2(backItemPosition["x"].asFloat(), backItemPosition["y"].asFloat()));

    auto menu = Menu::create(startItem, backItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
    return true;
}
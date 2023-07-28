#include "Scene/RoleSelectScene/YouXiaRole.h"
USING_NS_CC;

Scene* YouXiaSelected::createScene()
{
    return YouXiaSelected::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in YouXiaRole.cpp\n");
}

bool YouXiaSelected::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto labelOfRoleSelect = Label::createWithTTF("youxia", "fonts/Marker Felt.ttf", 72);
    labelOfRoleSelect->setPosition(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height - labelOfRoleSelect->getContentSize().height * 0.6f);
    this->addChild(labelOfRoleSelect);

    auto tileMap = TMXTiledMap::create("RoleSelectScene/youxiaSelectedScene/youxiaSelectedScene.tmx");
    this->addChild(tileMap);

    TMXObjectGroup* objectsLayer = tileMap->getObjectGroup("objectsLayer");

    auto startItemPosition = objectsLayer->getObject("startItemPosition");
    auto startItem = MenuItem::create([](Ref* pSender)->void {
        selected_role = "YouXia";
        role_blood = 50;
        role_shield = 100;
        role_blue = 200;
        Director::getInstance()->popToRootScene();
        playClickMusic();
        Director::getInstance()->pushScene(Room_0::create());
        });
    startItem->setAnchorPoint(Vec2::ZERO);
    startItem->setContentSize(Size(startItemPosition["width"].asFloat(), startItemPosition["height"].asFloat()));
    startItem->setPosition(Vec2(startItemPosition["x"].asFloat(), startItemPosition["y"].asFloat()));

    auto backItemPosition = objectsLayer->getObject("backItemPosition");
    auto backItem = MenuItem::create([](Ref* pSender)->void {Director::getInstance()->popScene(); });
    backItem->setAnchorPoint(Vec2::ZERO);
    backItem->setContentSize(Size(backItemPosition["width"].asFloat(), backItemPosition["height"].asFloat()));
    backItem->setPosition(Vec2(backItemPosition["x"].asFloat(), backItemPosition["y"].asFloat()));

    auto menu = Menu::create(startItem, backItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}
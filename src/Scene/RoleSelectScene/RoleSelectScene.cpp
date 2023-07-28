#include "Scene/RoleSelectScene/RoleSelectScene.h"
#include "Scene/RoleSelectScene/ShengQiShiRole.h"
#include "Scene/RoleSelectScene/QiShiRole.h"
#include "Scene/RoleSelectScene/YouXiaRole.h"
USING_NS_CC;

Scene* RoleSelect::createScene()
{
    return RoleSelect::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in RoleSelectScene.cpp\n");
}

bool RoleSelect::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /*auto labelOfRoleSelect = Label::createWithTTF("Please Choose Your Character.", "fonts/Marker Felt.ttf",72);
    labelOfRoleSelect->setPosition(origin.x + visibleSize.width * 0.5,origin.y+visibleSize.height-labelOfRoleSelect->getContentSize().height*0.6);
    this->addChild(labelOfRoleSelect);*/

    //生成tileMap
    auto tileMap = TMXTiledMap::create("RoleSelectScene/RoleSelectScene.tmx");
    this->addChild(tileMap);

    auto objectsLayer = tileMap->getObjectGroup("objectsLayer");
    //定位label
    auto labelPosition = objectsLayer->getObject("labelPosition");
    auto labelOfRoleSelect = Label::createWithTTF("Please Choose Your Character.", "fonts/Marker Felt.ttf", 72);
    labelOfRoleSelect->setPosition(labelPosition["x"].asFloat(), labelPosition["y"].asFloat() - labelOfRoleSelect->getContentSize().height * 0.5f);
    this->addChild(labelOfRoleSelect);

    //角色选择界面，圣骑士
    auto shengqishiPosition = objectsLayer->getObject("shengqishiPosition");
    auto shengqishiItem = MenuItem::create([](Ref* pSender)->void {Director::getInstance()->pushScene(ShengQiShiSelected::createScene()); });
    shengqishiItem->setContentSize(Size(shengqishiPosition["width"].asFloat(), shengqishiPosition["height"].asFloat()));
    shengqishiItem->setAnchorPoint(Vec2(0, 0));
    shengqishiItem->setPosition(Vec2(shengqishiPosition["x"].asFloat(), shengqishiPosition["y"].asFloat()));

    //角色选择界面，骑士
    auto qishiPosition = objectsLayer->getObject("qishiPosition");
    auto qishiItem = MenuItem::create([](Ref* pSender)->void {Director::getInstance()->pushScene(QiShiSelected::createScene()); });
    qishiItem->setContentSize(Size(qishiPosition["width"].asFloat(), qishiPosition["height"].asFloat()));
    qishiItem->setAnchorPoint(Vec2(0, 0));
    qishiItem->setPosition(Vec2(qishiPosition["x"].asFloat(), qishiPosition["y"].asFloat()));

    //角色选择界面，游侠
    auto youxiaPosition = objectsLayer->getObject("youxiaPosition");
    auto youxiaItem = MenuItem::create([](Ref* pSender)->void {Director::getInstance()->pushScene(YouXiaSelected::createScene()); });
    youxiaItem->setContentSize(Size(youxiaPosition["width"].asFloat(), youxiaPosition["height"].asFloat()));
    youxiaItem->setAnchorPoint(Vec2(0, 0));
    youxiaItem->setPosition(Vec2(youxiaPosition["x"].asFloat(), youxiaPosition["y"].asFloat()));

    //返回上一界面按钮
    auto backhomeItemPosition = objectsLayer->getObject("backhomeItemPosition");
    auto backhomeItem = MenuItem::create([](Ref* pSender)->void {Director::getInstance()->popScene(); });
    backhomeItem->setContentSize(Size(backhomeItemPosition["width"].asFloat(), backhomeItemPosition["height"].asFloat()));
    backhomeItem->setAnchorPoint(Vec2(0, 0));
    backhomeItem->setPosition(Vec2(backhomeItemPosition["x"].asFloat(), backhomeItemPosition["y"].asFloat()));


    auto menu = Menu::create(shengqishiItem, qishiItem, youxiaItem, backhomeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}
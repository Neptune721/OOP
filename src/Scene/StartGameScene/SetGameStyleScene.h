#pragma once
#ifndef __SETGAMESTYLESCENE_H__
#define __SETGAMESTYLESCENE_H__

#include "cocos2d.h"
#include "Music/Music.h"

class SetGameStyle : public cocos2d::Scene
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(SetGameStyle);

	//触屏事件
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	//滑块位置边界
	cocos2d::Vec2 LeftPosition;
	cocos2d::Vec2 RightPosition;

	cocos2d::Vec2 huakuaiPosition;
	cocos2d::Vec2 musicButtonPos;


	//滑块
	cocos2d::Sprite* huakuai;

	// a selector callback
	void musicCloseCallback(cocos2d::Ref* pSender);
	void musicOpenCallback(cocos2d::Ref* pSender);

	//按钮菜单，用来关闭和打开音乐，
	//思路是addchild一个，就去掉另一个
	cocos2d::Menu* menu1;
	cocos2d::Menu* menu2;
};


#endif //!__SETGAMESTYLESCENE_H__
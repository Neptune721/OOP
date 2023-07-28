#include "Scene/GameScene/BasicScene.h"
USING_NS_CC;

cocos2d::Scene* BasicScene::createScene()
{
	return BasicScene::create();
}

bool BasicScene::init()
{
	//�ȸ����init()����
	if (!Scene::init())
	{
		return false;
	}

	//���ü��̰���Pressed���ɿ�Released����״̬����Ҫ���õĺ���
	keyListener->onKeyPressed = CC_CALLBACK_2(BasicScene::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(BasicScene::onKeyReleased, this);
	dispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	//������갴��Began��Moved��Ended����״̬����Ҫ���õĺ���
	//�������Ҫ�ǿ����ӵ��ƶ���ʼλ�ã�������onTouchEnded()���棬�����ᵼ��һ�����⣬�����޷�ͨ���������������
	//�����ͨ���������������Ӧ�õ÷���onTouchMoved���棬��������֡�ʣ�����һ��60������ٶ�̫����
	mouseListener->onTouchBegan = CC_CALLBACK_2(BasicScene::onTouchBegan, this);
	mouseListener->onTouchMoved = CC_CALLBACK_2(BasicScene::onTouchMoved, this);
	mouseListener->onTouchEnded = CC_CALLBACK_2(BasicScene::onTouchEnded, this);
	dispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	//����update����
	this->scheduleUpdate();
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::updateRole));
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::iteratingShuiJingChong));
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::iteratingKuangGong));
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::iteratingBulletOfRole));
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::iteratingBulletOfKuangGong));
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::moveRole));

	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::addRoleShield), 2.0f);
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::addRoleBlue), 5.0f);

	//���峡���е������ɫ������ʹ����ȫ�ֱ���
	if (selected_role == "QiShi")
	{
		_role = QiShi::create("Role/QiShi.png");
	}
	else if (selected_role == "ShengQiShi")
	{
		_role = ShengQiShi::create("Role/ShengQiShi.png");
	}
	else if (selected_role == "YouXia")
	{
		_role = YouXia::create("Role/YouXia.png");
	}
	this->schedule(CC_SCHEDULE_SELECTOR(BasicScene::stopRoleSkill), this->_role->getSkillCD());

	this->_role->setRoleAttribution(role_blood, role_shield, role_blue);
	//Ŀǰ������һ���������������������ǰ���һ���
	//����ÿ�ֲ�ͬ���͵�����������ʵ�ַ���

	//this->_bullet = _role->getWeapon()->createBullet();
	//������������뵽������
	this->addChild(_role, 1);
	this->addChild(_role->getWeapon(), 2);
	this->addChild(this->roleBulletLayer, 4);//���������е��ӵ�����뵽������
	//����ͣ��ť���뵽������
	auto suspensionItem = MenuItemImage::create(
		"SuspensionRelated/SuspensionItem.png",
		"SuspensionRelated/SuspensionItem.png",
		[this](Ref* pSender)->void {
			this->unscheduleUpdate();
			playClickMusic();
			Director::getInstance()->pushScene(SuspensionScene::create());
			this->scheduleUpdate();
		});
	suspensionItem->setPosition(origin + visibleSize - suspensionItem->getContentSize());
	auto menu = Menu::create(suspensionItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 6);



	//��������ʼ��ȫ�����ڻ��������ˣ�����˵Ӧ��ÿ����������ֱ��ʼ����
	//�ȵ����޸�ÿ�������ʱ���ٸİ�
	this->initPropertiesLayer();
	this->addChild(propertiesLayer, 7);
	return true;
}

//�˼�����ĳ��������ʱ���õĺ������ᴫ��һ��keycode����ʾ�����µļ�
void BasicScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	this->_keyMap[keycode] = true;
}

//�����̰������ɿ�ʱ��ֹͣ�ö���
void BasicScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	this->_keyMap[keycode] = false;
}
/*****�����������ò��������ע�͵�******/
bool BasicScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//////////////////////////////////////
	return true;
}

void BasicScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//////////////////////////////////////
}

void BasicScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	if (this->_role->getBlue() <= 0)
	{
		return;
	}
	Vec2 endPosition = touch->getLocation();
	Vec2 startPosition = _role->getWeapon()->getPosition();
	auto bullet = _role->getWeapon()->createBullet();
	bullet->setMoveVector(startPosition, endPosition);
	bullet->setPosition(startPosition);
	bullet->setAnchorPoint(Vec2::ZERO);
	roleBulletLayer->addChild(bullet);
	vecBulletOfRole.push_back(bullet);
	this->_role->alterBlue(this->_role->getWeapon()->getBlueConsumption());
	this->labelOfRoleBlue->setString(std::to_string(this->_role->getBlue()));
	playShootMusic();
}

void BasicScene::bulletMoveTogether()
{
	for (std::vector<BasicBullet*>::iterator iter = vecBulletOfRole.begin(); iter != vecBulletOfRole.end(); iter++)
	{
		Vec2 nextPosition = (*iter)->getPosition();
		nextPosition += (*iter)->getMoveVector();
		(*iter)->setPosition(nextPosition);
	}
	for (std::vector<BasicBullet*>::iterator iter = vecBulletOfKuangGong.begin(); iter != vecBulletOfKuangGong.end(); iter++)
	{
		Vec2 nextPosition = (*iter)->getPosition();
		nextPosition += (*iter)->getMoveVector();
		(*iter)->setPosition(nextPosition);
	}
}

inline void BasicScene::enemyMoveOneByOne(std::vector<ShuiJingChong*>::iterator& iter)
{
	Vec2 nextPosition = (*iter)->getPosition();
	nextPosition += (*iter)->getMoveVector();
	(*iter)->setPosition(nextPosition);
}

//�����Ϸ������Ūһ���������˵�ͼƬ�滻role���ٹ���2�룬�л�����һ������
//�����ǣ��������˵�___�أ�����һ����2�ذ�
void BasicScene::ifRoleDead()
{
	if (_role->getBlood() <= 0)
	{
		Director::getInstance()->pushScene(GameLose::create());	
	}
}

void BasicScene::ifEnemiesAllDead()
{
	if (vecEnemyOfShuiJingChong.empty() && vecEnemyOfKuangGong.empty())
	{
		this->_ifGameEnd = 1;
	}
}

void BasicScene::updateRoleAttribution(int blood, int shield, int blue)
{
	role_blood = blood;
	role_shield = shield;
	role_blue = blue;
}

inline void BasicScene::initPropertiesLayer()
{
	TMXTiledMap* propertyList = TMXTiledMap::create("GameScene/BasicScene/PropertyList.tmx");
	Vec2 propertyListPosition = Vec2(origin.x, origin.y + visibleSize.height - propertyList->getContentSize().height);
	propertyList->setPosition(propertyListPosition);
	auto objectsLayer = propertyList->getObjectGroup("objectsLayer");
	this->propertiesLayer->addChild(propertyList);
	std::string roleBlood = std::to_string(this->_role->getBlood());
	std::string roleMaxBlood = std::to_string(this->_role->getMaxBlood());
	std::string roleBlue = std::to_string(this->_role->getBlue());
	std::string roleMaxBlue = std::to_string(this->_role->getMaxBlue());
	std::string roleShield = std::to_string(this->_role->getShield());
	std::string roleMaxShield = std::to_string(this->_role->getMaxShield());
	this->labelOfRoleBlood = Label::createWithTTF(roleBlood, "fonts/Marker Felt.ttf", 40);
	this->labelOfRoleMaxBlood = Label::createWithTTF(roleMaxBlood, "fonts/Marker Felt.ttf", 40);
	this->labelOfRoleShield = Label::createWithTTF(roleShield, "fonts/Marker Felt.ttf", 40);
	this->labelOfRoleMaxShield = Label::createWithTTF(roleMaxShield, "fonts/Marker Felt.ttf", 40);
	this->labelOfRoleBlue = Label::createWithTTF(roleBlue, "fonts/Marker Felt.ttf", 40);
	this->labelOfRoleMaxBlue = Label::createWithTTF(roleMaxBlue, "fonts/Marker Felt.ttf", 40);
	this->labelOfXieXian_1 = Label::createWithTTF("/", "fonts/Marker Felt.ttf", 40);
	this->labelOfXieXian_2 = Label::createWithTTF("/", "fonts/Marker Felt.ttf", 40);
	this->labelOfXieXian_3 = Label::createWithTTF("/", "fonts/Marker Felt.ttf", 40);
	auto roleBloodPosition = objectsLayer->getObject("blood");
	auto xiexianPosition_1 = objectsLayer->getObject("xiexian_1");
	auto roleMaxBloodPosition = objectsLayer->getObject("maxblood");
	auto roleShieldPosition = objectsLayer->getObject("shield");
	auto xiexianPosition_2 = objectsLayer->getObject("xiexian_2");
	auto roleShieldMaxPosition = objectsLayer->getObject("maxshield");
	auto roleBluePosition = objectsLayer->getObject("blue");
	auto xiexianPosition_3 = objectsLayer->getObject("xiexian_3");
	auto roleMaxBluePosition = objectsLayer->getObject("maxblue");
	labelOfRoleBlood->setPosition(propertyListPosition + Vec2(roleBloodPosition["x"].asFloat(), roleBloodPosition["y"].asFloat()));
	labelOfXieXian_1->setPosition(propertyListPosition + Vec2(xiexianPosition_1["x"].asFloat(), xiexianPosition_1["y"].asFloat()));
	labelOfRoleMaxBlood->setPosition(propertyListPosition + Vec2(roleMaxBloodPosition["x"].asFloat(), roleMaxBloodPosition["y"].asFloat()));
	labelOfRoleShield->setPosition(propertyListPosition + Vec2(roleShieldPosition["x"].asFloat(), roleShieldPosition["y"].asFloat()));
	labelOfXieXian_2->setPosition(propertyListPosition + Vec2(xiexianPosition_2["x"].asFloat(), xiexianPosition_2["y"].asFloat()));
	labelOfRoleMaxShield->setPosition(propertyListPosition + Vec2(roleShieldMaxPosition["x"].asFloat(), roleShieldMaxPosition["y"].asFloat()));
	labelOfRoleBlue->setPosition(propertyListPosition + Vec2(roleBluePosition["x"].asFloat(), roleBluePosition["y"].asFloat()));
	labelOfXieXian_3->setPosition(propertyListPosition + Vec2(xiexianPosition_3["x"].asFloat(), xiexianPosition_3["y"].asFloat()));
	labelOfRoleMaxBlue->setPosition(propertyListPosition + Vec2(roleMaxBluePosition["x"].asFloat(), roleMaxBluePosition["y"].asFloat()));
	this->propertiesLayer->addChild(labelOfRoleBlood);
	this->propertiesLayer->addChild(labelOfXieXian_1);
	this->propertiesLayer->addChild(labelOfRoleMaxBlood);
	this->propertiesLayer->addChild(labelOfRoleShield);
	this->propertiesLayer->addChild(labelOfXieXian_2);
	this->propertiesLayer->addChild(labelOfRoleMaxShield);
	this->propertiesLayer->addChild(labelOfRoleBlue);
	this->propertiesLayer->addChild(labelOfXieXian_3);
	this->propertiesLayer->addChild(labelOfRoleMaxBlue);
}

void BasicScene::stopRoleSkill(float delta)
{
	if (this->_keyMap[EventKeyboard::KeyCode::KEY_E])
	{
		this->_role->stopRoleSkill();
	}
}

inline void BasicScene::useRoleSkill()
{
	this->_role->useRoleSkill();
}

void BasicScene::update()//һ��60֡
{
	ifRoleDead();
	if (_keyMap[EventKeyboard::KeyCode::KEY_E] && !_role->startCalculateSkillCD)
	{
		this->useRoleSkill();
	}
	if (_role->startCalculateSkillCD)
	{
		_role->addSkillCD();
	}

	//this->updateRole();
	//this->iteratingShuiJingChong();
	//this->iteratingKuangGong();
	//this->iteratingObstacle();
	//this->iteratingBulletOfKuangGong();

	//�ж���Ϸ�Ƿ����
	this->ifRoleDead();
	this->ifEnemiesAllDead();
}

void BasicScene::updateRole(float delta)
{
	//���ǵ�Ȼ��ÿ֡������
	_role->setRect(Rect(_role->getPosition() - _role->getContentSize() / 2, _role->getContentSize()));//�����������λ��
	_role->getWeapon()->setPosition(_role->getPosition());//������������λ��
}

void BasicScene::iteratingShuiJingChong(float delta)
{
	//����ˮ���������
	for (std::vector<ShuiJingChong*>::iterator iterEnemy = vecEnemyOfShuiJingChong.begin(); iterEnemy != vecEnemyOfShuiJingChong.end(); iterEnemy++)
	{
		//���µ����ƶ����򣬲��ƶ�����
		if (!(*iterEnemy)->timeDelay())
		{
			Vec2 endPosition = this->_role->getPosition();
			Vec2 startPosition = (*iterEnemy)->getPosition();
			(*iterEnemy)->setMoveVector(startPosition, endPosition);
			Vec2 nextPosition = (*iterEnemy)->getPosition();
			nextPosition += (*iterEnemy)->getMoveVector();
			(*iterEnemy)->setPosition(nextPosition);
			//this->enemyMoveOneByOne(iterEnemy);

			//���µ��˾���
			(*iterEnemy)->setRect(Rect((*iterEnemy)->getPosition() - (*iterEnemy)->getContentSize() / 2, (*iterEnemy)->getContentSize()));
		}

		//�������Ѫ������0������ɾȥ
		if ((*iterEnemy)->getBlood() <= 0)
		{
			this->removeChild(*iterEnemy);
			vecEnemyOfShuiJingChong.erase(iterEnemy);
			break;
		}

		//������Ǻ͹�������ײ
		if (_role->getRect().intersectsRect((*iterEnemy)->getRect()) && _role->timeDelay())
		{
			_role->alterBloodOrShield((*iterEnemy)->getCollisionDamage());
			this->labelOfRoleShield->setString(std::to_string(this->_role->getShield()));
			this->labelOfRoleBlood->setString(std::to_string(this->_role->getBlood()));
		}
	}
}

void BasicScene::iteratingKuangGong(float delta)
{
	//��������������
	for (std::vector<KuangGong*>::iterator iterEnemy = vecEnemyOfKuangGong.begin(); iterEnemy != vecEnemyOfKuangGong.end(); iterEnemy++)
	{
		//�����ƶ�
		bool ifMove = true;
		Vec2 startPosition = (*iterEnemy)->getPosition();
		Vec2 endPosition = this->_role->getPosition();
		(*iterEnemy)->setMoveVector(endPosition, startPosition);
		Vec2 nextPosition = (*iterEnemy)->getPosition();
		nextPosition += (*iterEnemy)->getMoveVector();
		Rect rectOfNextPosition = Rect(nextPosition, (*iterEnemy)->getContentSize());
		for (std::vector<Rect>::iterator iterObstacle = vecObstacle.begin(); iterObstacle != vecObstacle.end(); iterObstacle++)
		{
			if (rectOfNextPosition.intersectsRect(*iterObstacle))
			{
				ifMove = false;
				break;
			}
		}
		if (ifMove)
		{
			(*iterEnemy)->setPosition(nextPosition);
		}
		//this->enemyMoveOneByOne(iterEnemy);

		//���﷢���ӵ�
		if ((*iterEnemy)->timeDelay())
		{
			//BasicBullet* bullet = (this->_role)->getWeapon()->createBullet();
			BasicBullet* bullet = (*iterEnemy)->getWeapon()->createBullet();
			bullet->setMoveVector(startPosition, endPosition);
			bullet->setPosition(startPosition);
			bullet->setAnchorPoint(Vec2::ZERO);
			this->addChild(bullet, 5);
			vecBulletOfKuangGong.push_back(bullet);
		}

		//���µ��˾���
		(*iterEnemy)->setRect(Rect((*iterEnemy)->getPosition() - (*iterEnemy)->getContentSize() / 2, (*iterEnemy)->getContentSize()));

		//�������Ѫ������0������ɾȥ
		if ((*iterEnemy)->getBlood() <= 0)
		{
			this->removeChild(*iterEnemy);
			vecEnemyOfKuangGong.erase(iterEnemy);
			break;
		}

		//������Ǻ͹�������ײ
		if (_role->getRect().intersectsRect((*iterEnemy)->getRect()) && _role->timeDelay())
		{
			_role->alterBloodOrShield((*iterEnemy)->getCollisionDamage());
			this->labelOfRoleShield->setString(std::to_string(this->_role->getShield()));
			this->labelOfRoleBlood->setString(std::to_string(this->_role->getBlood()));
		}
	}
}

inline void BasicScene::iteratingBulletOfRole(float delta)//��֡
{
	//�����ӵ��������
	this->bulletMoveTogether();

	for (std::vector<BasicBullet*>::iterator iterBullet = vecBulletOfRole.begin(); iterBullet != vecBulletOfRole.end(); )
	{
		Rect rectBullet = Rect((*iterBullet)->getPosition(), (*iterBullet)->getContentSize());
		if (ifRectCollideObstacles(rectBullet))
		{
			this->roleBulletLayer->removeChild(*iterBullet);//�ӳ�����ɾ��
			iterBullet = vecBulletOfRole.erase(iterBullet);//��vecBullet��ɾ��
			goto continueLabel;//����ӵ�����ǽ�ڣ�Ӧɾ����ǰԪ�ز�����������������Ȼ��continue����break
		}
		for (std::vector<ShuiJingChong*>::iterator iterEnemy = vecEnemyOfShuiJingChong.begin(); iterEnemy != vecEnemyOfShuiJingChong.end(); iterEnemy++)
		{
			if (rectBullet.intersectsRect((*iterEnemy)->getRect()))
			{
				(*iterEnemy)->alterBloodOrShield(_role->getWeapon()->getBulletDamage());
				this->roleBulletLayer->removeChild(*iterBullet);//�ӳ�����ɾ��
				iterBullet = vecBulletOfRole.erase(iterBullet);//��vecBullet��ɾ��
				goto continueLabel;//����ӵ��������ˣ�Ӧɾ����ǰԪ�ز�����������������Ȼ��continue����break
			}
		}
		for (std::vector<KuangGong*>::iterator iterEnemy = vecEnemyOfKuangGong.begin(); iterEnemy != vecEnemyOfKuangGong.end(); iterEnemy++)
		{
			if (rectBullet.intersectsRect((*iterEnemy)->getRect()))
			{
				(*iterEnemy)->alterBloodOrShield(_role->getWeapon()->getBulletDamage());
				this->roleBulletLayer->removeChild(*iterBullet);//�ӳ�����ɾ��
				iterBullet = vecBulletOfRole.erase(iterBullet);//��vecBullet��ɾ��
				goto continueLabel;//����ӵ��������ˣ�Ӧɾ����ǰԪ�ز�����������������Ȼ��continue����break
			}
		}
		iterBullet++;
	continueLabel:
		continue;
	}
}

void BasicScene::iteratingBulletOfKuangGong(float delta)
{
	//�����ӵ��Ƿ���������ײ
	for (std::vector<BasicBullet*>::iterator iterBullet = vecBulletOfKuangGong.begin(); iterBullet != vecBulletOfKuangGong.end(); iterBullet++)
	{
		Rect rectBullet = Rect((*iterBullet)->getPosition(), (*iterBullet)->getContentSize());
		if (this->_role->getRect().intersectsRect(rectBullet))
		{
			this->_role->alterBloodOrShield((*iterBullet)->getDamage());
			this->labelOfRoleShield->setString(std::to_string(this->_role->getShield()));
			this->labelOfRoleBlood->setString(std::to_string(this->_role->getBlood()));
			this->removeChild((*iterBullet));
			vecBulletOfKuangGong.erase(iterBullet);
			break;
		}
	}
}

inline void BasicScene::addRoleShield(float delta)
{
	this->_role->increaseShieldWithTime();
	this->labelOfRoleShield->setString(std::to_string(this->_role->getShield()));
}

inline void BasicScene::addRoleBlue(float delta)
{
	this->_role->increaseBlueWithTime();
	this->labelOfRoleBlue->setString(std::to_string(this->_role->getBlue()));
}

inline void BasicScene::moveRole(float delta)
{
	float offSetX = 0.0f, offSetY = 0.0f;
	if (this->_role->_ifRoleCollided)
	{
		this->_role->setSpeed(this->_role->getNormalSpeed() * 3.0f);
	}
	if (_keyMap[EventKeyboard::KeyCode::KEY_W])
	{
		offSetY = this->_role->getSpeed();
	}
	if (_keyMap[EventKeyboard::KeyCode::KEY_S])
	{
		offSetY = -this->_role->getSpeed();
	}
	if (_keyMap[EventKeyboard::KeyCode::KEY_A])
	{
		offSetX = -this->_role->getSpeed();
	}
	if (_keyMap[EventKeyboard::KeyCode::KEY_D])
	{
		offSetX = this->_role->getSpeed();
	}
	if (offSetX == 0 && offSetY == 0)
	{
		return;
	}

	//�����һ��λ������ײ�Ļ�����return
	/*
	* �����Ʋ⣬�ƶ��Ῠ�ٵ�ԭ������ǰ��moveBy��û��������ϣ���ǽ���ٲ��ᷢ����һ��һ���ƶ��У�
	* ���������ƶ���ʱ�����֣�����Ȼ�жϻ�����ײ��û���������˶����룬����ǰ���˶���û������
	*/
	if (ifRectCollideObstacles(Rect(this->_role->getRect().origin + Vec2(offSetX, offSetY), this->_role->getRect().size)))
	{
		this->_role->_ifRoleCollided = true;
		this->_role->stopAllActions();
		
		return;
	}
	this->_role->_ifRoleCollided = false;
	if (!_role->startCalculateSkillCD)
	{
		this->_role->setNormalSpeed();
	}
	
	MoveBy* moveBy = MoveBy::create(delta, Vec2(offSetX, offSetY));
	this->_role->runAction(moveBy);
}

inline bool BasicScene::ifRectCollideObstacles(cocos2d::Rect& nextRect)
{
	for (std::vector<Rect>::iterator iterObstacle = vecObstacle.begin(); iterObstacle != vecObstacle.end(); iterObstacle++)
	{
		if (nextRect.intersectsRect(*iterObstacle))
		{
			return true;
		}
	}
	return false;
}

void BasicScene::setInitialLocation(const std::string& strLocation)
{
	if (strLocation == "left")
	{
		_role->setPosition(Vec2LeftPosition);
	}
	else if (strLocation == "right")
	{
		_role->setPosition(Vec2RightPosition);
	}
}
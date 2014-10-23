
#include "Player.h"
#include "TollgateScene.h"
#include "MonsterManager.h"

#include "editor-support/cocostudio/CCSGUIReader.h"
using namespace cocostudio;


Scene* TollgateScene::createScene()
{
	auto scene = Scene::create();

	auto layer = TollgateScene::create();

	scene->addChild(layer);
	return scene;
}

bool TollgateScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//��Ϸ����
	Sprite* titleSprite = Sprite::create("title.png");
	titleSprite->setPosition(Point(visibleSize.width/2,visibleSize.height-50));
	this->addChild(titleSprite,2);


	//��������
	m_player = Player::create();
	m_player->bindSprite(Sprite::create("Players.png"),true);
	m_player->setPosition(Point(200,visibleSize.height / 4));
	this->addChild(m_player,3);

	//��ʼ������
	initBG();

	loadUI();

	//�������������
	MonsterManager* monsterMgr = MonsterManager::create();
	this->addChild(monsterMgr,4);
	monsterMgr->bindPlayer(m_player);


	this->scheduleUpdate();


	m_iScore = 0;
	return true;
}

void TollgateScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	m_bgSprite1 = Sprite::create("tollgateBG.jpg");
	m_bgSprite1->setPosition(Point(visibleSize.width / 2,visibleSize.height / 2));
	this->addChild(m_bgSprite1,0);


	m_bgSprite2 = Sprite::create("tollgateBG.jpg");
	m_bgSprite2->setPosition(Point(visibleSize.width + visibleSize.width / 2,visibleSize.height / 2));
	m_bgSprite2->setFlipX(true);    //ˮƽ��ת����
	this->addChild(m_bgSprite2,0);
}


void TollgateScene::update(float delta)
{
	int posX1 = m_bgSprite1->getPositionX();
	int posX2 = m_bgSprite2->getPositionX();

	int iSpeed = 1;  //��ͼ����

	//���ŵ�ͼ������������ŵ�ͼ�����ڵģ�����Ҫһ��������������ֿ�϶��
	posX1 -= iSpeed;
	posX2 -= iSpeed;

	Size mapSize = m_bgSprite1->getContentSize();

	/*����һ����ͼ��ȫ�뿪��Ļ��ʱ�򣬵ڶ�����ͼ�պ���ȫ��������Ļ��
	��ʱ����õ�һ����ͼ�����ڵڶ�����ͼ����*/
	if(posX1 <= -mapSize.width /2)
	{
		posX1 = mapSize.width + mapSize.width / 2;
	}


	/*ͬ�����ڶ�����ͼ��ȫ�뿪��Ļʱ����һ����ͼ�պ���ȫ��������Ļ�ϣ�
		��ʱ����õڶ�����ͼ�����ڵ�һ����ͼ����*/
	if(posX2 <= -mapSize.width /2)
	{
		posX2 = mapSize.width + mapSize.width / 2;
	}

	m_bgSprite1->setPositionX(posX1);
	m_bgSprite2->setPositionX(posX2);


	//���ӷ���
	m_iScore += 1;
	m_scoreLab->setText(Value(m_iScore).asString());

	//�޸�Ѫ����
	m_hpBar->setPercent(m_player->getiHp() / 1000.0f *100);

}


void TollgateScene::loadUI()
{
	//����UI
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("LittleRunnerUI/LittleRunnerUI_1.ExportJson");
    this->addChild(UI);


	//��ȡ�ؼ�����
	auto jumpBtn = (Button*)Helper::seekWidgetByName(UI,"JumpBtn");
	m_scoreLab = (Text*)Helper::seekWidgetByName(UI,"scoreLab");
	m_hpBar = (LoadingBar*)Helper::seekWidgetByName(UI,"hpProgress");



	//��ӵ�������
	jumpBtn->addTouchEventListener(this,toucheventselector(TollgateScene::jumpEvent));
}

void TollgateScene::jumpEvent(Ref*,TouchEventType type)
{
	switch (type)
	{
	case  TouchEventType::TOUCH_EVENT_ENDED:
		m_player->jump();
		break;
	}
}


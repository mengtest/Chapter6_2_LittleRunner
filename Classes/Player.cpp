#include "Player.h"
#include "FlowWord.h"


Player::Player()
{
	m_isJumping = false;

	m_iHp = 1000;  //��ʼѪ��
}

Player::~Player()
{
}



bool Player::init()
{
	return true;
}

void Player::jump()
{
	if (getSprite() == NULL)
	{
		return;
	}
    
	if (m_isJumping)
	{
		return;
	}


	m_isJumping = true;


	auto jump = JumpBy::create(2.0f,Point(0,0),250,1);

	auto callFunc = CallFunc::create([&](){
		m_isJumping = false;
	});

	auto jumpActions = Sequence::create(jump,callFunc,NULL);

	this->runAction(jumpActions);

}

void Player::hit()
{
	if (getSprite() == NULL)
	{
		return;
	}

	//��ѪƮ����Ч
	FlowWord* flowWord = FlowWord::create();
	this->addChild(flowWord);
	flowWord->showWord("-15",getSprite()->getPosition());


	m_iHp -= 15;
	if (m_iHp < 0)
	{
		m_iHp = 0;
	}

	//�������ֶ�������
	auto backMove = MoveBy::create(1.0f,Point(-20,0));
	auto forwardMove = MoveBy::create(0.1f,Point(20,0));
	auto backRotate = RotateBy::create(0.1f,-5,0);
	auto forwardRotate = RotateBy::create(0.1f,5,0);


	//�ֱ���ϳ����ֶ���
	auto backActions = Spawn::create(backMove,backRotate,NULL);
	auto forwardActions = Spawn::create(forwardMove,forwardRotate,NULL);

	auto actions = Sequence::create(backRotate,forwardRotate,NULL);

	stopAllActions();   //��ֹͣ��������ִ�еĶ���
	resetData();        //��������
	runAction(actions); //ִ�ж���

}


void Player::resetData()
{
	if (m_isJumping)
	{
		m_isJumping = false;
	}
	setPosition(Point(200,140));
	setScale(1.0f);
	setRotation(0);
}
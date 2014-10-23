#include "Monster.h"

Monster::Monster()
{
	m_isAlive = false;
}

Monster::~Monster()
{

}

bool Monster::init()
{
	return true;
}

void Monster::show()
{
	if (getSprite() != NULL)
	{
	    setVisible(true);
		m_isAlive = true;
	}
}

void Monster::hide()
{
	if (getSprite() != NULL)
	{
		setVisible(false);
		reset();
		m_isAlive = false;
	}
}

void Monster::reset()
{
	if (getSprite() != NULL)
	{
		setPosition(Point(1024 + CCRANDOM_0_1() *2000,300 - CCRANDOM_0_1() * 100));
	}
}

bool Monster::isCollideWithPlayer(Player* player)
{
	//获取碰撞检查对象的boundingBox
	Rect entityRect = player->getBoundingBox();

	Point monsterPos = getPosition();

	//判断boundingBox 和怪物中心是否有交集
	return entityRect.containsPoint(monsterPos);
}
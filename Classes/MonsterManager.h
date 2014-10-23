#ifndef _MONSTER_MANAGEER_H
#define _MONSTER_MANAGEER_H


#include "cocos2d.h"
#include "Monster.h"
USING_NS_CC;
#define MAX_MONSTER_NUM  10   //����������� 



class MonsterManager :public Node
{
public:
	CREATE_FUNC(MonsterManager);
	virtual bool init();

	virtual void update(float dt);


public:
	//����Ҷ���
	void bindPlayer(Player* player);

private:
	void createMonsters();
	Player* m_player;
private:
	Vector<Monster*> m_monsterArr;

};


#endif
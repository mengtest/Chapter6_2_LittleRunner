#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

#define JUMP_ACTION_TAG = 1

class Player :public Entity
 {
public:
    Player();
	~Player();

	CREATE_FUNC(Player);
	virtual bool init();

 public:
	 void jump();   //��Ծ����

 private:
	 bool m_isJumping; //��������Ƿ�������Ծ
};

#endif
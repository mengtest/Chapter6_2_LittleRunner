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
	 void jump();   //跳跃函数
	 void hit();    //玩家受伤
	 void resetData();

	 inline int getiHp(){return m_iHp;};

 private:
	 bool m_isJumping; //标记主角是否正在跳跃
	 int m_iHp;        //主角血量
};

#endif
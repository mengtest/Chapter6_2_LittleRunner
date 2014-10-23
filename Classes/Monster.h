#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "Entity.h"

class Monster : public Entity
{
public:
    Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();

public:
	void show();     //显示怪物
	void hide();     //隐藏怪物
	void reset();    //重置怪物数据
	inline bool isAlive(){ return m_isAlive();};  //是否活动状态

private:
	bool m_isAlive;

};



#endif
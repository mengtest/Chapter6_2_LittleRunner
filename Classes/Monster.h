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
	void show();     //��ʾ����
	void hide();     //���ع���
	void reset();    //���ù�������
	inline bool isAlive(){ return m_isAlive();};  //�Ƿ�״̬

private:
	bool m_isAlive;

};



#endif
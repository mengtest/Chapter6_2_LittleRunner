
#ifndef _ENTITY_H
#define _ENTITY_H

#include "cocos2d.h"
USING_NS_CC;

class Entity : public Node
{
public:
	Entity();
	~Entity();
	Sprite* getSprite();
	void bindSprite(Sprite* sprite,bool bFlippedX);


private:
	Sprite* m_sprite;

};




#endif
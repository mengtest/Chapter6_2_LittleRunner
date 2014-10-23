#include "Entity.h"

Entity::Entity()
{
	m_sprite = NULL;
}

Entity::~Entity()
{

}

Sprite* Entity::getSprite()
{
	return this->m_sprite;
}

void Entity::bindSprite(Sprite* sprite,bool bFlippedX)
{
	sprite->setFlippedX(bFlippedX);
	this->m_sprite = sprite;
	this->addChild(m_sprite);
}


#ifndef _TOLLGATESCENE_H
#define _TOLLGATESCENE_H

#include "cocos2d.h"
USING_NS_CC;

#include "editor-support/cocostudio/CCSGUIReader.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
using namespace cocostudio;


class Player;
class TollgateScene : public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TollgateScene);

	virtual void update(float delta);

private:
	void initBG();
	void loadUI();   //¼ÓÔØUI
	void jumpEvent(Ref*,TouchEventType type);
	
private:
	Sprite* m_bgSprite1;   //±³¾°¾«Áé1
	Sprite* m_bgSprite2;   //±³¾°¾«Áé2

	Player* m_player;      //Ö÷½Ç

};




#endif
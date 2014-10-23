
#ifndef _TOLLGATESCENE_H
#define _TOLLGATESCENE_H

#include "cocos2d.h"
USING_NS_CC;


#include "ui/CocosGUI.h"
using namespace cocos2d::ui;


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
	void loadUI();   //加载UI
	void jumpEvent(Ref*,TouchEventType type);
	
private:
	Sprite* m_bgSprite1;   //背景精灵1
	Sprite* m_bgSprite2;   //背景精灵2

	Player* m_player;      //主角

private:
	int m_iScore;         //分数
	Text* m_scoreLab;     //分数标签
	LoadingBar* m_hpBar;  //血量条 
};




#endif
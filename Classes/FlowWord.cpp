
#include "FlowWord.h"

FlowWord* FlowWord::create() 
{  
	FlowWord* flowWord = new FlowWord();  

	if(flowWord && flowWord->init()) 
	{  
		flowWord->autorelease();  
	}  
	else
	{  
		CC_SAFE_DELETE(flowWord);  
	}  

	return flowWord;  
} 

bool FlowWord::init() 
{  
	m_textLab = CCLabelTTF::create("", "Arial", 35);  
	m_textLab->setColor(ccc3(255, 0, 0));  
	m_textLab->setAnchorPoint(ccp(1, 0));  
	m_textLab->setVisible(false);  

	this->addChild(m_textLab);  
	return true;  
}  

void FlowWord::showWord( const char* text, CCPoint pos ) 
{  
	m_textLab->setString(text);  
	m_textLab->setPosition(pos);  
	m_textLab->setVisible(true);  

	/* 组合两个动作，放大后缩小 */  
	auto scaleLarge = CCScaleTo::create(0.3f, 2.5f, 2.5f);  
	auto scaleSmall = CCScaleTo::create(0.5f, 0.5f, 0.5f);  

	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::flowEnd));  

	auto actions = CCSequence::create(scaleLarge, scaleSmall, callFunc, NULL);  

	m_textLab->runAction(actions);  
}  

void FlowWord::flowEnd() {  
	/* 动作结束，从父节点中删除自身 */  
	m_textLab->setVisible(false);  
	m_textLab->removeFromParentAndCleanup(true);  
}  


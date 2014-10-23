#ifndef _FLOW_WORD_H_
#define _FLOW_WORD_H_

#include "cocos2d.h"
USING_NS_CC;


class FlowWord :public Node
{

public:  
	static FlowWord* create();  
	bool init();  

public:  
	void showWord(const char* text, CCPoint pos);  
private:  
	CCLabelTTF* m_textLab;  

	void flowEnd(); 
};

#endif
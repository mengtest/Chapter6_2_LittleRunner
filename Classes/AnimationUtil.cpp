#include "AnimationUtil.h"







Animation* AnimationUtil::createWithSingleFrameName(const char* name,float delay,int iLoops)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame;

	int index = 1;
	do 
	{
		frame = cache->getSpriteFrameByName(StringUtils::format("%s%d.png",name,index++));
		if (frame == NULL)
		{
			break;
		}
		frameVec.pushBack(frame);
	} while (true);

   Animation* animation = Animation::createWithSpriteFrames(frameVec);
   animation->setLoops(iLoops);
   animation->setRestoreOriginalFrame(true);
   animation->setDelayPerUnit(delay);
   return animation;
}






Animation* AnimationUtil::createWithFrameNameAndNum(const char* name,int iNum,float delay,int iLoops)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = NULL;

	int index = 1;
	for (int i = 1; i <= iNum; i++)
	{
		frame = cache->getSpriteFrameByName(StringUtils::format("%s%d.png",name,i));

		if (frame == NULL)
		{
			break;
		}
		frameVec.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}
#pragma once
/**
@file AnimationSet.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/ParameterAnimation/Animation/Animation.h"
#include "Common/ParameterAnimation/Timelines/TimelineBase.h"

#include <vector>


/**@brief */
class AnimationSet
{
private:
protected:
	std::vector< Animation* >			m_animations;
	std::vector< Ptr< TimelineBase > >	m_timelines;

public:
	explicit		AnimationSet() = default;
	~AnimationSet() = default;

};




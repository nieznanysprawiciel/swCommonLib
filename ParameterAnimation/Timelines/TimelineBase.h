#pragma once
/**
@file TimelineBase.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/ParameterAnimation/Timelines/TimelineTypes.h"

/**@defgroup Timelines Timelines
@ingroup KeyFrameAnimation*/




/**@brief 

@ingroup Timelines*/
class TimelineBase
{
private:
protected:

	TimeType		m_currentTime;

public:
	explicit		TimelineBase() = default;
	~TimelineBase() = default;


	
	virtual void		Update	( TimeType time )				= 0;
	virtual void		Start	( TimeType time )				= 0;
	virtual void		Stop	( TimeType time )				= 0;
	virtual void		Pause	( TimeType time )				= 0;

	void				Update	( TimelineBase* parent );


	inline TimeType		GetTime	()			{ return m_currentTime; };
};



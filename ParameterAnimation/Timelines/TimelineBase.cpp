#pragma once
/**
@file TimelineBase.cpp
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "TimelineBase.h"


// ================================ //
//
void		TimelineBase::Update	( TimelineBase* parent )
{
	Update( parent->GetTime() );
}

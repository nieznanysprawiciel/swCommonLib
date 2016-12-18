#pragma once
/**
@file AnimEvaluator.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/ParameterAnimation/Parameters/ParamAddress.h"
#include "Common/ParameterAnimation/KeySet.h"
#include "Common/ParameterAnimation/Timelines/TimelineBase.h"



/**@brief */
template< typename KeyType, typename AddressType >
class AnimEvaluator
{
private:
	KeySet< KeyType >						m_keys;
	ParamAddress< KeyType, AddressType >	m_param;

protected:
public:
	explicit		AnimEvaluator() = default;
	~AnimEvaluator() = default;


	void				Evaluate	( void* object, TimeType time );
	void				Evaluate	( void* object, TimelineBase* timeline );

};



//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
template< typename KeyType, typename AddressType >
inline void			AnimEvaluator< KeyType, AddressType >::Evaluate		( void* object, TimeType time )
{

}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline void			AnimEvaluator< KeyType, AddressType >::Evaluate		( void* object, TimelineBase* timeline )
{
	Evaluate( object, timeline->GetTime() );
}

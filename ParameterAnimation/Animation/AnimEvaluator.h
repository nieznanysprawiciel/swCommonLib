#pragma once
/**
@file AnimEvaluator.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/EngineObject.h"

#include "Common/ParameterAnimation/Parameters/ParamAddress.h"
#include "Common/ParameterAnimation/KeySet.h"
#include "Common/ParameterAnimation/Timelines/TimelineBase.h"



/**@brief */
template< typename KeyType, typename AddressType >
class AnimEvaluator
{
private:
	KeySet< KeyType >			m_keys;
	AddressType					m_param;

protected:
public:
	/// Constructor for serialization only.
	explicit		AnimEvaluator	() = default;
	explicit		AnimEvaluator	( EngineObject* object, const std::string& propertyPath );
					~AnimEvaluator	() = default;


	void				Evaluate	( EngineObject* object, TimeType time );
	void				Evaluate	( EngineObject* object, TimelineBase* timeline );

};



//====================================================================================//
//			Implementation	
//====================================================================================//

template< typename KeyType, typename AddressType >
inline				AnimEvaluator< KeyType, AddressType >::AnimEvaluator( EngineObject* object, const std::string& propertyPath )
{ }


// ================================ //
//
template< typename KeyType, typename AddressType >
inline void			AnimEvaluator< KeyType, AddressType >::Evaluate		( EngineObject* object, TimeType time )
{

}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline void			AnimEvaluator< KeyType, AddressType >::Evaluate		( EngineObject* object, TimelineBase* timeline )
{
	Evaluate( object, timeline->GetTime() );
}

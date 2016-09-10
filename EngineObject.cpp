#include "Common/EngineObject.h"
#include "Serialization/SW/Serialization.h"




RTTR_REGISTRATION
{
    using namespace rttr;
	
	registration::class_< EngineObject >( "EngineObject" );
}

// ================================ //
//
void		EngineObject::Serialize			( ISerializer* ser ) const
{
	Serialization::DefaultSerialize( ser, this );
}

// ================================ //
//
void		EngineObject::Deserialize		( IDeserializer* deser )
{
	Serialization::DefaultDeserialize( deser, this );
}

#pragma once

#include "Common/EngineObject.h"
#include "Common/RTTR.h"
#include "Common/Serialization/Serializer.h"
#include "Common/Serialization/Deserializer.h"

#include "Common/Serialization/SW/EngineSerializationContext.h"

#include <string>


class Serialization
{
public:

	static std::vector< rttr::property >&		GetTypeFilteredProperties	( rttr::type objType, EngineSerializationContext* context );


	static bool				ShouldSave			( rttr::property& prop, MetaDataType saveFlag );
	static void				DefaultSerialize	( ISerializer* ser, const EngineObject* object );
	static void				DefaultDeserialize	( IDeserializer* deser, EngineObject* object );

	static std::string		WstringToUTF		( const std::wstring& str );
	static std::wstring		UTFToWstring		( const std::string& str );

	template< typename PropertyType >
	static PropertyType		GetPropertyValue	( rttr::property prop, const EngineObject* object );

	template< typename PropertyType >
	static void				SerializeProperty	( ISerializer* ser, rttr::property prop, const EngineObject* object );


	template<>	static void				SerializeProperty< int16 >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< uint16 >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< int32 >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< uint32 >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< int64 >	( ISerializer* ser, rttr::property prop, const EngineObject* object );

	template<>	static void				SerializeProperty< EngineObject* >		( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< DirectX::XMFLOAT2* >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< DirectX::XMFLOAT3* >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< DirectX::XMFLOAT4* >	( ISerializer* ser, rttr::property prop, const EngineObject* object );
	template<>	static void				SerializeProperty< std::wstring >		( ISerializer* ser, rttr::property prop, const EngineObject* object );


	template< typename PropertyType >
	static void				SetPropertyValue	( rttr::property prop, const EngineObject* object, PropertyType value );

	template< typename PropertyType >
	static void				DeserializeProperty	( IDeserializer* deser, rttr::property prop, const EngineObject* object );


	template<>	static void				DeserializeProperty< int16 >				( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< uint16 >				( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< int32 >				( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< uint32 >				( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< int64 >				( IDeserializer* deser, rttr::property prop, const EngineObject* object );

	template<>	static void				DeserializeProperty< DirectX::XMFLOAT2* >	( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< DirectX::XMFLOAT3* >	( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< DirectX::XMFLOAT4* >	( IDeserializer* deser, rttr::property prop, const EngineObject* object );
	template<>	static void				DeserializeProperty< std::wstring >			( IDeserializer* deser, rttr::property prop, const EngineObject* object );

	//template<>	static  EngineObject*		DeserializeProperty< EngineObject* >		( IDeserializer* deser, rttr::property prop, const EngineObject* object );
};

#include "Serialization.inl"
#pragma once
/**
@file StringPropertyPath.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/



/**@brief */
template< typename KeyType >
class StringPropertyPath
{
private:
	std::string		m_path;

protected:
public:
	explicit		StringPropertyPath	();
	explicit		StringPropertyPath	( EngineObject* object, const std::string& propertyPath );
					~StringPropertyPath	() = default;

};


//====================================================================================//
//			Implementation	
//====================================================================================//


// ================================ //
//
template< typename KeyType >
inline		StringPropertyPath< KeyType >::StringPropertyPath()
	:	m_path( "" )
{}

// ================================ //
//
template< typename KeyType >
inline		StringPropertyPath<	KeyType >::StringPropertyPath( EngineObject* object, const std::string& propertyPath )
	:	m_path( propertyPath )
{}

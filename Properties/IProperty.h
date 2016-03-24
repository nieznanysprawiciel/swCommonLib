#pragma once



class IProperty
{
private:
	
	const char*		m_name;		///< Nazwa w³aœciwoœci, po której mo¿na siê do niej odwo³ywaæ.
	const char*		m_type;		///< Typ w³aœciwoœci identyfikowany wskaŸnikiem na strukturê typeinfo. (mo¿e siê zmieniæ w przysz³oœci)

	bool			m_serializable;
	bool			m_showInEditor;

public:
	const char*		GetPropertyName()		{ return m_name; }
	const char*		GetPropertyType()		{ return m_type; }
};

#define _CRT_SECURE_NO_WARNINGS
#include <cstring> // for strcpy
#include "guitarString.h"

namespace seneca
{
	GuitarString::GuitarString()
	{
		m_gauge = 0.0;
		m_material[0] = '\0';
	};

	GuitarString::GuitarString(const char* ma, double ga)
	{
		std::strcpy(m_material, ma);
		m_gauge = ga;
	};

	const char* GuitarString::getMaterial() const
	{
		return m_material;
	}

	double GuitarString::getGauge() const
	{
		return m_gauge;
	}
}

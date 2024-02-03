#ifndef SENECA_GUITARSTRING_H
#define SENECA_GUITARSTRING_H

namespace seneca
{
	class GuitarString
	{
		char m_material[30 + 1];
		double m_gauge;
	public:
		const char* getMaterial() const;
		double getGauge() const;
		GuitarString();
		GuitarString(const char* ma, double ga);
	};
}

#endif

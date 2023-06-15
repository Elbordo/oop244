/* ------------------------------------------------------
Workshop 8 part 1
Author	Maksym Sorokan
ID 106544208
Date 22.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line()
	{
		m_length = 0;
	}
	Line::Line(const char* str, int length) : LblShape(str)
	{
		m_length = length;
	}
	void Line::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(100, '\n');
	}
	void Line::draw(ostream& ostr) const
	{
		int l = m_length;
		if (l > 0 && label() != nullptr)
		{
			ostr << label() << '\n';
			for (int i = 0; i < l; i++)
			{
				ostr << '=';
			}
		}
	}
}
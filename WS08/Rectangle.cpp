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
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* str, int weight, int height) : LblShape(str)
	{
		m_width = weight;
		m_height = height;
		int l = strlen(label()) + 2;
		if (m_height < 3 && m_width < l)
		{
			m_width = 0;
			m_height = 0;
		}
	}
	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(100, ',');
		is >> m_height;
		is.ignore(100, '\n');
		int l = strlen(label()) + 2;
		if (m_height < 3 && m_width < l)
		{
			m_width = 0;
			m_height = 0;
		}
	}
	void Rectangle::draw(ostream& ostr)const
	{
		if (m_width > 0 && m_height > 0 && label() != nullptr)
		{
			int i, j;
			ostr << "+";
			for (i = 0; i < m_width - 2; i++)
			{
				ostr << '-';
			}
			ostr << "+" << "\n";
			ostr << "|";
			ostr << left;
			int w = m_width - 2;
			ostr.width(w);
			ostr << label();
			ostr << "|" << "\n";
			for (i = 0; i < m_height - 3; i++)
			{
				ostr << "|";
				for (j = 0; j < m_width - 2; j++)
				{
					ostr << " ";
				}
				ostr << "|" << "\n";
			}
			ostr << "+";
			for (i = 0; i < m_width - 2; i++)
			{
				ostr << '-';
			}
			ostr << "+";
		}
	}
}
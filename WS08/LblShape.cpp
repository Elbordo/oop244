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
#include "LblShape.h"
using namespace std;
namespace sdds {
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape()
	{
		m_label = nullptr;
	}
	LblShape::LblShape(const char* str)
	{
		m_label = new char[strlen(str) + 1];
		strcpy(m_label, str);
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	void LblShape::getSpecs(istream& istr)
	{
		char str[40];
		istr.get(str, 40, ',');
		delete[] m_label;
		m_label = new char[strlen(str) + 1];
		strcpy(m_label, str);
		istr.ignore(100, ',');
	}
}
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
#include "Shape.h"
using namespace std;
namespace sdds {
	ostream& operator<<(ostream& ostr, const Shape& s1)
	{
		s1.draw(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Shape& s1)
	{
		s1.getSpecs(istr);
		return istr;
	}
}
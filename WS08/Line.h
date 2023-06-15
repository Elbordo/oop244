/* ------------------------------------------------------
Workshop 8 part 1
Author	Maksym Sorokan
ID 106544208
Date 22.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"

using namespace std;
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* str, int length);
		void getSpecs(istream& istr);
		void draw(ostream& ostr) const;
	};
}
#endif
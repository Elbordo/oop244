/* ------------------------------------------------------
Workshop 8 part 1
Author	Maksym Sorokan
ID 106544208
Date 22.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual void draw(ostream& ostr) const = 0;
		virtual void getSpecs(istream& istr) = 0;
		virtual ~Shape() {};
	};
	ostream& operator<<(ostream& ostr, const Shape& s1);
	istream& operator>>(istream& istr, Shape& s1);
}

#endif
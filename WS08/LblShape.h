/* ------------------------------------------------------
Workshop 8 part 1
Author	Maksym Sorokan
ID 106544208
Date 22.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
	private:
		char* m_label{};
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* str);
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		~LblShape();
		void getSpecs(istream& istr);
	};
}
#endif

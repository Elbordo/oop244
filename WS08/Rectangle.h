/* ------------------------------------------------------
Workshop 8 part 1
Author	Maksym Sorokan
ID 106544208
Date 22.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
using namespace std;

namespace sdds {
    class Rectangle : public LblShape {
    private:
        int m_width;
        int m_height;
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void getSpecs(istream& istr);
        void draw(ostream& ostr) const;
    };
}

#endif
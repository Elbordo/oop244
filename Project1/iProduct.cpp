/* Citation and Sources...
Final Project Milestone 5.6
Module: iProducts
Filename: iProducts.cpp
Version 1.0
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/04/01  Preliminary release
2022/04/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "iProduct.h"
using namespace std;
namespace sdds {
	ostream& operator << (ostream& ostr, const iProduct& prod) {
		prod.display(ostr);
			return ostr;
	}
	istream& operator >> (istream& istr, iProduct& prod) {
		prod.read(istr);
		return istr;
	}
}
/* Citation and Sources...
Final Project Milestone 5.6
Module: Status
Filename: Status.h
Version 1.0
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/18  Preliminary release
2022/03/18  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <fstream>
#include <ostream>
#include <istream>
#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;
namespace sdds {
	class Status {
		char* description{};
		int Code;
		void setEmpty();
	public:
		void set(const char* desc, int c = 0);
		Status();
		Status(const char* desc, int c = 0);
		Status(const Status& st);
		Status& operator=(const Status& st);
		~Status();
		Status& clear();
		Status& operator=(int c);
		Status& operator=(const char* desc);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		ostream& print(ostream& ostr) const;
		friend ostream& operator<<(ostream& ostr, const Status& st);
	};
	ostream& operator<<(ostream& ostr, const Status& st);
}

#endif
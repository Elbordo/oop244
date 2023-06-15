/* Citation and Sources...
Final Project Milestone 5.6
Module: Status
Filename: Status.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Utils.h"
#include "Status.h"
using namespace std;
namespace sdds {
	void Status::setEmpty() {
		description = nullptr;
		Code = 0;
	}
	void Status::set(const char* desc, int c) {
		if (desc != nullptr) {	
			ut.alocpy(description, desc);
			Code = c;
		}
		else {
			setEmpty();
		}
	}
	Status::Status() {
		setEmpty();
	}
	Status::Status(const char* desc, int c) {
		set(desc, c);
	}
	Status::Status(const Status& st) {
		if (!st) set(st.description, st.Code);
	}
	Status& Status::operator=(const Status& st) {
		if (this != &st) set(st.description, st.Code);
		return *this;
	}
	Status::~Status() {
		delete[] description;
		description = nullptr;
	}
	Status& Status::clear() {
		delete[] description;
		setEmpty();
		return *this;
	}
	Status& Status::operator=(int c) {
		Code = c;
		return *this;
	}
	Status& Status::operator=(const char* desc) {
		ut.alocpy(description, desc);
		return *this;
	}
	Status::operator int() const {
		return Code;
	}
	Status::operator const char* () const {
		return description;
	}
	Status::operator bool() const {
		if (description == nullptr)return true;
		else return false;
	}
	ostream& Status::print(ostream& ostr) const {
		if (Code == 0) ostr << description;
		else ostr << "ERR#" << Code << ": " << description;
		return ostr;
	}
	ostream& operator<<(ostream& ostr, const Status& st) {
		if (!st) st.print(ostr);
		return ostr;
	}



}
/* ------------------------------------------------------
Workshop 9 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
#include "Text.h"
using namespace std;
namespace sdds {
	void Text::setEmpty() {
		m_content = nullptr;
	}
	const char& Text::operator[](int index)const {
		return m_content[index];
	}
	Text::Text() {	
		setEmpty();
    }
	void Text::set(const char* content) {	
		delete[] m_content;
		setEmpty();
		if (content != nullptr) {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
	}
	Text::Text(const Text& t1) {
		set(t1.m_content);
	}

	Text& Text::operator=(const Text& t1) {
		if (this != &t1) set(t1.m_content);
		return *this;
	}
	Text::~Text() {
		delete[] m_content;
	}
	istream& Text::read(istream& istr) {
		delete[] m_content;
		m_content = new char[getFileLength(istr) +1];
		istr.get(m_content, getFileLength(istr) + 1, '\0');
		if (!istr.fail()) istr.clear();
		return istr;
	}
	int Text::getFileLength(std::istream& is) {
		int len{};
		if (is) {
			std::streampos cur = is.tellg();
			is.seekg(0, ios::end);
			len = is.tellg();
			is.seekg(cur);
		}
		return len;
	}
	istream& operator>>(istream& istr, Text& t1) {
		t1.read(istr);
		return istr;
    }
	ostream& operator<<(ostream& ostr, const Text& t1) {
		t1.write(ostr);
		return ostr;
    }
}
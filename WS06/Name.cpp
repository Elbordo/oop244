/* ------------------------------------------------------
Workshop 6 part 2
Author	Maksym Sorokan
ID 106544208
Date 08.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Name.h"
using namespace std;
namespace sdds {
	void Name::setEmpty() {
		m_fname = nullptr;
		m_mname = nullptr;
		m_lname = nullptr;
	}
	void Name::allocateFname(const char* name) {
		delete[] m_fname;
		m_fname = new char[strlen(name) + 1];
		strcpy(m_fname, name);
	}
	void Name::allocateMname(const char* name) {
		delete[] m_mname;
		m_mname = new char[strlen(name) + 1];
		strcpy(m_mname, name);
	}
	void Name::allocateLname(const char* name) {
		delete[] m_lname;
		m_lname = new char[strlen(name) + 1];
		strcpy(m_lname, name);
	}
	void Name::setf(const char* f) {	
		if (f == nullptr) setEmpty();
		else allocateFname(f);
	}
	void Name::setfl(const char* f, const char* l) {
		if (f == nullptr && l == nullptr) setEmpty();
		else {
			allocateFname(f);
			allocateLname(l);
		}
	}
	void Name::setfml(const char* f, const char* m, const char* l) {
		if (f == nullptr && m == nullptr && l == nullptr) setEmpty();
		else {
			allocateFname(f);
			allocateMname(m);
			allocateLname(l);
		}
	}
	Name::Name() {
		setEmpty();
	}
	Name::Name(const char* f) {
		if (f == nullptr) setEmpty();
		else allocateFname(f);
	}
	Name::Name(const char* f, const char* l) {
		if (f == nullptr && l == nullptr) setEmpty();
		else {
			allocateFname(f);
			allocateLname(l);
		}
	}
	Name::Name(const char* f, const char* m, const char* l) {
		if (f == nullptr && m == nullptr && l == nullptr) setEmpty();
		else {
			if (f != nullptr) allocateFname(f);
			if (m != nullptr) allocateMname(m);
			if (l != nullptr) allocateLname(l);
		}
	}
	Name::Name(const Name& n1) {
		if (n1) {
			if (n1.m_fname != nullptr && n1.m_mname != nullptr && n1.m_lname != nullptr) setfml(n1.m_fname, n1.m_mname, n1.m_lname);
			else if (n1.m_mname == nullptr && n1.m_lname == nullptr) setf(n1.m_fname);
			else if (n1.m_mname == nullptr) setfl(n1.m_fname, n1.m_lname);
		}
	}
	Name& Name::operator=(const Name& n1) {
		if (this != &n1) setfml(n1.m_fname, n1.m_mname, n1.m_lname);
		return *this;
	}
	Name::~Name() {
		delete[] m_fname;
		delete[] m_mname;
		delete[] m_lname;
	}
	void Name::setShort(bool flag) {
		if (flag) {
			if (m_mname != nullptr) {
				int j = strlen(m_mname);
				m_mname[1] = '.';
				for (int i = 2; i <= j; i++){
					m_mname[i] = '\0';
				}
			}
		}
	}
	Name& Name::operator+=(const char* c) {
		bool flag = false;
		if (c[0] == '\0' || c[0] == ' ') flag = false;
		else  flag = true; 
		if (!flag) {			
			m_mname = nullptr;
			m_lname = nullptr;
		}
		if (flag) {
			if (m_fname == nullptr) allocateFname(c);
			else if (m_mname == nullptr) allocateMname(c);
			else if (m_lname == nullptr) allocateLname(c);
			else { 
				delete[] m_fname;
				delete[] m_mname;
				delete[] m_lname;
				setEmpty(); 
			}
		}
		return *this;
	}
	Name::operator bool() const {
		return m_fname != nullptr;
	}
	ostream& Name::print(ostream& ostr) const {
		if (m_fname != nullptr && m_mname != nullptr && m_lname != nullptr) ostr << m_fname << " " << m_mname << " " << m_lname;
		if (m_fname != nullptr && m_mname != nullptr && m_lname == nullptr) ostr << m_fname << " " << m_mname;
		if (m_fname != nullptr && m_mname == nullptr && m_lname != nullptr) ostr << m_fname << " " << m_lname;
		if (m_fname != nullptr && m_mname == nullptr && m_lname == nullptr) ostr << m_fname;
		return ostr;
	}
	istream& Name::read(istream& istr) {
		string str1;
		string str2;
		string str3;
		delete[] m_fname;
		delete[] m_mname;
		delete[] m_lname;
		setEmpty();
		if (isspace(istr.peek())) {
			istr.ignore();
		}
		istr >> str1;
		if (istr.peek() == ' ') {
			istr.ignore();
			istr >> str2;
			if (istr.peek() == ' ') {
				istr.ignore();
				istr >> str3;
				if (istr.peek() == '\n') setfml(str1.c_str(), str2.c_str(), str3.c_str());
				else {
					delete[] m_fname;
					delete[] m_mname;
					delete[] m_lname;
					setEmpty();
				}
			}
			else setfl(str1.c_str(), str2.c_str());
		}
		else setf(str1.c_str());
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Name& n1) {
		if (n1) n1.print(ostr);
		else cout << "Bad Name";
		return ostr;
	}
	istream& operator>>(istream& istr, Name& n1) {
		return n1.read(istr);
	}
}
/* ------------------------------------------------------
Workshop 6 part 2
Author	Maksym Sorokan
ID 106544208
Date 08.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <fstream>
#include <ostream>
#include <istream>
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
	class Name {
	private:
		char* m_fname{};
		char* m_mname{};
		char* m_lname{};
		void setEmpty();
		void allocateFname(const char* name);
		void allocateMname(const char* name);
		void allocateLname(const char* name);
		void setf(const char* f);
		void setfl(const char* f, const char* l);
		void setfml(const char* f, const char* l, const char* m);	
	public:	
		Name(const char* f);
		Name(const char* f, const char* l);
		Name(const char* f, const char* m, const char* l);
		Name();
		Name(const Name& n1);
		Name& operator=(const Name& n1);
		~Name();
		void setShort(bool flag);
		Name& operator+=(const char* c);
		operator bool() const;
		ostream& print(ostream& ostr) const;
		istream& read(istream& istr);
	};
	ostream& operator<<(ostream& ostr, const Name& n1);
	istream& operator>>(istream& istr, Name& n1);
}
#endif 
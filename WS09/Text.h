/* ------------------------------------------------------
Workshop 9 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_
#include <iostream>
#include <fstream>
#include <ostream>
#include <istream>
using namespace std;
namespace sdds{
	class Text {
	private:
		char* m_content{};
		void setEmpty();
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		void set(const char* content);
		Text(const Text& t1);
		Text& operator=(const Text& t1);
		~Text();
		virtual ostream& write(ostream& ostr) const {
			if (m_content != nullptr) ostr << m_content;	
			return ostr;
		}
		istream& read(istream& istr);
		int getFileLength(std::istream& is);
	};
	istream& operator>>(istream& istr, Text& t1);
	ostream& operator<<(ostream& ostr,const Text& t1);
}


#endif 
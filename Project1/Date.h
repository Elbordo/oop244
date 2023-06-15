/* Citation and Sources...
Final Project Milestone 5.6
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "Status.h"
using namespace std;
namespace sdds {
	const int MAX_YEAR_VALUE = 2030;
	const int CURRENT_YEAR = 2022;
	class Date {
		int m_year;
		int m_mon;
		int m_day;
		Status m_state;
		bool m_formatted = true;
		bool validate();
		int uniqueDateValue() const;
		void setCurr();
	public:
		int days()const;		
		Date();
		Date(int year, int mon, int day);
		const Status& state()const;
		Date& formatted(bool flag);	
		void form(bool flag);
		bool operator==(const Date& d1)const;
		bool operator!=(const Date& d1)const;
		bool operator<(const Date& d1)const;
		bool operator>(const Date& d1)const;
		bool operator<=(const Date& d1)const;
		bool operator>=(const Date& d1)const;
		operator bool()const;
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
	};
	ostream& operator<<(ostream& ostr, const Date& d1);
	istream& operator>>(istream& istr, Date& d1);









}





#endif
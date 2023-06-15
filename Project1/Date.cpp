/* Citation and Sources...
Final Project Milestone 5.6
Module: Date
Filename: Date.cpp
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
#include <istream>
#include "Utils.h"
#include "Status.h"
#include "Date.h"
using namespace std;
namespace sdds {
	bool Date::validate() {
		int k = 0;
		if (m_year<CURRENT_YEAR || m_year>MAX_YEAR_VALUE) {
			m_state = "Invalid year in date";
			m_state = 1;
			k++;
		}
		if (m_mon < 1 || m_mon > 12) {
			m_state = "Invalid month in date";
			m_state = 2;
			k++;
		}
		if (m_day < 1 || m_day>days()) {
			m_state = "Invalid day in date";
			m_state = 3;
			k++;
		}
		if (k == 0)return true;
		else return false;
	}
	int Date::days()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 12;
		mon--;
		return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}
	int Date::uniqueDateValue() const {
		int uniq;
		return uniq = m_year * 372 + m_mon * 31 + m_day;
	}
	void Date::setCurr() {
		m_year = 2022;
		m_mon = 03;
		m_day = 31;

	}
	Date::Date() {
		m_year = 0;
		m_mon = 0;
		m_day = 0;
	}
	Date::Date(int year, int mon, int day) {
		setCurr();
		m_year = year;
		m_mon = mon;
		m_day = day;
		validate();
	}
	const Status& Date::state() const {
		return m_state;
	}
	Date& Date::formatted(bool flag) {
		m_formatted = flag;
		return *this;
	}
	void Date::form(bool flag) {
		m_formatted = flag;
	}
	bool Date::operator==(const Date& d1)const {
		if (this->uniqueDateValue() == d1.uniqueDateValue()) return true;
		else return false;
	}
	bool Date::operator!=(const Date& d1)const {
		if (this->uniqueDateValue() != d1.uniqueDateValue()) return true;
		else return false;
	}
	bool Date::operator<(const Date& d1)const {
		if (this->uniqueDateValue() < d1.uniqueDateValue()) return true;
		else return false;
	}
	bool Date::operator>(const Date& d1)const {
		if (this->uniqueDateValue() >d1.uniqueDateValue()) return true;
		else return false;
	}
	bool Date::operator<=(const Date& d1)const {
		if (this->uniqueDateValue() <= d1.uniqueDateValue()) return true;
		else return false;
	}
	bool Date::operator>=(const Date& d1)const {
		if (this->uniqueDateValue() >= d1.uniqueDateValue()) return true;
		else return false;
	}
	Date::operator bool()const {
		return m_state;
	}
	ostream& Date::write(ostream& ostr) const {
		
		if (m_formatted == true)
		{
			if (m_mon <= 9)
				ostr << m_year << "/0" << m_mon << '/' << m_day;
			else
				ostr << m_year << '/' << m_mon << '/' << m_day;
		}
		if (m_formatted == false)
		{
			int formyear = m_year - 2000;
			if (m_mon <= 9)
				ostr << formyear << "0" << m_mon << m_day;
			else
				ostr << formyear << m_mon << m_day;
		}
		return ostr;
	}
	istream& Date::read(istream& istr) {
		int k = 0,y=0,m=0,d=0;
		string str;
		istr >> str;
		
		if (isdigit(str[0]) == false) {
			istr.setstate(ios::badbit);
		}
		else {
			if (str.length() == 4) {
				k = stoi(str);
				m = k / 100 % 100;
				d = k / 1 % 100;
				m_year = CURRENT_YEAR;
				m_mon = m;
				m_day = d;
				if (!validate()) istr.setstate(ios::badbit);
			}
			if (str.length() == 6) {
				k = stoi(str);
				y = k / 10000 % 100;
				m= k / 100 % 100;
				d= k / 1 % 100;
				m_year = y+2000;
				m_mon = m;
				m_day = d;
				*this = Date(m_year, m_mon, m_day);
				if (!validate()) istr.setstate(ios::badbit);
			}
			if(str.length() == 2){
				k = stoi(str);
				d = k / 1 % 100;
				m_mon = 0;
				m_day = d;
				if (!validate()) istr.setstate(ios::badbit);
			}			
		}
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Date& d1) {
		return d1.write(ostr);
}
	istream& operator>>(istream& istr, Date& d1) {
		return d1.read(istr);
}
}
/* ------------------------------------------------------
Workshop 5 part 2
Author	Maksym Sorokan
ID 106544208
Date 19.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    Portfolio::operator double() const {
        return m_value;
    }
    Portfolio::operator const char* () const {
        return m_stock;
    }
    Portfolio::operator char() const {
        return m_type;
    }
    Portfolio::operator bool() const {
        return (m_type == 'G' || m_type == 'V' || m_type == 'I');
    }
    Portfolio& Portfolio::operator+=(double num) {
        if (*this && num > 0) {
            m_value += num;
        }
        return *this;
    }
    Portfolio& Portfolio::operator-=(double num) {
        if (*this && num > 0) {
            m_value -= num;
        }
        return *this;
    }
    bool Portfolio::operator ~() const {
        return (m_value <= -1);
    }
    Portfolio& Portfolio::operator<<(Portfolio& por) {
        if (&por && por) {
            m_value += por.m_value;
            por.emptyPortfolio();
        }
        return *this;
    }
    Portfolio& Portfolio::operator>>(Portfolio& por) {
        if (&por && por) {
            por.m_value += m_value;
            this->emptyPortfolio();
        }
        return *this;
    }
    double operator+ (const Portfolio& le, const Portfolio& ri) {
        if (&le && &ri) {
            return double(le) + double(ri);
        }
        return 0;
    }
    double operator+= (double& num, const Portfolio& por) {
        return num+=double(por);
    }


}
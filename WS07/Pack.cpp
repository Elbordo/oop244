#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Container.h"
#include "Pack.h"
using namespace std;
namespace sdds {
    Pack::Pack(const char* content, int size, int usize, int num) :Container(content, size* usize, usize* num) {
        m_size = size;
        m_usize = usize;
        m_num = num;
    }
    int Pack::operator += (int units) {
        int result = Container::operator+=(units * m_usize) / m_usize;
        m_num += result;
        return result;
    }
    int Pack::operator -= (int units) {
        int result = Container::operator-=(units * m_usize) / m_usize;
        m_num -= result;
        return result;
    }
    int Pack::unit() {
        return m_usize;
    }
    int Pack::noOfUnits() {
        return m_num;
    }
    int Pack::size() {
        return m_size;
    }
    void Pack::clear(int size, int usize, const char* content) {
        if (usize > 0) {
            Container::clear(size * usize, content);
            m_usize = usize;
            m_num = 0;
        }
    }
    ostream& Pack::print(ostream& ostr) {
        Container::print(ostr);
        if (valid()) {
            ostr << ", " << m_num << " in a pack of " << m_size;
        }

        return ostr;
    }
    istream& Pack::read(istream& in) {
        char ch;
        int units;

        if (!valid()) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
            in.ignore();
            ch = getchar();
        }
        else if (m_num == m_size) {
            in.ignore();
            cout << "Pack is full!, press <ENTER> to continue..." << endl;
            ch = getchar();
        }
        else {
            bool validValue = false;
            cout << "Add to ";
            print(cout);

            int maxVal = m_size - m_num;

            while (!validValue) {
                cout << endl << "> ";
                in >> units;

                if (units > m_size) {
                    cout << "Invalid Integer, retry: ";
                }

                else if (units < 1 || units > maxVal) {
                    cout << "Value out of range [1<=val<=" << maxVal << "]:";
                }

                else validValue = true;
            }

            units = (*this += units);
            cout << "Added " << units << endl;
        }

        return in;
    }
    istream& operator >> (istream& istr, Pack& p1) {
        return p1.read(istr);
    }
    ostream& operator << (ostream& ostr, Pack& p1) {
        return p1.print(ostr);
    }
}


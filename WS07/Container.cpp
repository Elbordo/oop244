#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Container.h"
using namespace std;
namespace sdds {
    void Container::setEmpty() {
        m_valid = false;
    }
    int Container::capacity() {
        return m_capacity;
    }
    int Container::volume() {
        return m_volume;
    }
    Container::Container(const char* content, int capacity, int volume) {
        if (content == NULL || volume > capacity) {
            m_valid = false;
        }
        else {
            strcpy(m_content, content);
            m_capacity = capacity;
            m_volume = volume;
            m_valid = true;
        }
    }
    int Container::operator += (int value) {
        if (m_volume + value <= m_capacity) {
            m_volume += value;
        }
        else {
            value = m_capacity - m_volume;
            m_volume = m_capacity;
        }
        return value;
    }
    int Container::operator -= (int value) {
        if (m_volume - value >= 0) {
            m_volume -= value;
        }
        else {
            value = m_volume;
            m_volume = 0;
        }
        return value;
    }
    bool Container::valid() {
        return m_valid;
    }
    void Container::clear(int capacity, const char* content) {
        if (capacity >= 1 && content != NULL && strlen(content) >= 1) {          
            strcpy(m_content, content);
            m_capacity = capacity;
            m_volume = 0;
            m_valid = true;
        }
    }
    ostream& Container::print(ostream& ostr) {
        if (m_valid) {
            ostr << m_content << ": (" << m_volume << "cc/" << m_capacity << ")";
        }
        else {
            ostr << "****: (**cc/***)";
        }

        return ostr;
    }
    istream& Container::read(istream& in) {
        char ch;
        int value;

        if (!m_valid) {
            cout << "Broken Container, adding aborted! Press to continue...." << endl;
            in.ignore();
            ch = getchar();
        }
        else {
            bool validValue = false;
            cout << "Add to ";
            print(cout);

            while (!validValue) {
                cout << endl << "> ";
                in >> value;

                if (value > m_capacity) {
                    cout << "Invalid Integer, retry:";
                }

                else if (value < 1 || value > 999) {
                    cout << "Value out of range [1<=val<=999]:";
                }

                else validValue = true;
            }


            value = (*this += value);
            cout << "Added " << value << " CCs" << endl;
        }

        return in;
    }
    istream& operator >> (istream& istr, Container& c1) {
        return c1.read(istr);
    }
    ostream& operator << (ostream& ostr, Container& c1) {
        return c1.print(ostr);
    }
}

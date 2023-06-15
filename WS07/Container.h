#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    class Container {
    private:
        char m_content[50];
        int m_capacity;
        int m_volume;
        bool m_valid;
    protected:
        void setEmpty();
        int capacity();
        int volume();
    public:
        Container(const char* content, int capacity, int volume = 0);
        int operator += (int value);
        int operator -= (int value);
        bool valid();
        void clear(int capacity, const char* content);
        ostream& print(ostream& ostr);
        istream& read(istream& istr);
    };
    ostream& operator << (ostream& ostr, Container& C);
    istream& operator >> (istream& istr, Container& C);
}

#endif
#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include "Container.h"
using namespace sdds;

namespace sdds {
    class Pack : public Container {
    private:
        int m_usize;
        int m_size;
        int m_num;
    public:
        Pack(const char* content, int size, int usize = 330, int num = 0);
        int operator += (int units);
        int operator -= (int units);
        int unit();
        int noOfUnits();
        int size();
        void clear(int size, int usize, const char* content);
        ostream& print(ostream& ostr);
        istream& read(istream& istr);
    };
    ostream& operator << (ostream& ostr, Pack& p1);
    istream& operator >> (istream& istr, Pack& p1);
}


#endif
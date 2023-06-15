/* Citation and Sources...
Final Project Milestone 5.6
Module: Perishable
Filename: Perishable.h
Version 1.0
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/04/03  Preliminary release
2022/04/03  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include  "Item.h"
#include "Date.h"
using namespace std;
namespace sdds {
    class Perishable : public Item {
    private:
        Date m_exdate;
        char* m_instruct{};
        void setEmpty();
    public:
        Perishable();
        Perishable(const Perishable& p1);
        Perishable& operator=(const Perishable& p1);
        ~Perishable();
        void set(const char* instruct);
        const Date& expiry();
        int readSku(istream& istr);
        ofstream& save(ofstream& ofstr);
        ifstream& load(ifstream& ifstr);
        ostream& display(ostream& ostr)const;
        istream& read(istream& istr);
    };
}
#endif
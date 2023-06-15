/* Citation and Sources...
Final Project Milestone 5.6
Module: Item
Filename: Item.h
Version 1.0
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/04/01  Preliminary release
2022/04/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "iProduct.h"
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    class Item : public iProduct {
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char* m_desc{};
        bool m_linear;
        void setEmpty();
    protected:
        Status m_state;
        int m_sku;
        bool linear()const;
    public:
        void set(double price, int qty, int Nqty, const char* m_desc,int sku);
        Item();
        Item(const Item& Item);
        Item& operator=(const Item& Item);
        ~Item();
        int qtyNeeded()const;
        int qty()const;
        operator double()const;
        operator bool()const;
        int operator += (int qty);
        int operator -= (int qty);
        void linear(bool isLinear);
        Status& clear();
        bool operator==(int sku)const;
        bool operator==(const char* desc)const;
        ofstream& save(ofstream& ofstr);
        ifstream& load(ifstream& ifstr);
        ostream& display(ostream& ostr)const;
        istream& read(istream& istr);
        int readSku(istream& istr);
    };
}
#endif
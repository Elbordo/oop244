/* Citation and Sources...
Final Project Milestone 5.6
Module: Item
Filename: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "iProduct.h"
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setEmpty() {
        m_price = 0.0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_desc = nullptr;
        m_linear = false;
    }
    bool Item::linear()const {
        return m_linear;
    }
    void Item::set(double price, int qty, int qtyNeeded, const char* desc, int sku) {
        if (desc != nullptr) {
            m_price = price;
            m_qty = qty;
            m_qtyNeeded = qtyNeeded;
            ut.alocpy(m_desc,desc);
            m_sku = sku;
        }
        else setEmpty();
    }
    Item::Item() {
        setEmpty();
    }
    Item::Item(const Item& Item) {
        if (Item.m_desc!=nullptr) set(Item.m_price, Item.m_qty, Item.m_qtyNeeded, Item.m_desc, Item.m_sku);
    }
    Item& Item::operator=(const Item& Item) {
        if (this != &Item) set(Item.m_price, Item.m_qty, Item.m_qtyNeeded, Item.m_desc, Item.m_sku);
        return *this;
    }
    Item::~Item() {
        delete[] m_desc;
    }
    int Item::qtyNeeded()const {
        return m_qtyNeeded;
    }
    int Item::qty()const {
        return m_qty;
    }
    Item::operator double()const {
        return m_price;
    }
    Item::operator bool()const {
        return m_state;
    }
    int Item::operator += (int qty) {
        m_qty += qty;
        return qty;
    }
    int Item::operator -= (int qty) {
        m_qty -= qty;
        return qty;
    }
    void Item::linear(bool isLinear) {
        m_linear = isLinear;
    }
    Status& Item::clear() {
        return m_state.clear();
    }
    bool Item::operator==(int sku)const {
        if (m_sku == sku)return true;
        else return false;
    }
    bool Item::operator==(const char* desc)const {
       if (strstr(m_desc, desc) && desc!=nullptr && m_desc!=nullptr)return true;
       else return false;
    }
    ofstream& Item::save(ofstream& ofstr) {
        if (m_state) {
            ofstr << m_sku << '\t';
            ofstr << m_desc << '\t';
            ofstr << m_qty << '\t';
            ofstr << m_qtyNeeded << '\t';
            if (m_sku >= 10000 && m_sku <= 39999) ofstr << m_price;
            else ofstr << m_price << endl;
        }
        return ofstr;
    }
    ifstream& Item::load(ifstream& ifstr)
    {
        string desc;
        if (m_desc != nullptr)
        {
            delete[] m_desc;
            m_desc = nullptr;
        }
        ifstr >> m_sku;
        ifstr.ignore(1000, '\t');
        getline(ifstr, desc, '\t');
        m_desc = new char[strlen(desc.c_str()) + 1];
        strcpy(m_desc, desc.c_str());
        ifstr >> m_qty;
        ifstr.ignore(1000, '\t');
        ifstr >> m_qtyNeeded;
        ifstr.ignore(1000, '\t');
        ifstr >> m_price;
        if (!ifstr) m_state = "Input file stream read failed!";
        ifstr.ignore();
        
        return ifstr;
    }
    ostream& Item::display(ostream& ostr)const {
        float k = m_price * (m_qtyNeeded - m_qty);
        if (!m_state) cout << m_state;
        else {
            if (m_linear) {
                ostr.setf(ios::fixed);
                ostr.width(4);
                ostr << left << m_sku << " | ";
                if(strlen(m_desc)>35) ostr.write(m_desc, 35);
                else {
                    ostr.width(35);
                    ostr << m_desc;
                }
                ostr << " | ";
                ostr.width(4);
                ostr << right << m_qty << " | ";
                ostr.width(4);
                ostr << m_qtyNeeded << " | ";;
                ostr.width(7);
                ostr << setprecision(2) << m_price << " |";
                ostr.unsetf(ios::fixed);
            }
            else {
                ostr.setf(ios::fixed);
                ostr << "AMA Item:" << endl;
                ostr << m_sku << ": " << m_desc << endl;
                ostr << "Quantity Needed: " << m_qtyNeeded << endl;
                ostr << "Quantity Available: " << m_qty << endl;
                ostr << setprecision(2) << "Unit Price: $"<< m_price << endl;
                ostr << setprecision(2) << "Needed Purchase Fund: $"<< k << endl;
                ostr.unsetf(ios::fixed);
            }
        }
        
        return ostr;
    }
    istream& Item::read(istream& istr) {
        clear();
        char desc[51];
        cout << "AMA Item:" << endl;
        cout << "SKU: " << m_sku << endl;
        cout << "Description: ";
        istr.clear();
        istr.ignore(1000, '\n');
        istr.get(desc,51,'\n');
        ut.alocpy(m_desc, desc);
        m_qtyNeeded=ut.getint(1,9999, "Quantity Needed: ");
        m_qty=ut.getint(0,m_qtyNeeded, "Quantity On Hand: ");
        m_price=ut.getdouble(0.00,9999.00, "Unit Price: $");
        return istr;
    }
    int Item::readSku(istream& istr) {
        m_sku = ut.getint(40000, 99999, "SKU: ");
        return m_sku;
    }
}
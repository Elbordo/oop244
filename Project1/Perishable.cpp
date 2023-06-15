/* Citation and Sources...
Final Project Milestone 5.6
Module: Perishable
Filename: Perishable.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "Perishable.h"
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds {
    void Perishable::setEmpty() {
        m_instruct = nullptr;
    }
    Perishable::Perishable() {
        setEmpty();
    }
    Perishable::Perishable(const Perishable& p1) {
        if (p1.m_instruct != nullptr) {
            (Item&)*this = p1;
            set(p1.m_instruct);
            m_exdate = p1.m_exdate;
        }
        else m_state = "Empty";
    }
    Perishable& Perishable::operator=(const Perishable& p1) {
        if (this != &p1) {
            (Item&)*this = p1;
            set(p1.m_instruct);
            m_exdate = p1.m_exdate;
        }
        return *this;
    }
    Perishable::~Perishable() {
        delete[] m_instruct;
    }
    void Perishable::set(const char* instruct) {
        if (instruct != nullptr) {
            ut.alocpy(m_instruct, instruct);
        }
        else {
            setEmpty();
        }
    }
    const Date& Perishable::expiry() {
        return m_exdate;
    }
    int Perishable::readSku(istream& istr) {
        m_sku = ut.getint(10000, 39999, "SKU: ");
        return m_sku;
    }
    ofstream& Perishable::save(ofstream& ofstr) {
        if (m_state) {
            Item::save(ofstr);
            ofstr << '\t';
            if (m_instruct != nullptr) ofstr << m_instruct;
            m_exdate.form(false);
            ofstr << '\t' << m_exdate << endl;
        }
        return ofstr;
    }
    ifstream& Perishable::load(ifstream& ifstr) {
        string instruction;
        Item::load(ifstr);
        if (m_instruct != nullptr)
        {
            delete[] m_instruct;
            m_instruct = nullptr;
        }
        getline(ifstr, instruction, '\t');
        m_instruct = new char[strlen(instruction.c_str()) + 1];
        strcpy(m_instruct, instruction.c_str());
        ifstr >> m_exdate;
        ifstr.ignore(1000, '\n');
        if (!ifstr)  m_state = "Input file stream read (perishable) failed!";
        return ifstr;
    }
    ostream& Perishable::display(ostream& ostr)const{
        if (!m_state) ostr << m_state;
        else { 
            if (Item::linear()) {
                Item::display(ostr);
                if (m_instruct != nullptr && strcmp(m_instruct, "")) ostr << "*";
                else ostr << ' ';             
                ostr << m_exdate;
            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                ostr << m_exdate;
                ostr << endl;
                if (m_instruct != nullptr && strcmp(m_instruct, "")) {
                    ostr << "Handling Instructions: " << m_instruct << endl;
                }
            }
        }
        return ostr;
    }
    istream& Perishable::read(istream& istr) {
        string instruct;
        Item::read(istr);
        delete[] m_instruct;
        m_instruct = nullptr;
        cout << "Expiry date (YYMMDD): ";
        istr >> m_exdate;
        istr.ignore(1000, '\n');
        cout << "Handling Instructions, ENTER to skip: ";
        if (istr.peek() != '\n') {
            getline(istr, instruct, '\n');
            m_instruct = new char[strlen(instruct.c_str()) + 1];
            strcpy(m_instruct, instruct.c_str());
        }
        if (!istr) m_state = "Perishable console date entry failed!";
        return istr;
    }
}
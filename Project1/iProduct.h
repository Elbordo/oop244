/* Citation and Sources...
Final Project Milestone 5.6
Module: iProducts
Filename: iProducts.h
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
#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H
#include <fstream>
#include <ostream>
#include <istream>
#include <iostream>
#include <string>

using namespace std;
namespace sdds
{
    class iProduct {
    public:
        virtual ~iProduct() {};
        virtual   int readSku(istream& istr) = 0;
        virtual   int operator-=(int qty) = 0;
        virtual  int operator+=(int qty) = 0;
        virtual  operator double()const = 0;
        virtual operator bool()const = 0;
        virtual int qtyNeeded()const = 0;
        virtual int qty()const = 0;
        virtual  void linear(bool isLinear) = 0;
        virtual  ofstream& save(ofstream& ofstr) = 0;
        virtual ifstream& load(ifstream& ifstr) = 0;
        virtual ostream& display(ostream& ostr)const = 0;
        virtual istream& read(istream& istr)=0;
        virtual bool operator==(int sku)const =0;
        virtual bool operator==(const char* description)const =0;
    };
    ostream& operator << (ostream& ostr, const iProduct& prod);
    istream& operator >> (istream& istr, iProduct& prod);
}
#endif
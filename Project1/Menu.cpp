/* Citation and Sources...
Final Project Milestone 5.6
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/19  Preliminary release
2022/03/19  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {
    void Menu::set(unsigned int num, const char* list) {
        if (num < 15 && list != nullptr) {
            m_num = num;
            ut.alocpy(m_list, list);
        }
        else {
            m_list = nullptr;
            m_num = 0;
        }
    }
    Menu::Menu(unsigned int num, const char* list) {
        set(num, list);
    }
    Menu::~Menu() {
        delete[] m_list;
    }
    unsigned int Menu::run() const {
        cout << m_list << "0- Exit" << endl;
        return  ut.getint(0, m_num, "> ", "Invalid Integer");
    }
}
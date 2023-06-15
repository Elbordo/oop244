/* Citation and Sources...
Final Project Milestone 5.6
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
    class Menu {
        char* m_list{};
        unsigned int m_num;
    public:
        void set(unsigned int num, const char* list);
        Menu(unsigned int num, const char* list);
        Menu& operator=(const Menu& M) = delete;
        ~Menu();
        unsigned int run() const;
    };
}


#endif
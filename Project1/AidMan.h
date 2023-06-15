/* Citation and Sources...
Final Project Milestone 5.6
Module: AidMan
Filename: AidMan.h
Version 1.6
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/19  Preliminary release
2022/03/19  Debugged DMA
2022/04/06  added new elements of menu
2022/04/06  Added add menu
2022/04/07  Added remove to menu
2022/04/07  Added update to menu
2022/04/07  Added sort to menu
2022/04/07  Added ship to menu
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H

#include "Menu.h"
#include "iProduct.h"
using namespace std;
namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
	private:
		iProduct* pointers[sdds_max_num_items];
		int m_numofip=0;
		char* m_filename{};
		Menu m_menu;
		unsigned int menu() const;
		void save();
		bool load();
		void destruct();
	public:
		AidMan();
		AidMan(AidMan& a1) = delete;
		AidMan& operator=(AidMan& a1) = delete;
		~AidMan();
		void run();
		int list(const char* sub_desc = nullptr);
		void add();
		int search(int sku) const;
		int searchindex(int sku) const;
		void remove(int index);
		void rem();
		void update();
		void sort();
		void ship();
	};

}
#endif
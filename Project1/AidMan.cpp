/* Citation and Sources...
Final Project Milestone 5.6
Module: AidMan
Filename: AidMan.cpp
Version 1.6
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/19  Preliminary release
2022/03/19  Debugged DMA
2022/04/06  Added new elements of menu
        2022/04/06  Added add menu
2022/04/07  Added remove to menu
2022/04/07  Added update to menu
2022/04/07  Added sort to menu
2022/04/07  Added ship to menu
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "Menu.h"
#include "AidMan.h"
#include "Utils.h"
#include "Perishable.h"
#include "Status.h"
using namespace std;
namespace sdds
{
    unsigned int AidMan::menu() const {
        cout << "Aid Management System\n";
        cout << "Date: 2022/03/31\n";
        cout << "Data file: ";
        if (m_filename == nullptr) cout << "No file\n";
        else cout << m_filename << endl;
        cout << "---------------------------------\n";
        return  m_menu.run();
    }
    AidMan::AidMan() : m_menu{ 7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n" } {}
    AidMan::~AidMan() {
        delete[] m_filename;
    }
    int AidMan::search(int sku) const {
        for (int i = 0; i < m_numofip; i++) {
            if (pointers[i]->operator==(sku)) return sku;
        }
        return -1;
    }
    int AidMan::searchindex(int sku) const {
        for (int i = 0; i < m_numofip; i++) {
            if (pointers[i]->operator==(sku)) return i;
        }
        return -1;
    }
    void AidMan::run() {
        string str;
        while (1) {
            int k = menu();
            if (k != 0 && m_filename == nullptr) k = 7;

            if (k == 0) {
                cout << "Exiting Program!\n";
                save();
                destruct();
                break;

            }
            else if (k == 1) {
                cout << "\n****List Items****\n";
                list();
            }
            else if (k == 2) {
                cout << "\n****Add Item****\n";
                add();             
            }
            else if (k == 3) {
                cout << "\n****Remove Item****\n";
                rem();
            }
            else if (k == 4) {
                cout << "\n****Update Quantity****\n";
                update();
            }
            else if (k == 5) {
                cout << "\n****Sort****\n";
                sort();
            }
            else if (k == 6) {
                cout << "\n****Ship Items****\n";
                ship();
            }
            else if (k == 7) {
                cout << "\n****New/Open Aid Database****\n";
                cout << "Enter file name: ";
                save();
                cin >> str;
                delete[] m_filename;
                ut.alocpy(m_filename, str.c_str());
                if (load()) cout << m_numofip << " records loaded!" << endl << endl;
            }
        }
    }
    void AidMan::ship() {
        int k = 0;

        ofstream f("shippingOrder.txt");
        f << "Shipping Order, Date: ";
        f << ut.currDate();
        f << "\n";
        f << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
        f << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        for (int i = 0; i < m_numofip; i++) {
            if (pointers[i]->qty() == pointers[i]->qtyNeeded()) {
                f << setw(4) << k + 1 << " | ";
                pointers[i]->linear(true);
                pointers[i]->display(f);
                f << endl;
                remove(i);
                k++;
            }
        }
        f << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        cout << "Shipping Order for "<< k <<" times saved!\n\n";
    }
    void AidMan::sort() {
        iProduct* temp;
        for (int i = 0; i < m_numofip; ++i) {
            for (int j=0; j < m_numofip-1; ++j) {
                if (pointers[j]->qtyNeeded() - pointers[j]->qty() < pointers[j+1]->qtyNeeded() - pointers[j+1]->qty()) {
                    temp = pointers[j];
                    pointers[j] = pointers[j+1];
                    pointers[j+1] = temp;
                }
            }     
        }
        cout << "Sort completed!\n\n";
    }
    void AidMan::update() {
        string str;
        int k = 0;
        char* temp{};
        cout << "Item description: ";
        cin.ignore(1000, '\n');
        getline(cin, str);
        temp = new char[strlen(str.c_str()) + 1];
        strcpy(temp, str.c_str());
        for (int i = 0; i < m_numofip; i++) {
            if (pointers[i]->operator==(temp)) k++;
        }
        if (k != 0)list(temp);
        else cout << "No matches found!\n";
        delete[] temp;
        pointers[m_numofip] = new Perishable;
        cout << "Enter ";     
        int i = searchindex(pointers[m_numofip]->readSku(cin));
        delete pointers[m_numofip];
        if (i == -1) {
            cout << "SKU not found!";  
            cout << endl;
        }
        else {
            cout << "1- Add\n" << "2- Reduce\n" "0- Exit\n";
            int k = ut.getint(0, 2, "> ");
            if (k == 1) {
                if (pointers[i]->qty() == pointers[i]->qtyNeeded()) cout << "Quantity Needed already fulfilled!\n\n";
                else {
                    cout << "Quantity to add:";
                    int q = ut.getint(1, pointers[i]->qtyNeeded(), " ");
                    if (q + pointers[i]->qty() > pointers[i]->qtyNeeded()) cout << "Quantity Needed already fulfilled!\n\n";
                    else {
                        pointers[i]->operator+=(q);
                        cout << q << " items added!\n\n";
                    }
                }               
            }
            else if (k == 2) {
                if (pointers[i]->qty() < 0) cout << "Quaintity on hand is zero!\n\n";
                else {
                    cout << "Quantity to reduce:";
                    int q = ut.getint(1, pointers[i]->qtyNeeded(), " ");
                    if (q - pointers[i]->qty() < 0) cout << "Quaintity on hand is zero!\n\n";
                    else {
                        pointers[i]->operator-=(q);
                        cout << q << " items removed!\n\n";
                    }
                }     
            }
            else cout << "Aborted!\n\n";
        }
    }
    void AidMan::remove(int index) {
        delete pointers[index];
        pointers[index] = nullptr;
        for (int i = index; i < m_numofip-1; i++) {
            pointers[i] = pointers[i + 1];       
        }
        m_numofip--;

    }
    void AidMan::rem() {
        string str;
        char* temp{};
        cout << "Item description: ";
        cin.ignore(1000, '\n');
        getline(cin, str);
        temp = new char[strlen(str.c_str()) + 1];
        strcpy(temp, str.c_str());
        list(temp);
        delete[] temp;
        pointers[m_numofip] = new Perishable;
        cout << "Enter ";
        int i = searchindex(pointers[m_numofip]->readSku(cin));
        if (i == -1) {
            cout << "SKU not found!";
            delete pointers[m_numofip];
            cout << endl;
        }
        else {

            cout << "Following item will be removed: \n";
            delete pointers[m_numofip]; 
            pointers[i]->linear(false);
            pointers[i]->display(cout);
            cout << endl;
            cout << "Are you sure?\n" << "1- Yes!\n" << "0- Exit\n";
            int k = ut.getint(0, 1, "> ");
            if (k == 1) {
                remove(i);
                cout << "Item removed!\n\n";
            }
            else cout << "Aborted!\n\n";
        }
    }
    void AidMan::add() {
        if (m_numofip >= sdds_max_num_items) cout << "Database full!" << endl;
        else {
            cout << "1- Perishable" << endl << "2- Non-Perishable" << endl << "-----------------" << endl << "0- Exit" << endl;
            int c = ut.getint(0, 2, "> ");
            if (c == 0) cout << "Aborted\n\n";
            else if (c == 1) {
                pointers[m_numofip] = new Perishable;     
                int i=search(pointers[m_numofip]->readSku(cin));
                if (i != -1) {
                    cout << "Sku: " << i << " is already in the system, try updating quantity instead.\n";
                    delete pointers[m_numofip];
                    cout << endl;
                }
                else {
                    pointers[m_numofip]->read(cin);
                    if (pointers[m_numofip]->operator bool()) m_numofip++;
                    else {
                        pointers[m_numofip]->display(cout);
                        delete pointers[m_numofip];
                    }
                    cout << endl;
                }
                
            }
            else if (c == 2) {
                pointers[m_numofip] = new Item;
                int i=search(pointers[m_numofip]->readSku(cin));
                if (i != -1) {
                    cout << "Sku: "<< i <<" is already in the system, try updating quantity instead.\n";
                    delete pointers[m_numofip];
                    cout << endl;
                }
                else {
                    pointers[m_numofip]->read(cin);
                    if (pointers[m_numofip]->operator bool()) m_numofip++;
                    else {
                        pointers[m_numofip]->display(cout);
                        delete pointers[m_numofip];
                    }
                    cout << endl;
                }
                
            }
        }
    }
    void AidMan::save() {
        if (m_filename != nullptr) {
            ofstream f(m_filename);
            for (int i = 0; i < m_numofip; i++) pointers[i]->save(f);        
        }
    }
    bool AidMan::load() {
        bool flag = false;
        destruct();
        ifstream f;
        f.open(m_filename, ifstream::in);
        if (!f.is_open()) {
            int k;
            cout << "Failed to open" << m_filename << "for reading!" << endl << "Would you like to create a new data file?" << endl
                << "1- Yes!" << endl << "0- Exit" << endl;
            k = ut.getint(0, 1, "> ");
            if (k == 1) ifstream f(m_filename);
        }
        else {
            while (f) {
                char ch = f.peek();
                if (ch >= '1' && ch <= '3') {
                    flag = true;
                    pointers[m_numofip] = new Perishable;
                    pointers[m_numofip]->load(f);                   
                    if (pointers[m_numofip]->operator bool()) m_numofip++;
                    else delete pointers[m_numofip];
                }
                else if (ch >= '4' && ch <= '9') {
                    flag = true;
                    pointers[m_numofip] = new Item;
                    pointers[m_numofip]->load(f);                 
                    if (pointers[m_numofip]->operator bool()) m_numofip++;
                    else delete pointers[m_numofip];
                }
                else f.setstate(ios::badbit);
            }
        }
        f.close();
        return flag;
    }
    void AidMan::destruct() {
        for (int i = 0; i < m_numofip; i++) delete pointers[i];
        m_numofip = 0;
    }
    int AidMan::list(const char* sub_desc) {
        int num = 0;
        int k;
        ofstream f(m_filename);
        if (sub_desc == nullptr) {
            cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            for (int i = 0; i < m_numofip; i++) {
                cout << setw(4) << i + 1 << " | ";
                pointers[i]->linear(true);
                pointers[i]->display(cout);
                cout << endl;
                num++;
            }
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
            cin.ignore(1000, '\n');
            char che;
            che = cin.peek();
            if (che != '\n') {
                k = che - '0';
                cin.get(che);
                for (int i = 0; i < m_numofip; i++) {
                    if (k == i) {
                        pointers[i-1]->linear(false);
                        pointers[i-1]->display(cout);
                        num++;
                        cout << endl << endl;
                    }
                }
            }
            else  cout << endl;
        }
        else {             
            if (m_numofip <= 0)  cout << "The list is empty!" << endl;
            else if (m_numofip > 0) {               
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                    for (int i = 0; i < m_numofip; i++) {
                        if (pointers[i]->operator==(sub_desc)) {
                            cout << setw(4) << i + 1 << " | ";
                            pointers[i]->linear(true);
                            pointers[i]->display(cout);
                            cout << endl;
                        }
                    }
                    cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                }
                else  cout << endl;
        }
        return num;
    }
}
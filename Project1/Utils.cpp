/* Citation and Sources...
Final Project Milestone 5.6
Module: Utils
Filename: Utils.cpp
Version 1.1
Author	Maksym Sorokan
ID 106544208
Email msorokan@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/18  Preliminary release
2022/03/18  Debugged DMA
2022/04/01  Added getdouble
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "Utils.h"
#include "Status.h"
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   string Utils::currDate() {
	   return "2022/03/31";
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }

   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }
   void Utils::alocpy(char*& destination, const char* source) {
	   delete[] destination;
	   destination = nullptr;
	   if (source!=nullptr) {
		   destination = new char[strlen(source) + 1];
		   strcpy(destination, source);
	   }

   }
   int Utils::getint(const char* prompt){
	   int num;
	   int k = 0;
	   if (prompt)
		   cout << prompt;
	   do {
		   cin >> num;
		   if (cin.fail())
		   {
			   cout << "Invalid Integer, retry: ";
			   cin.clear();
			   while (cin.get() != '\n');
		   }
		   else k = 1;
	   } while (k == 0);
	   return num;
   }
   int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
	   int num = getint(prompt);
	   while (num<min || num>max) {
		   if (errMes)
		   {	
			   if (errMes)
			   {
				   cout << errMes << ", retry: ";
			   }
			   num = getint();
		   }
		   else {
			   cout << "Value out of range [" << min << "<=" << "val" << "<=" << max << "]: ";
			   num = getint("");
		   }
	   }
	   return num;
   }
   double Utils::getdouble(const char* prompt) {
	   double num;
	   int k = 0;
	   if (prompt)
		   cout << prompt;
	   do {
		   cin >> num;
		   if (cin.fail())
		   {
			   cout << "Invalid number, retry: ";
			   cin.clear();
			   while (cin.get() != '\n');
		   }
		   else k = 1;
	   } while (k == 0);
	   return num;
   }
   double Utils::getdouble(double min, double max, const char* prompt, const char* errMes) {
	   double num = getdouble(prompt);
	   while (num<min || num>max) {
		   if (errMes)
		   {
			   if (errMes)
			   {
				   cout << errMes << ", retry: ";
			   }
			   num = getdouble("");
		   }
		   else {
			   cout.setf(ios::fixed);
			   cout << "Value out of range [" << setprecision(2) << min << "<=" << "val" << "<=" << setprecision(2) << max << "]: ";
			   cout.unsetf(ios::fixed);
		   }
		   num = getdouble("");

	   }
	   return num;
   }
}
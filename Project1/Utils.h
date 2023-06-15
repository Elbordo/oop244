/* Citation and Sources...
Final Project Milestone 5.6
Module: Utils
Filename: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include "Status.h"
namespace sdds {
   const int sdds_testYear = 2022;
   const int sdds_testMon = 03;
   const int sdds_testDay = 31;
   class Utils {
      bool m_testMode = false;
   public:
      void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
      int daysOfMon(int mon, int year)const;
      void testMode(bool testmode = true);
      void alocpy(char*& destination, const char* source);
      int getint(const char* prompt = nullptr);
      int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
      double getdouble(const char* prompt);
      double getdouble(double min, double max, const char* prompt, const char* errMes = nullptr);
      string currDate();
   };
   extern Utils ut;
}

#endif // !SDDS_UTILS_H

/* ------------------------------------------------------
Workshop 5 part 2
Author	Maksym Sorokan
ID 106544208
Date 19.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>
using namespace std;
namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;
      void emptyPortfolio();

   public:
       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio()const;
       std::ostream& display()const;
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       Portfolio& operator+=(double num);
       Portfolio& operator-=(double num);
       bool operator ~() const;
       Portfolio& operator<<(Portfolio& fl);
       Portfolio& operator>>(Portfolio& fl);
   };
   double operator+ (const Portfolio& le, const Portfolio& ri);
   double operator+= (double& num, const Portfolio& por);
}
#endif // SDDS_Portfolio_H_
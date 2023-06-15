/* ------------------------------------------------------
Workshop 10 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "Displayable.h"
namespace sdds{
  class Employee :public Displayable{
    int m_empno{};
    char m_name[41]{};
    int m_officeNo{};
    void set(int empno, const char* name, int officNo);
  public:
     Employee();
    Employee(int empno, const char* name, int officNo);
    std::ostream& display(std::ostream& os)const;
    bool operator==(const Employee& E)const;
  };
}
#endif 
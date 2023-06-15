/* ------------------------------------------------------
Workshop 10 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"
namespace sdds{
  void Student::set(int stno, const char* name, const char* subject){
    m_stno = stno;
    std::strcpy(m_name, name);
    std::strcpy(m_subject, subject);
  }
  Student::Student() {
  }
  Student::Student(int stno, const char* name, const char* subject){
    set(stno, name,subject);
  }
  std::ostream& Student::display(std::ostream& os)const{
    return os << m_stno << ", " << m_name << ", " << m_subject;
  }
  bool Student::operator==(const Student& S)const{
     return std::strcmp(m_subject, S.m_subject) == 0;
  }
}

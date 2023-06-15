/* ------------------------------------------------------
Workshop 10 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Displayable.h"
namespace sdds{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}
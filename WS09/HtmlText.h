/* ------------------------------------------------------
Workshop 9 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include <iostream>
#include "Text.h"
using namespace std;
namespace sdds {
    class HtmlText : public Text {
    private:
        char* m_title{};
        void setEmpty();
    public:
        void set(const char* title);
        HtmlText();
        HtmlText(const char* title);
        HtmlText(const HtmlText& h1);
        HtmlText& operator=(const HtmlText& h1);
        ~HtmlText();
        ostream& write(ostream& ostr) const;
    };
}

#endif 
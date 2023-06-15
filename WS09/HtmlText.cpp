/* ------------------------------------------------------
Workshop 9 part 1
Author	Maksym Sorokan
ID 106544208
Date 30.3.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <ostream>
#include <istream>
#include <string>
#include "Text.h"
#include "HtmlText.h"
using namespace std;
namespace sdds {
    void HtmlText::setEmpty() {
        m_title = nullptr;
    }
    void HtmlText::set(const char* title) {
        delete[] m_title;
        setEmpty();
        if (title != nullptr) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }
    HtmlText::HtmlText(const char* title) {
        set(title);
    }
    HtmlText::HtmlText() {
        setEmpty();
    }
    HtmlText::HtmlText(const HtmlText& h1 ) {
        (Text&)*this = h1;
        set(h1.m_title);
    }
    HtmlText& HtmlText::operator=(const HtmlText& h1)  {
        if (this != &h1) {      
            (Text&)*this = h1;
            set(h1.m_title);          
        }
        return *this;
    }
    HtmlText::~HtmlText() {
        delete[] m_title;
    }
    ostream& HtmlText::write(ostream& ostr) const {
        bool MS = false, end = false;
        ostr << "<html><head><title>";
        if (m_title != nullptr) ostr << m_title;
        else ostr << "No Title";
        ostr << "</title></head>\n<body>\n";
        if (m_title != nullptr) ostr << "<h1>" << m_title << "</h1>\n";
        int index = 0;
        while (!end) {
            char ch = Text::operator[](index);
            if (ch == ' ') {
                if (MS == true) ostr << "&nbsp;";
                else {
                    MS = true; 
                    ostr << ' ';
                }
            }
            else if(ch == '<') {
                ostr << "&lt;";
                MS = false;
            }
            else if(ch == '>') {
                ostr << "&gt;";
                MS = false;
            }
            else if (ch == '\n') {
                ostr << "<br />\n";
                MS = false;
            }
            else {
                MS = false;
                if (ch != '\0')ostr << ch;
            }
            index++;
            if (ch == '\0') end = true;
        }
        if(end)ostr << "</body>\n</html>";
        return ostr;
    }
}
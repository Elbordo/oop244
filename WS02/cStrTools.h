/* ------------------------------------------------------
Workshop 2 part 1
Author	Maksym Sorokan
ID 106544208
Date 27.1.2022(dd.mm.yyyy)
-----------------------------------------------------------*/
#ifndef NAMESPACE_CSTRTOOLS_H // replace with relevant names
#define NAMESPACE_CSTRTOOLS_H
namespace sdds {
	void read(char* cString, unsigned int maxSize, char delimiter='\n');
	char toLower(char ch);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
	const char* strStr(const char* str, const char* find);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif
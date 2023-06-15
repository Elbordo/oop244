/* ------------------------------------------------------
Workshop 3 part 2
Author	Maksym Sorokan
ID 106544208
Date 02.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Train.h"
using namespace std;
namespace sdds {
	void Train::setEmpty() {
		tname[0] = '\0'; //assigning all data members to 0 or basically empty state
		numOP = 0;
		speed = 0;
	}
	void Train::set(const char* name, int num, double sp) {
		
		if (name == nullptr|| num <= 0 || num > MAX_PEOPLE || sp<=0 || sp > MAX_SPEED)
		{
			setEmpty(); //using additional function for empty state
		}
		else {
			strncpy(tname,name,MAX_NAME_LENGTH);
			numOP = num;
			speed = sp;
		}
	}
	int Train::getNumberOfPeople() const {
		return numOP;
	}
	const char* Train::getName() const {
		return tname;
	}
	double Train::getSpeed() const {
		return speed;
	}
	bool Train::isSafeEmpty() const {
		if (tname[0] == '\0' || numOP == -1 || speed == -1) return true;
		else return false; 
		
	}
	void Train::display() const {
		if (isSafeEmpty() != true)
		{
			cout.setf(ios::left);
			cout.width(18);
			cout << "NAME OF THE TRAIN";
			cout.width(2);
			cout << ": ";
			cout.width(11);
			cout << tname << endl;
			cout.width(18);
			cout << "NUMBER OF PEOPLE";
			cout.width(2);
			cout << ": ";
			cout << numOP << endl;
			cout.width(18);
			cout << "SPEED";
			cout.width(2);
			cout << ": ";
			cout << setprecision(2) << fixed << speed;
			cout << " km/h" << endl;
			cout.unsetf(ios::left);
		}
		else cout << "Safe Empty State!"<< endl;
	}
	bool Train::loadPeople(int num) {
		numOP = numOP + num;
		if (numOP <0) 
		{
			numOP = 0;
		}
		else if(numOP > MAX_PEOPLE)
		{
			numOP = MAX_PEOPLE;
		}
		if (isSafeEmpty() == true) return false;
		else return true;
	}
	bool Train::changeSpeed(double sp){
		speed = speed + sp;
		if (speed < 0) 
		{
			speed = 0.00;
		}
		else if(speed > MAX_SPEED)
		{
			speed = MAX_SPEED;
		}
		if (isSafeEmpty() == true) return false;
		else return true;
	}
	int transfer(Train& T1, Train& T2) {
		int eif;
		int trans;
		if (T1.isSafeEmpty() || T2.isSafeEmpty()) 
		{
			trans = -1;
		}
		else {
			eif = MAX_PEOPLE - T1.getNumberOfPeople();
			if (T2.getNumberOfPeople() >= eif) {
				T1.loadPeople(eif);
				T2.loadPeople(-eif);
				trans = eif;
			}
			else {
				trans = T2.getNumberOfPeople();
				T1.loadPeople(trans);
				T2.loadPeople(-trans);
			}
		}
		return trans;
	}
}
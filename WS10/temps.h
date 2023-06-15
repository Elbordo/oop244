/* ------------------------------------------------------
Workshop 10 part 1
Author	Maksym Sorokan
ID 106544208
Date 13.4.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_TEMPS_H_
#define SDDS_TEMPS_H_
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "Collection.h"
#include "Displayable.h"
using namespace std;
namespace sdds {
	template <typename t>//creating a template with name t
	const Collection<t> select(const t *arr, int size, const t& c1) {
		int k=0;
		for (int i = 0; i < size; i++) {//looping to check if are instances of c1 in array and if yes add +1 to k
			if (arr[i] == c1) {
				k++;
			}
		}
		Collection<t> arr1(k); // create a collectiion that holds a set of objects
		
		for (int i = 0; i < size; i++) {
			if (arr[i] == c1) {
				arr1[k] = arr[i]; //assign values from arr to arr1
				k++;
			}
		}
		return arr1;
	}
	template <typename t1>
	void printCollection(const Collection<t1> & c1, const char* title) {//recieves collection object
		cout << title << endl;
		for (int i = 0; i < c1.size(); i++) {//loop throught c1 object with help of a college function size
			cout << c1[i] << endl;
		}
	}
}
#endif
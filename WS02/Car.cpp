/* ------------------------------------------------------
Workshop 2 part 1
Author	Maksym Sorokan
ID 106544208
Date 27.1.2022(dd.mm.yyyy)
-----------------------------------------------------------*/
#define CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <string>
#include "Car.h"
#include "cStrTools.h"

using namespace std;
namespace sdds
{
	Car* c;
	int size;
	int num;
	int cArrs;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry " << endl;
		cout << "Enter the data in the following format: " << endl;
		cout << "Make and model, LicensePlate, MilitaryTime<ENTER> " << endl;
		cout << "Exit the program by entering the following : " << endl;
		cout << "X, <ENTER> " << endl;
	}

	void initialize(int allocSize) {
		num = 0;
		size = cArrs = allocSize;
		c = new Car[allocSize];
	}

	void deallocate(Car& C) {
		if (C.MaM != nullptr) {
			delete[] C.MaM;
		}
	}

	bool read(Car& C) {
		bool flag = false;
		char time[10];
		char makeModel[61];
		read(makeModel, 60, ',');
		if (strCmp(makeModel, "X") != 0) {
			flag = true;
			C.MaM = new char[strLen(makeModel) + 1];
			strCpy(C.MaM, makeModel);
			read(C.lPlate, 8, ',');
			read(time, 6);
			C.time = stoi(time);
		}
		return flag;
	}

	void print(const Car& C) {
		cout << C.time << ": " << C.MaM << "," << C.lPlate << endl;
	}

	void record(const Car& C) {
		Car* tempArr = nullptr;
		if (num == cArrs) {
			tempArr = new Car[cArrs + size];
			for (int i = 0; i < cArrs; i++) {
				strCpy(tempArr[i].lPlate, c[i].lPlate);
				tempArr[i].time = c[i].time;
				tempArr[i].MaM = c[i].MaM;
			}
			cArrs += size;
			delete[] c;
			c = tempArr;
			tempArr = nullptr;
		}
		strCpy(c[num].lPlate, C.lPlate);
		c[num].time = C.time;
		c[num].MaM = C.MaM;
		num++;
	}

	void endOfDay() {
		for (int i = 0; i < num; i++) {
			print(c[i]);
			deallocate(c[i]);
		}
		delete[] c;
		c = nullptr;
	}

}
/* ------------------------------------------------------
Workshop 2 part 1
Author	Maksym Sorokan
ID 106544208
Date 27.1.2022(dd.mm.yyyy)
-----------------------------------------------------------*/
#ifndef NAMESPACE_CAR_H // replace with relevant names
#define NAMESPACE_CAR_H

namespace sdds {
	struct Car {
		char lPlate[8];
		char* MaM;
		int time;
	};
	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();
}
#endif
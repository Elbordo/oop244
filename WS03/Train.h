/* ------------------------------------------------------
Workshop 3 part 2
Author	Maksym Sorokan
ID 106544208
Date 02.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef NAMESPACE_TRAIN_H // replace with relevant names
#define NAMESPACE_TRAIN_H
#define MAX_PEOPLE 1000
#define MAX_SPEED 320
#define MAX_NAME_LENGTH 20

namespace sdds {
	class Train {
	private:
		char tname[MAX_NAME_LENGTH];
		int numOP;
		double speed;
	public:
		void set(const char*, int, double);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
		void setEmpty();
		bool loadPeople(int num);
		bool changeSpeed(double sp);
};
	int transfer(Train& T1,Train& T2);
}
#endif
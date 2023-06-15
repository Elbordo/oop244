/* ------------------------------------------------------
Workshop 4 part 2
Author	Maksym Sorokan
ID 106544208
Date 12.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Robot.h"

using namespace std;
using namespace sdds;
	int main()
	{
		const int num_robots = 6;
		int broken_robot = 0;
		char replacmentName[] = "C3PO";
		Robot robot[num_robots] = {
			{},
			{"KC1", "kitchen", 25.33, 4.55, 2, 2.2, false},
			{"BR1", "bedroom", 5.22, 2.54, 1, 2.2, true},
			{"Broken", "Bedroom", 10.12, 2.5,1.55, 0, true},
			{"KC2", "kitchen", 20.56, 5, 2, 3.5, true},
			{"BR2", "bedroom", 25.32, 6.5, 2.5, 3.1, true}	
		};

		while ((broken_robot = conrtolRooomReport(robot, num_robots)) >= 0) {
			cout << endl << "Attention: There is a broken robot! Fixing the problem..." << endl;
			robot[broken_robot].set(replacmentName, "Control Room", 10.0, 4, 1, 2.09, false).display();
			replacmentName[0]++;
			cout << "Replacement Provided!" << endl << endl;
		}

		return 0;
	}



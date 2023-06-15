/* ------------------------------------------------------
Workshop 4 part 2
Author	Maksym Sorokan
ID 106544208
Date 12.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
#include <iostream>
namespace sdds {
	class Robot {
	private:
		char* m_name;
		char* m_location;
		double m_weight;
		double m_width;
		double m_height;
		double m_speed;
		bool m_deployed;
		void resetInfo();
	public:
		Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment);
		~Robot();
		Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment);
		void setLocation(const char* location);
		void setDeployed(bool deployment);
		char getName() const;
		char getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
		void display() const;
		
	};
	int conrtolRooomReport(const Robot robot[], int num_robots);
	

}
#endif
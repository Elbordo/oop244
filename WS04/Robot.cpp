/* ------------------------------------------------------
Workshop 4 part 2
Author	Maksym Sorokan
ID 106544208
Date 12.2.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Robot.h"
using namespace std;
namespace sdds {
	void Robot::resetInfo() {
		m_name = nullptr;
		m_location = nullptr;
		m_weight = 0;
		m_width = 0;
		m_height = 0;
		m_speed = 0;
		m_deployed = false;
}
	Robot::Robot() {
		resetInfo();
	}
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment) {
		resetInfo();
		set(name, location, weight, width, height, speed, deployment);
	}
	Robot::~Robot() {
		delete[] m_name;
		delete[] m_location;
	}
	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment) {
		delete[] m_name;
		delete[] m_location;
		if (name == nullptr || location == nullptr || weight == 0 || width == 0 || height == 0 || speed == 0) {
			resetInfo();
		}
		else {
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			setLocation(location);
			m_weight = weight;
			m_width = width;
			m_height = height;
			m_speed = speed;
			setDeployed(deployment);
		}
		return *this;
	}
	void Robot::setLocation(const char* location) {
		m_location = new char[strlen(location) + 1];
		strcpy(m_location, location);
	}
	void Robot::setDeployed(bool deployment) {
		m_deployed = deployment;
	}
	char Robot::getName() const {
		return *m_name;
	}
	char Robot::getLocation() const {
		return *m_location;
	}
	bool Robot::isDeployed() const {
		return m_deployed;
	}
	bool Robot::isValid() const {
		if (m_name != nullptr && m_location != nullptr && m_weight > 0 && m_width > 0 && m_height > 0 && m_speed > 0)
			return true;
		else return false;
	}
	double Robot::speed() const {
		return m_speed;
	}
	void Robot::display() const {
		string dep;
		if (m_deployed == true) dep = "YES";
		else dep = "NO";
		cout << "| " << setw(11) << left << m_name;
		cout << "| " << setw(15) << left << m_location;
		cout << " | " << setw(6) << setprecision(1) << fixed << right << m_weight;
		cout << " | " << setw(6) << setprecision(1) << fixed << right << m_width;
		cout << " | " << setw(6) << setprecision(1) << fixed << right << m_height;
		cout << " | " << setw(6) << setprecision(1) << fixed << right << m_speed;
		cout << " | " << setw(9) << left << dep << "|" << endl;

	}
	int conrtolRooomReport(const Robot robot[], int num_robots) {
		int i=0, j = 0;
		int deploy = 0;
		double s1 = 0, s2 = 0;
		cout << setw(55) << right <<"------ Robot Control Room -----" << endl;
		cout << setw(59) << right <<"---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		for (i = 0; i < num_robots; i++) {		
			if (robot[i].isValid()) {
				s1 = robot[i].speed();
				robot[i].display();	
				if (robot[i].isDeployed()) deploy++;			
				if (s1 > s2) {
					s2 = s1;
					j = i;
				}
			}
			else return i;	
		}
		cout << "|=============================================================================|" << endl;
		cout << "| SUMMARY:                                                                    |" << endl;
		cout << "| " << deploy << "  robots are deployed.                                                     |" << endl;
		cout << "| The fastest robot is:                                                       |" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		robot[j].display();
		cout << "|=============================================================================|" << endl;
		return -1;
	}

}
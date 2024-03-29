//============================================================================
// File Name   : Menu.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include <vector>
//#include "GroupOfStudents.h"
#include "InputOutput.h"
using namespace std;
using std::string;

class Menu
{
public:
	struct InvalidData : std::runtime_error {
		InvalidData(): runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile(): runtime_error("Invalid input file name") {}
	};

	enum OPTIONS{ INFO=1, READ_FILE, DISPLAY, DISPLAY_SORTED, HIGHEST, DISPLAY_ONE, WRITE_TO_FILE,EXIT };
		
private:
	GroupOfStudents gs;
	vector <StudentCourses> st_vector;
public:
	Menu() {};

	bool is_id_valid(string id) const;
	void display_menu();
	void display_info();
	void read_students();
	
	void display_students();
	void display_students_sorted();
	void display_highest_score();
	void display_one();
	void write_to_file();
	void set_vektor(vector<StudentCourses> vektor);
};

#endif /*MENU_H_*/

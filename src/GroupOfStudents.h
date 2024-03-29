
//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <vector>
#include <fstream>
#include <iostream>
#include "StudentCourses.h"

using namespace std;
using std::vector;

class GroupOfStudents
{
private:
	vector <StudentCourses> st_vec;

//	void search_for_highest(vector<int>& indices_max) const; // utility

public:
	GroupOfStudents() {}
	GroupOfStudents(const vector< StudentCourses >& v) : st_vec(v) {}
	
	// Trazene metode koje treba da se dodaju
	void display(vector<StudentCourses> st_vector);
	void display_sorted(vector<StudentCourses> st_vector);
	void display_highest(vector<StudentCourses> st_vector);
	void display_one_student(vector<StudentCourses> st_vector);
	void write_to_file(string path);
	const vector<StudentCourses>& get_student_courses() const { return st_vec; }
};

#endif /*GROUPOFSTUDENTS_H_*/

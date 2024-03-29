//============================================================================
// File Name   : main.cpp 
// Authors     : Marko Vukotić, Aleksandar Jovanović
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
	vector<StudentCourses> st_vector;
	Menu m;
	int option;
	m.display_menu();
	do
	{
		cout << "> ";
		while (!(cin >> option) || option < 1 || option > Menu::EXIT)
		{
			if (cin.fail())	// we found something that wasn’t an integer
			{
				cin.clear();	// we’d like to look at the characters
				char ch;
				while (cin>>ch && !isdigit(ch))
				{
					cerr << "Los unos! Pokusajte ponovo:" << endl;
					cout << "> ";
					
				}
				cin.unget();
			} 
			else
			{	// option < 1 || option > Menu::EXIT */
				cerr << "Unos mora biti jedan od ponudjenih cifara! Pokusajte ponovo:" << endl;
				cout << "> ";
			}
		}
			
		switch(option)
		{
		case Menu::INFO:
			m.display_info();
			break;
		case Menu::READ_FILE:
			try
			{
				m.read_students();
			} catch (const Menu::InvalidFile& excp)
			{
				cerr << excp.what() << endl;
			} catch (const Menu::InvalidData& excp)
			{
				cerr << excp.what() << endl;
			}
			break;
		case Menu::DISPLAY:
			m.display_students();
			break;
		case Menu::DISPLAY_SORTED:
			m.display_students_sorted();
			break;   
		case Menu::HIGHEST:
			m.display_highest_score();
			break;
		case Menu::DISPLAY_ONE:
			m.display_one();
			break;
		case Menu::WRITE_TO_FILE:
			m.write_to_file();
			break;
		case Menu::EXIT:
			EXIT_SUCCESS();
		}
		m.display_menu();
	} while (option != Menu::EXIT);
	return 0;
}

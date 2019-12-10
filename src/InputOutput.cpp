#include "InputOutput.h"
using namespace std;
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

#include "Student.h"
#include "Courses.h"
#include "StudentCourses.h"

void InputOutput::read_textFile(string path) {
	
	std::ifstream file(path);
	string line;
	int i = -1;
	int d = 0;
	int brojac = 0;//brojac koji ce da broji posle koliko iteracija smo prosli jednog studenta i njegove ocene
	vector<Student> studenti;
	vector<int> domaci;
	vector<int> testovi;
	vector<int> kvizovi;

	while (std::getline(file, line)) {
		// Rad sa linijom teksta
		++i;
		if (i % 4 == 0) { //Sve linije gde su studenti stavlja u vektor studenata			
			std::vector<std::string> arr = split(line, ' '); // Splituje liniju u vektor
			Student s = Student(arr[0], arr[1], arr[2]); // Po indeksima u vektoru zovemo konstruktor
			studenti.push_back(s);
			brojac++;
			//cout << s.get_first_name() << endl;
		}

		else if ((i - 1) % 4 == 0) {//Dodaje sve domace zadatke u vektor domaci
			std::vector<std::string> arrD = split(line, ' ');
			for (int j = 0; j < arrD.size(); j++) {
				d = stoi(arrD.at(j));
				domaci.push_back(d);
				brojac++;
			}
		}
		
		else if ((i - 2) % 4 == 0) {//Dodaje sve testove u vektor testovi
			std::vector<std::string> arrT = split(line, ' ');
			for (int j = 0; j < arrT.size(); j++) {
				d = stoi(arrT.at(j));
				domaci.push_back(d);
				brojac++;
			}
		}
		else if ((i - 3) % 4 == 0) {//Dodaje sve kvizove u vektor kvizovi
			std::vector<std::string> arrQ = split(line, ' ');
			for (int j = 0; j < arrQ.size(); j++) {
				d = stoi(arrQ.at(j));
				domaci.push_back(d);
				brojac++;
			}
		}

		if (brojac == 4) {
			Courses c = Courses(domaci, testovi, kvizovi);//Pravi novi courses u svakoj iteraciji(za svakog studenta)
			StudentCourses sc = StudentCourses(studenti[0], c);

			brojac = 0;
			domaci.clear();
			testovi.clear();
			kvizovi.clear();
			studenti.clear();
		}
	}

	

	for (int j = 0; j < studenti.size(); j++) {
		Student* Trenutni = &studenti[j];
	}
	for (int j = 0; j < domaci.size(); j++) {
		cout << domaci.at(j);
	}
	cout << endl;
	for (int j = 0; j < testovi.size(); j++) {
		cout << testovi.at(j);
	}
	cout << endl;
	for (int j = 0; j < kvizovi.size(); j++) {
		cout << kvizovi.at(j);
	}
}


void InputOutput::read_binaryFile(string path) {
	// char buffer[100]; ??
	ifstream file(path, ios::in | ios::binary);
	//file.read(buffer, 100) ?

	if (!file) {
		// greska

	}




}

// Moramo u write dodati neku listu koja se upisuje
void InputOutput::write_textFile(string path) {

	std::ofstream file(path);
	if (file.is_open()) {

		string line;

		do {
			std::getline(cin, line);
			file << line << endl;


		} while (line != "");

		file.close();

	}

	else cerr << "Fajl nemoguce otvoriti.";

}

// isto i ovde listu
void InputOutput::write_binaryFile(string path) {

	fstream file(path, ios::in | ios::out | ios::binary);
	//file.write();  u zagradu ide to sto upisujemo
	file.close();



}



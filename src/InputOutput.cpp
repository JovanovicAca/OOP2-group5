#include "InputOutput.h"
using namespace std;
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

vector<StudentCourses> InputOutput::read_textFile(string path) {
	
	std::ifstream file(path);
	string line;
	int i = -1;
	int d;
	int t;
	int k;
	int brojac = 0;//brojac koji ce da broji posle koliko iteracija smo prosli jednog studenta i njegove ocene
	vector<Student> studenti;
	vector<int> domaci;
	vector<int> testovi;
	vector<int> kvizovi;
	vector<StudentCourses> st_vector;
	

	while (std::getline(file, line)) {
		// Rad sa linijom teksta
		++i;	
		if (i % 4 == 0) { //Sve linije gde su studenti stavlja u vektor studenata		
			std::vector<std::string> arr = split(line, ' '); // Splituje liniju u vektor
			Student s = Student(arr[0], arr[1], arr[2]); // Po indeksima u vektoru zovemo konstruktor
			studenti.push_back(s);		
			brojac +=1;
			//cout << s.get_first_name() << endl;
		}

		else if ((i - 1) % 4 == 0) {//Dodaje sve domace zadatke u vektor domaci
			brojac += 1;
			std::vector<std::string> arrD = split(line, ' ');
			for (int j = 0; j < arrD.size(); j++) {
				d = stoi(arrD.at(j));
				domaci.push_back(d);
			}
		}
		
		else if ((i - 2) % 4 == 0) {//Dodaje sve testove u vektor testovi
			brojac += 1;
			std::vector<std::string> arrT = split(line, ' ');
			for (int j = 0; j < arrT.size(); j++) {
				t = stoi(arrT.at(j));
				testovi.push_back(t);
			}
		}
		else if ((i - 3) % 4 == 0) {//Dodaje sve kvizove u vektor kvizovi
			brojac += 1;
			std::vector<std::string> arrQ = split(line, ' ');
			for (int j = 0; j < arrQ.size(); j++) {
				k = stoi(arrQ.at(j));
				kvizovi.push_back(k);
			}
		}
		if (brojac == 4) {
			Courses c = Courses(kvizovi, domaci, testovi);//Pravi novi courses u svakoj iteraciji(za svakog studenta)
			StudentCourses sc = StudentCourses(studenti[0], c);
		
			st_vector.push_back(sc);//Vektor za GroupOfStudents
			
			brojac = 0;
			domaci.clear();
			testovi.clear();
			kvizovi.clear();
			studenti.clear();
			c.calc_final_score();
			c.calc_letter_grade();
		
			
		}
		
	}
	GroupOfStudents grp = GroupOfStudents(st_vector);

	
	return st_vector;

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
void InputOutput::write_textFile(vector<StudentCourses> vektor) {
	cout << "Unesite ime fajla(bez ekstenzije .txt): " << endl;
	string path;

	while (!(cin >> path)) { //Proverava da li je ime dobro
		cout << "Pogresan unos! Unesite opet: " << endl;
		cin.clear();
		cin.ignore(100, '\n');

	}
	
	GroupOfStudents group = GroupOfStudents(vektor);
	group.write_to_file(path);
	
}

// isto i ovde listu
void InputOutput::write_binaryFile(string path) {

	fstream file(path, ios::in | ios::out | ios::binary);
	//file.write();  u zagradu ide to sto upisujemo
	file.close();



}



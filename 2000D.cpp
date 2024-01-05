#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct student {
	string name;
	unsigned int age;
	unsigned int score;
} Student;

void sortSocre(Student s[], int n) {
	for (int i = 0; i < n; ++i) {
		int max = i;
		for (int j = i + 1; j < n; ++j) 
			if (s[j].score > s[max].score) 
				max = j;
		if (max != i) {
			Student t = s[i];
			s[i] = s[max];
			s[max] = t;
		}
	}
}

int main() {
	Student s[4];
	for (int i = 0; i < 4; ++i)
		cin >> s[i].name >> s[i].age >> s[i].score;

	ofstream ofile("sf1.txt", ios::out);
	if (ofile == NULL) {
		cout << "FILE OPEN ERROR";
		return -1;
	}
	for (int i = 0; i < 4; ++i)
		ofile << s[i].name << " " << s[i].age << " " << s[i].score << endl;
	ofile.close();

	ifstream ifile("sf1.txt", ios::in);
	if (ifile == NULL) {
		cout << "FILE OPEN ERROR";
		return -1;
	}
	for (int i = 0; i < 4; ++i)
		ifile >> s[i].name >> s[i].age >> s[i].score;
	ifile.close();

	sortSocre(s, 4);
	cout << endl << "Sorted data:" << endl;
	for (int i = 0; i < 4; ++i)
		cout << s[i].name << " " << s[i].age << " " << s[i].score << endl;
	cout << endl << "The second highest:" << endl
	<< "name: " << s[1].name << " age: " << s[1].age << " score: " << s[1].score << endl;
	return 0;
}

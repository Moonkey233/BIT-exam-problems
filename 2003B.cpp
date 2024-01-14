#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct student{
	string number;
	string name;
	string sex;
	int age;
}Student;

int main(){
	ofstream outfile("student.txt");
	Student s[4];
	for(int i = 0; i < 4; ++i)
		cin >> s[i].number >> s[i].name >> s[i].sex >> s[i].age;
	for(int i = 0; i < 4; ++i)
		outfile << s[i].number << " " << s[i].name << " "  << s[i].sex << " " << s[i].age << endl;
	outfile.close();
	int flag = 0;
	string number;
	cin >> number;
	for(int i = 0; i < 4; ++i){
		if(s[i].number == number) {
			cout << s[i].number << " " << s[i].name << " " << s[i].sex << " " << s[i].age << " " << endl;
			flag = 1;
		}
	}
	if(flag == 0) cout << "²éÕÒÊ§°Ü" << endl;
	return 0;
}

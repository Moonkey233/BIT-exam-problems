#include <bits/stdc++.h>
using namespace std;
class Student{
	public:
		Student(int n, string na, char s, int a) { number = n, name = na, sex = s, age = a; } 
		int number;
		string name;
		char sex;
		int age;
		bool operator < (const struct Student & s) const { return number < s.number; }
};
int main() {
	set<Student> s;
	string cmd;
	s.insert(Student(10, "wes", 'f', 23));
	s.insert(Student(20, "ert", 'f', 45));
	s.insert(Student(30, "str", 't', 89));
	while(cin >> cmd){
		if(cmd[0] == 'i' || cmd[0] == 'I'){
			int n, a, pos;
			string na, sex;
			pos = cmd.find(",");
			n = stoi(cmd.substr(1, pos - 1));
			cmd = cmd.substr(pos + 1);
			pos = cmd.find(",");
			na = cmd.substr(0, pos);
			cmd = cmd.substr(pos + 1);
			pos = cmd.find(",");
			sex = cmd.substr(0, pos);
			cmd = cmd.substr(pos + 1);
			pos = cmd.find(",");
			a = stoi(cmd.substr(0, pos));
			cmd = cmd.substr(pos + 1);
			bool flag = true;
			for(auto &ele : s){
				if(ele.number == n){
					flag = false;
					break;
				}
			}
			if(!flag){
				cout << "Number exist" << endl;
			} else {
				s.insert(Student(n, na, sex[0], a));
			}
		} else if(cmd[0] == 'd' || cmd[0] == 'D'){
			int n = stoi(cmd.substr(1, cmd.size() - 1));
			if(!n) cout << "Cmd error" << endl;
			else{
				set<Student>::iterator it = s.begin();
				for(; it != s.end(); ++it){
					if(it->number == n) {
						s.erase(it);
						break;
					}
				}
				if(it == s.end()) cout << "Not found" << endl;
			}
		} else {
			cout << "Cmd error" << endl;
		}
		for(auto &ele : s){
			if(s.find(ele) != s.begin()) cout << ",";
			cout << "(" << ele.number << "," << ele.name << "," << ele.sex << "," << ele.age << ")"; 
		}
		cout << endl;
	}
	return 0;
}

#include <bits/stdc++.h> //A+B*(C-D/E+F)*G-H*J
using namespace std;
int getLevel(char ch) {
	if(ch == '(') return 0;
	else if(ch == '+' || ch == '-') return 1;
	else if(ch == '*' || ch == '/') return 2;
}
int main() {
	string mid;
	cin >> mid;
	vector<char> vc;
	for(auto &ch : mid) {
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) cout << ch;
		else if(ch == '(') {
			vc.push_back(ch);
			continue;
		} else if(ch == ')') {
			while(!vc.empty() && vc[vc.size()-1] != '(') {
				cout << vc[vc.size()-1];
				vc.pop_back();
			}
			if(vc.empty()) {
				cout << endl << "Error: ( is missing." << endl;
				exit(0);
			} else vc.pop_back();
			continue;
		} else if(!vc.empty()) {
			if(getLevel(vc[vc.size()-1]) < getLevel(ch)) vc.push_back(ch);
			else {
				while(!vc.empty() && getLevel(vc[vc.size()-1]) >= getLevel(ch)) {
					cout << vc[vc.size()-1];
					vc.pop_back();
				}
				vc.push_back(ch);
			}
		} else vc.push_back(ch);
	}
	while(!vc.empty()) {
		cout << vc[vc.size()-1];
		vc.pop_back();
	}
	return 0;
}

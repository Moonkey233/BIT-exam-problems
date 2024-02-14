#include <bits/stdc++.h>
using namespace std;
void print(stringstream &ss) {
	if(ss.str() != "") {
		try {
			double n = stod(ss.str());
			if(ss.str()[0] == '+') cout << "+";
			cout << n << " ";
		} catch(...) {}
		ss.str("");
	}
}
int main() {
	stringstream ss;
	string str;
	cin >> str;
	for(auto &ch : str) {
		if(ch >= '0' && ch <= '9') ss << ch;
		else if(ch == '.') ss << ch;
		else if(ch == '-') {
			print(ss);
			ss << ch;
		} else if(ch == '+') {
			print(ss);
			ss << ch;
		} else print(ss);
	}
	print(ss);
	return 0;
}

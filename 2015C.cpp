#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	vector<bool> v;
	for(int i = 0; i < str.length(); ++i) {
		if(str[i] == '(') {
			if(i != 0 && str[i-1] == '-') v.push_back(true);
			else v.push_back(false);
		} else if(str[i] == ')') v.pop_back();
		else if(str[i] == '+' || str[i] == '-') {
			if(v.size() && v[v.size() - 1]) {
				char ch = str[i] == '+' ? '-' : '+';
				cout << ch;
			} else cout << str[i];
		} else cout << str[i];
	}
	return 0;
}

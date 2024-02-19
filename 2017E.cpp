#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	int row, flag = 1, n = 0;
	cin >> str >> row;
	if(row == 1) {
		cout << str;
		return 0;
	}
	vector<vector<char>> v(row, vector<char>(str.length(), ' '));
	for(int i = 0; i < str.length(); ++i) {
		v[n][i] = str[i];
		n += flag;
		if(n == -1) {
			flag = 1;
			n = 1;
		} else if(n == row) {
			flag = -1;
			n = row - 2;
		}
	}
	for(auto &ee : v) {
		for(auto &e : ee) cout << e;
		cout << endl;
	}
	return 0;
}

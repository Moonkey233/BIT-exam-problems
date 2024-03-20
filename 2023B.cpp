#include <bits/stdc++.h>
using namespace std;
int main() {
	char ch;
	int n;
	cin >> ch >> n;
	while(n <= 0 || n >= 10) {
		cout << "Input n must in range 0 < n < 10." << endl;
		cin >> n;
	}
	while(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')) {
		cout << "Input ch must in range a~z or A~Z." << endl;
		cin >> ch;
	}
	bool flag;
	if(ch >= 'A' && ch <= 'Z') flag = false;
	else flag = true;
	if(flag) ch -= 32;
	vector<vector<char>> vc(n * 2 - 1, vector<char>(n, '\0'));
	for(int i = 0; i < n * 2 - 1; ++i) {
		if(ch > 'Z') ch -= 26;
		vc[i][0] = ch++;
	}
	for(int i = 0; i < n - 1; ++i) {
		if(ch > 'Z') ch -= 26;
		vc[n * 2 - 3 - i][i + 1] = ch++;
	}
	for(int i = 0; i < n - 2; ++i) {
		if(ch > 'Z') ch -= 26;
		vc[n - 2 - i][n - 2 - i] = ch++;
	}
	for(auto &ele : vc) {
		for(auto &e : ele) if(flag) cout << (char)(e + 32) << " ";
			else cout << e << " ";
		cout << endl;
	}
	return 0;
}

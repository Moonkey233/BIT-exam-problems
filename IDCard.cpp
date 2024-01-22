#include <iostream>
#include <string>

using namespace std;

int check(const string &s) {
	int sum = 0, weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	char x[11] = {'1', '0', 'x', '9', '8', '7', '6', '5', '4', '3', '2'};
	if(s.length() != 18) return 0;
	for(int i = 0; i < 18; ++i) {
		if(s[i] < '0' || s[i] > '9'){
			if(i != 17) return 0;
			else if(s[i] != 'x' && s[i] != 'X') return 0;
		}
		if(i != 17) sum += weight[i] * (s[i] - '0');
		else sum %= 11;
	}
	if (x[sum] == s[17] || x[sum] == s[17] + 32) return 1;
	else return 0;
}

int main() {
	string s;
	while(cin >> s) {
		if(check(s)) cout << "ID Correct" << endl;
		else cout << "ID Wrong" << endl;
	}
	return 0;
}

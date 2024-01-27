#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	while(n <= 0 || n > 9 || !(n & 1)) cin >> n;
	for(int i = 0; i < n / 2; ++i) cout << " ";
	cout << "*" << endl;
	for(int i = 1; i < n / 2; ++i){
		for(int j = 0; j < n / 2 - i; ++j) cout << " ";
		cout << "*";
		for(int j = 0; j < 2 * i - 1; ++j) cout << " ";
		cout << "*" << endl;
	}
	if(n != 1){
		cout << "*";
		for(int i = 0; i < n - 2; ++i) cout << " ";
		cout << "*" << endl; 
	}
	for(int i = n / 2 - 1; i > 0; --i){
		for(int j = 0; j < n / 2 - i; ++j) cout << " ";
		cout << "*";
		for(int j = 0; j < 2 * i - 1; ++j) cout << " ";
		cout << "*" << endl;
	}
	if(n != 1){
		for(int i = 0; i < n / 2; ++i) cout << " ";
		cout << "*" << endl;
	}
	return 0;
}

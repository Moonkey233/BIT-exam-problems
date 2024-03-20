#include <bits/stdc++.h>
using namespace std;
int main(){
	char ch;
	int n;
	cin >> ch >> n;
	if(!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')) {
		cout << "Input invaild: char must be a~z or A~Z." << endl;
		return 0;
	}
	if(n < 0 || n > 9) {
		cout << "Input invaild: num must be [0, 9]." << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i){
		char p = ch + n - i - 26 - 1;
		if(ch <= 'Z' && p < 'A') p += 26;
		else if(ch >= 'a' && p < 'a') p += 26;
		for(int j = 0; j < i; ++j) cout << " ";
		printf("%c", p);
		int space = (n - i - 1) * 2 - 1;
		if(space > 0) for(int j = 0; j < space; ++j) cout << " ";
		if(space > 0) printf("%c", p);
		cout << endl;
	}
	for(int i = 0; i < n - 1; ++i){
		unsigned char p = ch + i - 26 + 1;
		if(ch <= 'Z' && p < 'A') p += 26;
		else if(ch >= 'a' && p < 'a') p += 26;
		for(int j = 0; j < n - i - 2; ++j) cout << " ";
		printf("%c", p);
		for(int j = 0; j < i * 2 + 1; ++j) cout << " ";
		printf("%c", p);
		cout << endl;
	}
	return 0;
} 

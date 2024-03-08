#include <bits/stdc++.h>
using namespace std;
int main(){
	string str, sub, temp;
	cin >> str;
	for(int i = 1; i <= str.length() / 2; ++i){
		if(str.length() % i != 0) continue;
		sub = str.substr(0, i);
		temp = "";
		for(int j = 0; j < str.length() / i; ++j) temp += sub;
		if(str != temp) continue;
		cout << i;
		return 0;
	}
	cout << 0;
	return 0;
} 

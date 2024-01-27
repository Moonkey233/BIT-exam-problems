#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	int max = 0, cnt = 0;
	for(auto &c : str){
		if(c == '(') ++cnt;
		else if (c == ')') --cnt;
		max = max < cnt ? cnt : max;
	}
	cout << max;
	return 0;
}

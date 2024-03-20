#include <bits/stdc++.h>
using namespace std;
int main() {
	set<char> st1, st2;
	string a, b;
	cin >> a >> b;
	for(auto &ch : a) st1.insert(ch);
	for(auto &ch : b) st2.insert(ch);
	for(auto &ch : st1) if(st2.count(ch) == 0) st1.erase(ch);
	for(auto &ch : st1) cout << ch;
	return 0;
}

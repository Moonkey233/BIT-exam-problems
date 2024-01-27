#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b) {
	string al(a), bl(b);
	transform(al.begin(), al.end(), al.begin(), ::tolower);
	transform(bl.begin(), bl.end(), bl.begin(), ::tolower);
	if(al != bl) return al < bl;
	return a < b;
} 
int main() {
	vector<string> v;
	string str;
	while(cin >> str){
		if(str == "0") break;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	for(auto &e : v)
		cout << e << " ";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	string str;
	vector<string> v;
	while(t--){
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end()/*, greater<string>()*/);
	for(vector<string>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;
	return 0;
}

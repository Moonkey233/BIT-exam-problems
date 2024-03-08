#include <bits/stdc++.h>
using namespace std;
int main(){
	string str, sub;
	cin >> str;
	set<string> st;
	sub = "";
	for(int i = 0; i < str.length(); ++i){
		if(i + 1 < str.length() && str[i] == str[i+1]) sub += str[i];
		else {
			sub += str[i];
			st.insert(sub);
			sub = "";
		}
	}
	for(auto &ele : st) cout << ele << endl;
	return 0;
} 

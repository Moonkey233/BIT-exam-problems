#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<string> v_string;
	string s;
	while(cin>>s) v_string.push_back(s);
	sort(v_string.begin(),v_string.end());
	for(int i=0; i<v_string.size(); i++)
		cout<<v_string[i]<<" ";
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	set<string> st;
	map<char, int> mapL, mapH;
	int t;
	cin >> t;
	string str;
	while(t--){
		cin >> str;
		if(st.count(str) == 0){
			st.insert(str);
			if(str[0] >= 'a' && str[0] <= 'z')
				++mapL[str[0]];
			else if(str[0] >= 'A' && str[0] <= 'Z')
				++mapH[str[0]];
		}
	}
	map<char, int>::iterator itL = mapL.begin(), itH = mapH.begin();
	for(; itL != mapL.end() && itH != mapH.end();){
		if(itL->first - 32 == itH->first){
			cout << itL->first << "," << itL->second << " " << itH->first << "," << itH->second << " ";
			++itL;
			++itH;
		} else{
			cout << itL->first << "," << itL->second << " ";
			++itL;
		}
	}
	for(; itL != mapL.end(); ++itL)
		cout << itL->first << "," << itL->second << " ";
	for(; itH != mapH.end(); ++itH)
		cout << itH->first << "," << itH->second << " ";
	return 0;
} 

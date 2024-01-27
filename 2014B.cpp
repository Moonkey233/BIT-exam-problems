#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> v;
	stringstream ss;
	int n;
	while(cin >> n){
		if(n == 0) break;
		if(!count(v.begin(), v.end(), n)) {
			if(v.size() < 3) v.push_back(n);
			else {
				v.push_back(n);
				v.erase(v.begin());
			}
		} else {
			for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
				if(*it == n){
					v.erase(it);
					break;
				}
			}
			v.push_back(n);
		}
		ss.str("");
		for(vector<int>::reverse_iterator r_it = v.rbegin(); r_it != v.rend(); ++r_it)
			ss << *r_it << ",";
		cout << ss.str().substr(0, ss.str().length() - 1)<< endl; 
	}
	return 0;
}

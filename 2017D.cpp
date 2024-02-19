#include <bits/stdc++.h> //{21,13},{32,13},{24,14},{28,14},{14,11},{13,11}
using namespace std;
unordered_map<int, int> el;
set<int> sl, sr;
string str, m;
int pos = 0;
void add(string m){
	int x = stoi(m.substr(1, m.find(",")));
	int y = stoi(m.substr(m.find(",") + 1));
	el[x] = y;
	sl.insert(x);
	sr.insert(y);
}
string gen(int l){
	stringstream ss;
	vector<int> ee;
	for(auto &e : el) if(e.second == l) ee.push_back(e.first);
	sort(ee.begin(), ee.end());
	if(l != 0){
		ss << "{" << l;
		if(!ee.empty()) ss << ",[";
	}
	for(auto &e : ee){
		ss << gen(e);
		if(e != ee[ee.size() - 1]) ss << ",";
	}
	if(l != 0){
		if(!ee.empty()) ss << "]";
		ss << "}";
	}
	return ss.str();
}
int main(){
	getline(cin, str);
	while(!str.empty() && pos != string::npos){
		pos = str.find(",{");
		m = str.substr(0, pos);
		str = str.substr(pos + 1);
		add(m);
	}
	for(auto &e : sr) if(sl.count(e) == 0) el[e] = 0;
	cout << gen(0);
	return 0;
}

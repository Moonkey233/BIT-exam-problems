#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
multiset<int> mst;
int cc = 0;
bool isPrime(int n){
	if(n < 2) return false;
	if(n == 2 || n == 3) return true;
	if(n % 6 != 1 && n % 6 != 5) return false;
	for(int i = 5; i < floor(sqrt(n)); i += 6) if(n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}
int cmp(pr a, pr b){
	if(a.second != b.second) return a.second > b.second;
	return a.first > b.first;
}
void print(){
	set<pr> st;
	vector<pr> vc;
	for(auto &ele : mst) st.insert(pr(ele, mst.count(ele)));
	for(auto &ele : st) vc.push_back(ele);
	sort(vc.begin(), vc.end(), cmp);
	for(auto &ele : vc) cout << ele.first << " " << ele.second << " ";
	cout << endl;
	++cc;
}
void func(int p, int n){
	if(p > n) {
		print();
		return;
	}
	for(int i = 3; i <= (p + 1) / 2; i += 2){
		if(!isPrime(p - i) || !isPrime(i)) continue;
		mst.insert(i);
		mst.insert(p - i);
		func(p + 2, n);
		int cnt = mst.count(i);
		mst.erase(i);
		for(int j = 1; j < cnt; ++j) mst.insert(i);
		cnt = mst.count(p - i);
		mst.erase(p - i);
		for(int j = 1; j < cnt; ++j) mst.insert(p - i);
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	if(m & 1) func(m + 1, n);
	else func(m, n);
//	cout << cc;
	return 0;
}

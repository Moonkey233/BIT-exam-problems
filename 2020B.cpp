#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int cnta = 0, cntb = 0;
typedef pair<int, int> pr;
set<pr> st;
void dfs(int pos) {
	if(pos > c.length()) return;
	else if(pos == c.length()) {
		st.insert(pr(cnta, cntb));
		return;
	}
	d = c.substr(pos);
	int p = d.find(a), p2 = d.find(b);
	if(p == 0) {
		++cnta;
		dfs(pos+a.length());
		--cnta;
	}
	if(p2 == 0) {
		++cntb;
		dfs(pos+b.length());
		--cntb;
	}
}
int main() {
	cin >> a >> b >> c;
	dfs(0);
	if(!st.empty()) for(auto &e : st) cout << e.first << " " << e.second << endl;
	else cout << "FALSE" << endl;
	return 0;
}

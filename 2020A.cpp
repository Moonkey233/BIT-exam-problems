#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
int main() {
	int m, n, cnt = 0;
	cin >> m >> n;
	vector<vector<int>> vc(m, vector<int>(n, 0));
	queue<pr> qu, qu2;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> vc[i][j];
			if(vc[i][j] == 2) qu.push(pr(i, j));
		}
	}
	while(!qu.empty()){
		qu2 = qu;
		bool flag = true;
		while(!qu2.empty()) {
			pr p = qu2.front();
			qu.pop();
			qu2.pop();
			int i = p.first, j = p.second;
			if(i+1<m && vc[i+1][j] == 1) { qu.push(pr(i+1, j)), vc[i+1][j] = 2, flag = false; }
			if(i-1>=0 && vc[i-1][j] == 1) { qu.push(pr(i-1, j)), vc[i-1][j] = 2, flag = false; }
			if(j+1<n && vc[i][j+1] == 1) { qu.push(pr(i, j+1)), vc[i][j+1] = 2, flag = false; }
			if(j-1>=0 && vc[i][j-1] == 1) { qu.push(pr(i, j-1)), vc[i][j-1] = 2, flag = false; }
		}
		if(flag) break;
		++cnt;
	}
	for(auto &ele : vc) for(auto &e : ele) if(e == 1) {
		cout << "FALSE";
		return 0;
	}
	cout << cnt;
	return 0;
}

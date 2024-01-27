#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
	int max = 0, cnt = 0;
	for(int i = 1; i <= a.length(); ++i){
		for(int j = 1; j <= b.length(); ++j){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			if(dp[i][j] > max){
				max = dp[i][j];
				cnt = 1;
			} else if(dp[i][j] == max) ++cnt;
		}
	}
	cout << max << " " << cnt; 
	return 0;
}

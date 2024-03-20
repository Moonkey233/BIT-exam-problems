#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pr;
int main() {
	string str;
	cin >> str;
	if(str == "") return 0;
	vector<int> dp(str.length(), 0);
	dp[0] = 1;
	for(int i = 1; i < str.length(); ++i) {
		if(str[i] == str[i - 1]) dp[i] = dp[i - 1] + 1;
		else dp[i] = 1;
	}
	int max = 0;
	set<pr> st;
	for(auto &e : dp) if(max < e) max = e;
	for(int i = 0; i < str.length(); ++i) if(dp[i] == max) st.insert(pr(i + 2 - max, str[i]));
	for(auto &e : st) cout << e.first << ", " << e.second << endl;
	return 0;
}

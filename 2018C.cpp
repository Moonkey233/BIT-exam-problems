#include <bits/stdc++.h>
using namespace std;
int main() {
	int a;
	vector<int> vc;
	while(~scanf("%d",&a)) vc.push_back(a);
	vector<int> dp(vc.size());
	for(int i = 0; i < vc.size(); ++i) {
		if(i == 0) dp[i] = 1;
		else for(int j = i - 1; j >= 0; --j) if(vc[j] < vc[i]) if(dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
	}
	int max = 0;
	for(auto &e : dp) if(max < e) max = e;
	cout << max;
	return 0;
}

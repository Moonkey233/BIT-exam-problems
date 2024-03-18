#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	vector<int> nums;
	while(~scanf("%d", &n)) nums.push_back(n);
	if(nums.size() == 0) cout << 0;
	else if(nums.size() == 1) cout << nums[0];
	else if(nums.size() == 2) cout << max(nums[0], nums[1]);
	else {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		dp[1] = nums[1];
		int m = dp[0], ans = max(dp[0], dp[1]);
		for(int i = 2; i < nums.size(); ++i) {
			m = max(m, dp[i-2]);
			dp[i] = max(nums[i], nums[i] + m);
			ans = max(dp[i], ans);
		}
		cout << ans;
	}
	return 0;
}

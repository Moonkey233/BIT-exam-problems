#include <bits/stdc++.h>
using namespace std;
int main() {
	string str, ans;
	cin >> str;
	ans = str;
	stack<int> st, st2;
	for(int i = 0; i < str.length(); ++i) {
		if(str[i] == '[') st.push(i);
		else if(str[i] == '*') st2.push(i);
		else {
			if(!st.empty()) st.pop();
			else if(!st2.empty()) {
				ans[st2.top()] = ']';
				st2.pop();
			} else {
				cout << "false" << endl;
				return 0;
			}
		}
	}
	while(!st.empty() && !st2.empty()) {
		if(st.top() < st2.top()) {
			ans[st2.top()] = ']';
			st.pop();
			st2.pop();
		} else {
			cout << "false" << endl;
			return 0;
		}
	}
	if(!st.empty()) cout << "false" << endl;
	else cout << ans << endl;
	return 0;
}

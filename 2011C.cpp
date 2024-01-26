#include <bits/stdc++.h>
using namespace std;
int main() {
	stack<string> st;
	string str, s;
	cin >> str;
	cin >> s;
	st.push(s);
	int pos = str.find(s), level = 0;
	for(int i = pos; i != 0; --i) {
		if(str[i] == '(') {
			if(level > 0) --level;
			else {
				s = "";
				while(str[i-1] != '(' && str[i-1] != ')' && str[i-1] != ',' && i != 0)
					s += str[--i];
				reverse(s.begin(), s.end());
				st.push(s);
			}
		} else if(str[i] == ')')
			++level;
		else
			continue;
	}
	cout << st.top();
	st.pop();
	while(!st.empty()) {
		cout << ">" << st.top();
		st.pop();
	}
	return 0;
}

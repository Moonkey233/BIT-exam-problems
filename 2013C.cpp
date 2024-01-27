#include <bits/stdc++.h>
using namespace std;
int getLevel(char op){
	if(op == ')') return 0;
	if(op == '+' || op == '-') return 1;
	if(op == '*' || op == '/') return 2;
	else return 3;
}
int main() {
	stack<char> st;
	stringstream ss;
	string str;
	cin >> str;
	for(string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
		if((*it >= 'a' && *it <= 'z') || (*it >= 'A' && *it <= 'Z')) ss << *it;
		else if(*it == ')') st.push(*it);
		else if(*it == '(') {
			while(st.top() != ')'){
				ss << st.top();
				st.pop(); 
			}
			st.pop(); 
		} else {
			while(!st.empty() && getLevel(st.top()) > getLevel(*it)){
				ss << st.top();
				st.pop(); 
			}
			st.push(*it);
		}
	}
	while(!st.empty()){
		ss << st.top();
		st.pop();
	}
	str = ss.str();
	for(string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it)
		cout << *it;
	return 0;
}

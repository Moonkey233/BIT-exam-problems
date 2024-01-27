#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int cnt = 0;
void fun(string s, int n){
	if(n == 0) {
		ss << s << ",";
		++cnt;
	} else {
		fun(s + 'a', n - 1);
		fun(s + 'b', n - 1);
		fun(s + 'c', n - 1);
	}
}
int main() {
	int n;
	cin >> n;
	fun("", n);
	cout << ss.str().substr(0, ss.str().length() - 1) << " " << cnt << endl;
	return 0;
}

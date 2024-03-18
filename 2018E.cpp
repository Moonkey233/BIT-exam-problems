#include <bits/stdc++.h>
using namespace std;
stringstream anss;
bool isPrime(int n) {
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); ++i) if(n % i == 0) return false;
	return true;
}
void func(int n) {
	if(isPrime(n)) {
		anss << n << "*";
		return;
	}
	for(int i = 2; i <= n; ++i) {
		if(!isPrime(i)) continue;
		if(n % i == 0) {
			anss << i << "*";
			func(n/i);
			break;
		}
	}
}
int main() {
	int n;
	cin >> n;
	func(n);
	string ans = anss.str();
	ans[ans.length()-1] = '\0';
	cout << ans;
	return 0;
}

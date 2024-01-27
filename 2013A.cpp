#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if(a % b != 0)
		return gcd(b, a % b);
	else return b;
}
int main() {
	int a, b;
	scanf("%d,%d", &a, &b);
	cout << gcd(max(a, b), min(a, b));
	return 0;
}

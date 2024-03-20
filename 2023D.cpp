#include <bits/stdc++.h>
using namespace std;
vector<int> vc(1003, 0);
int f(int n) {
	if(vc[n] != 0) return vc[n];
	if(n <= 1) vc[n] = 4;
	else if(n == 2) vc[n] = 8;
	else vc[n] = f(n - 1) + f(n - 2);
	return vc[n];
}
double func(int n) {
	if(n == 1) return -1.0 / 4;
	else if(n % 2 == 0) return func(n - 1) + 1.0 / f(n);
	else return func(n - 1) - 1.0 / f(n);
}
int main() {
	int n;
	cin >> n;
	while(n <= 0) {
		cout << "Input n must bigger than 0." << endl;
		cin >> n;
	}
	printf("%6f\n", func(n));
	return 0;
}

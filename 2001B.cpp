#include <iostream>

using namespace std;

int fun(int n){
	int sum = 0;
	if (n >= 0)
		for(int i = n; i <= 2*n; ++i) sum += i;
	else
		for(int i = 2*n; i <= n; ++i) sum += i;
	return sum;
}

int main () {
	int n, k;
	cin >> k;
	for(int i = 0; i < k; ++i){
		cin >> n;
		cout << fun(n) << endl;
	}
	return 0;
}

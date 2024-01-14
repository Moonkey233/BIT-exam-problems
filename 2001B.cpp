#include <iostream>

using namespace std;

int fun(int n){
	int sum = 0;
	if (n >= 0)
		for(int i = n; i <= 2*n; ++i) sum += i;
	else
		for(int i = 2*n; i <= n; ++i) sum += i;
	
}

int main () {
	int n;
	cin >> n;
	cout << fun(n) << endl;
	return 0;
}

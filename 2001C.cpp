#include <iostream>

using namespace std;

int re(int n){
	int sum = 0;
	while(n){
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum;
}

int main(){
	for (int n = 1000; n <= 1111; ++n)
		if (n == re(9*n))
			cout << n << endl;
}

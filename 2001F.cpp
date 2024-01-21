#include <iostream>

using namespace std;
typedef long long ll;

ll fact(int n){
	if (n <= 1) return 1;
	else return n * fact(n-1);
}

int main(){
	int n, x;
	cin >> x;
	for(int i = 0; i < x; ++i){
		cin >> n;
		cout << fact(n) << endl;
	}
	return 0;
}

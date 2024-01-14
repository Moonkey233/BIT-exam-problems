#include <iostream>

using namespace std;
typedef long long ll;

ll fact(int n){
	if (n <= 1) return 1;
	else return n * fact(n-1);
}

int main(){
	int n;
	cin >> n;
	cout << fact(n) << endl;
	return 0;
}

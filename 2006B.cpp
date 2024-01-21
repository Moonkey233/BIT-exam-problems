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
	int cnt = 0, n;
	cin >> n;
	while(n && cnt < 10){
		cout << n << " " << re(n) << endl;
		++cnt;
		if(cnt >= 10) break;
		cin >> n;
	}
	return 0; 
}

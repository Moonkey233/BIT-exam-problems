#include<iostream>

using namespace std;

int fun(int n){
	if(n < 2) return n;
	return fun(n-1) + fun(n-2);
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n ; ++i){
		for(int j = 0; j < n - i - 1; ++j) cout << "  ";
		for(int j = 0; j < 2 * i + 1; ++j) cout << fun(j) << " ";
		cout << endl;
	}
	return 0;
}

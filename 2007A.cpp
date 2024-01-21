#include <iostream>

using namespace std;

double calculate(double h, int n){
	if(n == 1) return h;
	return 1.5 * h + calculate(0.5 * h, n - 1); 
}

int main(){
	int x, h, n;
	cin >> x;
	for(int i = 0; i < x; ++i){
		cin >> h >> n;
		printf("%.2f\n", calculate(h, n));
	}
	return 0;
}

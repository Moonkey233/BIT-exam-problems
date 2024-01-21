#include <iostream>

using namespace std;

double y(double x) {
	if (x >= 0 && x < 2) return -x+2.5;
	else if(x >= 2 && x < 4) return 2 - 1.5*(x-3)*(x-3);
	else if(x >= 4 && x < 6) return x / 2 - 1.5;
}

int main() {
	double x, n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> x;
		printf("y=%.1f\n", y(x));
	}
	
	return 0;
}

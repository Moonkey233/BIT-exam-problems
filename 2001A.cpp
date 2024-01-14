#include <iostream>

using namespace std;

double y(double x) {
	if (x >= 0 && x < 2) return -x+2.5;
	else if(x >= 2 && x < 4) return 2 - 1.5*(x-3)*(x-3);
	else if(x >= 4 && x < 6) return x / 2 - 1.5;
}

int main() {
	double x;
	do {
		cout << "input X([0-6)): ";
		cin >> x;
	} while(x < 0 || x >= 6);
	cout << y(x) << endl;
	return 0;
}

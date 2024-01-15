#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a = 0, b = 0, c = 0;
	do{
		cin >> a >> b >> c;
	}while(a == 0);
	double d = b * b - 4 * a * c;
	if(d > 0) cout << "X1 = " << (-b + sqrt(d))/(2*a) << " X2 = " << (-b - sqrt(d))/(2*a);
	else if(d == 0) cout << "X1 = X2 = " << -b/(2*a);
	else cout << "X1 = " << -b/(2*a) << "+" << sqrt(-d)/(2*a) << "i X2 = " << -b/(2*a) << "-" << sqrt(-d)/(2*a) << "i";
	return 0;
}

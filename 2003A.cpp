#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const double pi = 3.14159265358;
	int x;
	cin >> x;
	for(int i = 0; i < x; ++i){
		double x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		double r = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
		printf("%.2f %.2f\n", r, 4.0 / 3 * pi * r * r * r);
//		cout << r << " " << 4.0 / 3 * pi * r * r << endl;
	}
	return 0;
}

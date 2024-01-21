#include <iostream>
#include <cmath>

using namespace std;
const double pi = 3.14159265358;

class Angle{
public:
	Angle() { this->r = 0; };
	Angle(const double &r) { this->r = r; };
	Angle operator- (const Angle &r);
	double calculateSin();
	double getR() const { return this->r; };
	void setR(double r) { this->r = r; };
private:
	double r;
};

Angle Angle::operator- (const Angle &r){
	return Angle(this->r - r.getR());
}

double Angle::calculateSin(){
	double x = this->r * pi / 180;
	return sin(x);
//	return x - x*x*x/6 + x*x*x*x*x/120 - x*x*x*x*x*x*x/5040;
}

int main(){
	int x, aa, ab;
	cin >> x;
	for(int i = 0; i < x; ++i){
		cin >> aa >> ab;
		Angle a(aa), b(ab);
		printf("%.2f\n", (a-b).calculateSin());
//		cout << (a-b).calculateSin() << endl;
	}
	return 0;
}

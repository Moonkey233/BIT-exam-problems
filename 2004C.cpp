#include <iostream>

using namespace std;

class P {
	public:
		P(int n);
		~P();
		double calculate(const double &x);
	private:
		int maxN;
		double *p;
	protected:
		double pow(const double &x, const unsigned int &y);
};

P::P(int n){
	maxN = n;
	p = new double[n];
	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}
} 

P::~P(){
	delete[] p;
}

double P::calculate(const double &x){
	double ans = 0;
	for(int i = 0; i < maxN; ++i)
		ans += p[i] * pow (x, i);
	return ans;
}

double P::pow(const double &x, const unsigned int &y){
	if(y == 0) return 1;
	else return x*pow(x, y-1);
}

int main(){
	int n;
	cin >> n;
	P p(n);
	int x;
	cin >> x;
	cout << p.calculate(x) << endl; 
}

#include <iostream>

using namespace std;

class P {
	public:
		P(int n);
		~P();
		int calculate(const double &x);
	private:
		int maxN;
		double *p;
	protected:
		double pow(const double &x, const unsigned int &y);
};

P::P(int n){
	maxN = n + 1;
	p = new double[n+1];
	for(int i = 0; i < n+1; ++i){
		cin >> p[i];
	}
} 

P::~P(){
	delete[] p;
}

int P::calculate(const double &x){
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
	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; ++i){
		int n;
		cin >> n;
		P p(n);
		int x;
		cin >> x;
		printf("%d\n", p.calculate(x));
//		cout << p.calculate(x) << endl;
	}
	return 0;
}

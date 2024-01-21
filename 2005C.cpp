#include <iostream>

using namespace std;

class Complex{
	public:
		Complex();
		Complex(const int &a, const int &b);
		Complex operator + (const Complex &c) const;
		int getA() const { return a; }
		int getB() const { return b; }
	private:
		int a;
		int b; 
};

Complex::Complex(){
	a = 0;
	b = 0;
}

Complex::Complex(const int &a, const int &b){
	this->a = a;
	this->b = b;
}

Complex Complex::operator + (const Complex &c) const {
	return Complex(this->a + c.getA(), this->b + c.getB());
}

int main(){
	int x;
	cin >> x;
	for(int i = 0; i < x; ++i){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		Complex e = Complex(a, b) + Complex(c, d);
		char sign = e.getB() > 0 ? '+' : '-';
		int f = e.getB() > 0 ? e.getB() : -e.getB();
		cout << e.getA() << sign << f << "i" << endl;
	}
	return 0;
}

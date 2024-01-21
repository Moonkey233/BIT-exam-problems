#include <iostream>

using namespace std;

class CTriangle{
	public:
		CTriangle();
		CTriangle(const int &y, const int &x);
		CTriangle operator + (const CTriangle &c) const;
		void operator += (const CTriangle &c);
		int getY() const { return y; }
		int getX() const { return x; }
	private:
		int y;
		int x;
};

CTriangle::CTriangle(){
	this->y = 0;
	this->x = 0; 
}

CTriangle::CTriangle(const int &y, const int &x){
	this->y = y;
	this->x = x;
}

CTriangle CTriangle::operator + (const CTriangle &c) const{
	return CTriangle(this->y + c.getY(), this->x + c.getX()); 
}

void CTriangle::operator += (const CTriangle &c){
	this->y += c.getY();
	this->x += c.getX();
}

int main(){
	int y = 1, x;
	CTriangle c;
	while(1){
		cin >> y;
		if(!y) break;
		cin >> x;
		c += CTriangle(y, x);
	}
	cout << "A(0," << c.getY() <<"),B(0,0),C(" << c.getX() << ",0)" << endl;
	return 0;
}


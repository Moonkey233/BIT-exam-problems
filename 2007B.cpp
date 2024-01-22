#include <iostream>
#include <cmath>

using namespace std;

class CPoint{
	public:
		CPoint();
		CPoint(const int &x, const int &y);
		CPoint operator - (const CPoint &c) const;
		double distance(const CPoint &c) const;
		int getX() const { return x; }
		int getY() const { return y; }
	private:
		int x;
		int y;
};

CPoint::CPoint(){
	this->x = 0;
	this->y = 0;
}

CPoint::CPoint(const int &x, const int &y){
	this->x = x;
	this->y = y;
}

CPoint CPoint::operator - (const CPoint &c) const{
	return CPoint(this->x - c.getX(), this->y - c.getY());
}

double CPoint::distance(const CPoint &c) const{
	CPoint p = CPoint(this->x, this->y) - c;
	return sqrt(p.getX() * p.getX() + p.getY() * p.getY());
}

int main(){
	int x, a, b, c, d;
	cin >> x;
	for(int i = 0; i < x; ++i){
		cin >> a >> b >> c >> d;
		CPoint p1(a, b);
		printf("%.2f\n", p1.distance(CPoint(c, d)));
	}
	return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

class CPoint{
	public:
		CPoint() { this->x = 0; this->y = 0; }
		CPoint(const int &x, const int &y) { this->x = x; this->y = y; }
		int getX() const { return x; }
		int getY() const { return y; }
		void setX(const int &x) { this->x = x; }
		void setY(const int &y) { this->y = y; }
		double distance(const CPoint &p) const { return sqrt((x - p.getX()) * (x - p.getX()) + (y - p.getY()) * (y - p.getY())); } 
	private:
		int x;
		int y;
};

class CTriangle{
	public:
		CTriangle();
		CTriangle(const int &x1, const int &y1, const int &x2, const int &y2, const int &x3, const int &y3);
		CTriangle(const CPoint &a, const CPoint &b, const CPoint &c);
		int isRightAngle() const;
		double calculateCircumference();
	private:
		CPoint a, b, c;
};

CTriangle::CTriangle(){
	a.setX(0);
	a.setY(0);
	b.setX(0);
	b.setY(0);
	c.setX(0);
	c.setY(0);
}

CTriangle::CTriangle(const int &x1, const int &y1, const int &x2, const int &y2, const int &x3, const int &y3){
	a.setX(x1);
	a.setY(y1);
	b.setX(x2);
	b.setY(y2);
	c.setX(x3);
	c.setY(y3);
}

CTriangle::CTriangle(const CPoint &a, const CPoint &b, const CPoint &c){
	this->a = a;
	this->b = b;
	this->c = c;
}

int CTriangle::isRightAngle() const{
	double d1 = a.distance(b), d2 = a.distance(c), d3 = b.distance(c);
	if(d1 > d2) {
		double t = d1;
		d1 = d2;
		d2 = t;
	}
	if(d1 > d3) {
		double t = d1;
		d1 = d3;
		d3 = t;
	}
	if(d2 > d3) {
		double t = d2;
		d2 = d3;
		d3 = t;
	}
	if(fabs(d1*d1+d2*d2-d3*d3) < 1e-6) return 1;
	else return 0;
}

double CTriangle::calculateCircumference(){
	return a.distance(b) + a.distance(c) + b.distance(c);   
}


int main(){
	int x, a, b, c, d, e, f;
	cin >> x;
	for(int i = 0; i < x; ++i){
		cin >> a >> b >> c >> d >> e >> f;
		CTriangle t(a, b, c, d, e, f);
		if(t.isRightAngle()) cout << "Yes" << endl;
		else cout << "No" << endl;
		printf("%.2f\n", t.calculateCircumference());
	}
	return 0;
}

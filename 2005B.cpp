#include <iostream>
#include <string>
#include <sstream>

using namespace std;

static int monthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
	public:
		Date();
		Date(const string &date);
		void setDate(const string &date);
		string getDate();
		void print();
		Date operator++ ();
		Date operator-- ();
		Date operator+ (const int &d);
		Date operator+ (const Date &date);
		Date operator- (const int &d);
		Date operator- (const Date &date);
		int getYear() const {
			return year;
		}
		int getMonth() const {
			return month;
		}
		int getDay() const {
			return day;
		}
	protected:
		void adjust();
	private:
		int year;
		int month;
		int day;
};

Date::Date() {
	int d;
	cin >> year >> month >> day >> d;
	day += d;
	adjust();
}
Date::Date(const string &date) {
	setDate(date);
}
void Date::setDate(const string &date) {
	int y = 0, m = 0, d = 0, i = 0;
	for(; date[i] != '-' && i < date.length(); ++i)
		y = y*10 + date[i] - '0';
	for(++i; date[i] != '-' && i < date.length(); ++i)
		m = m*10 + date[i] - '0';
	for(++i; date[i] != '-' && i < date.length(); ++i)
		d = d*10 + date[i] - '0';
	if(d <= 0 || d > 30 || m <= 0 || m > 12)
		cout << "INVALID" << endl;
	else {
		year = y;
		month = m;
		day = d;
	}
}
string Date::getDate() {
	stringstream ss;
	if(year < 0) {
		ss << "��Ԫǰ";
		ss << -year;
	} else
		ss << year;
	ss << "-";
	if(month < 10) ss << "0";
	ss << month;
	ss << "-";
	if(day < 10) ss << "0";
	ss << day;
	return ss.str();
}
void Date::print() {
	adjust();
	cout << getDate();
}
Date Date::operator++ () {
	day++;
	adjust();
}
Date Date::operator-- () {
	day--;
	adjust();
}
Date Date::operator+ (const int &d) {
	day += d;
	adjust();
}
Date Date::operator+ (const Date &date) {
	day += date.getDay();
	month += date.getMonth();
	year += date.getYear();
	adjust();
}
Date Date::operator- (const int &d) {
	day -= d;
	adjust();
}
Date Date::operator- (const Date &date) {
	day -= date.getDay();
	month -= date.getMonth();
	year -= date.getYear();
	adjust();
}
void Date::adjust() {
	int d;
	do {
		if(day <= 0) {
			month -= 1;
			day += monthDay[month];
		}
		d = (month == 2 && (year%400==0 || (year%4==0&&year%100!=0))) ? 1 : 0;
		if(day > monthDay[month] + d) {
//			cout << month << " " << day << " " << monthDay[month] << endl;
			day -= monthDay[month];
			if(month == 2 && (year%400==0 || (year%4==0&&year%100!=0))) --day;
			month += 1;
		}
		if(month <= 0) {
			year -= 1;
			month += 12;
		}
		if(month > 12) {
			year += 1;
			month -= 12;
		}
		d = (month == 2 && (year%400==0 || (year%4==0&&year%100!=0))) ? 1 : 0;
	} while(day <= 0 || day > (monthDay[month] + d) || month <= 0 || month > 12);
}

int main() {
//	Date a("1999-10-20");
//	++a;
//	a.print();
//	a.setDate("2004-03-30");
//	++a;
//	a.print();
//	a.setDate("2004-12-30");
//	++a;
//	a.print();
//	a.setDate("0-1-1");
//	--a;
//	a.print();
	int x;
	cin >> x;
	for(int i = 0; i < x; ++i) {
		Date a;
//		++a;
		a.print();
		cout << endl;
	}
	return 0;
}

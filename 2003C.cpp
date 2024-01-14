#include <iostream>

using namespace std;

int monthDay(int m, int y){
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	if(m != 2) return 30;
	if(m == 2){
		if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) return 29;
		return 28;
	}
}

int main(){
	int year, month, day, cnt = 0;
	cin >> year >> month >> day;
	for(int i = 1; i < month; ++i)
		cnt += monthDay(i, year); 
	cnt += day;
	cout << cnt << endl;
	return 0;
}

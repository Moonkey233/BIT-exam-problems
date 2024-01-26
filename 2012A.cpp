#include <bits/stdc++.h>
using namespace std;
int main() {
	int ary[10];
	for(int i = 0; i < 10; ++i){
		cin >> ary[i];
	}
	sort(ary, ary+10);
	for(int i = 0; i < 10; ++i){
		cout << ary[i] << " ";
	}
	return 0;	
}

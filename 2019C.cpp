#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, sum = 0;
	vector<int> vc;
	while(~scanf("%d", &a)) vc.push_back(a);
	while(vc.size() >= 2){
		sort(vc.begin(), vc.end(), greater<int>());
		a = vc.back(), vc.pop_back();
		b = vc.back(), vc.pop_back();
		vc.push_back(a+b);
		sum += (a + b);
	}
	cout << sum;
	return 0;
} 

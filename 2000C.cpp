#include <iostream>

using namespace std;

int getSum(int n){
	int sum = 1;
	for(int i = 2; i <= n / 2; ++i) if(n % i == 0) sum += i;
	return sum;
}

int main(){
	int E[60] = {0}, G[60] = {0}, cntE = 0, cntG = 0;
	for(int i = 2; i <= 60; ++i){
		if(i == getSum(i)) E[cntE++] = i;
		else if(i < getSum(i)) G[cntG++] = i;
	}
	cout << "E:";
	for(int i = 0; i < cntE; ++i) cout << " " << E[i];
	cout << "\nG:";
	for(int i = 0; i < cntG; ++i) cout << " " << G[i];
}

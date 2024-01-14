#include <iostream>

using namespace std;

int re(int n){
	int sum = 0;
	while(n){
		sum = sum * 10 + n % 10;
		n /= 10;
	}
	return sum;
}

int main(){
	for(int i = 0; i < 256; ++i)
		if(i*i == re(i*i)) cout << i << endl;
	return 0;
}

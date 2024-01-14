#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	for(int i = 0; i <= 5; ++i) {
		for(int j = 0; j <= 4; ++j) {
			for(int k = 0; k <= 6; ++k) {
				if(i+j+k==0) continue;
				++sum;
				cout<<0.8*i+1*j+1.8*k<<endl;
			}
		}
	}
	cout << sum << endl;
	return 0;
}

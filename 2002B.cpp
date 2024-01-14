#include <iostream>

using namespace std;

int tr(int i, int j) {
	if(!(j > 0 && i > j)) return 1;
	else return tr(i-1, j-1) + tr(i-1, j);
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int k = 0; k < n - i - 1; ++k) cout << " ";
		for(int j = 0; j <= i; ++j)
			cout << tr(i, j) << " ";
		cout << endl;
	}
	return 0;
}

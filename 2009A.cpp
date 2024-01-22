#include <iostream>
#include <string>

using namespace std;

int main() {
	string str[4];
	int pos = 0, cnt = 0, x;
	cin >> x;
	while(x--) {
		cin >> str[pos];
		++cnt;
		for(int i = 0; i < (cnt > 4 ? 4 : cnt); ++i)
			cout << i + 1 << "=" << str[(pos-i+4)%4] << " ";
		++pos %= 4;
		cout << endl;
	}
	return 0;
}

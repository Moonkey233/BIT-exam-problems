#include <iostream>

using namespace std;

int main() {
	char str[5] = {0};
	cin >> str;
	for(int i = 0; i < 4; i++)
		cout<<str[3-i];
	return 0;
}

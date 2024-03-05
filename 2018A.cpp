#include <bits/stdc++.h>
using namespace std;
int main() {
	string in, str = "^";
	cin >> in;
	for(auto &ch : in) {
		if(ch >= 'A' && ch <= 'Z') ch += 32;
		str = str + "#" + ch;
	}
	str = str + "#$";
	int maxL = 0, cnt = 0, len = str.length();
	for(int i = 0; i < len; ++i) {
		if(i + maxL > len) break;
		for(int j = 0; j <= i && i + j < len; ++j) {
			if(str[i-j] != str[i+j]) {
				if(str[i-j] != '#') j = j - 2;
				else j = j - 1;
				if(maxL < j) {
					maxL = j;
					cnt = 1;
				} else if(maxL == j) ++cnt;
				break;
			}
		}
	}
	cout << maxL + 1 << " " << cnt;
	return 0;
}

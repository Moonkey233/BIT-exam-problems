#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string str[4];
	int pos = 0, cnt = 0, x;
	cin >> x;
	ofstream outFile("Name.txt");
	while(x--){
		cin >> str[pos];
		++cnt;
		for(int i = 0; i < (cnt > 4 ? 4 : cnt); ++i)
			outFile << i + 1 << "=" << str[(pos-i+4)%4] << " ";
		++pos;
		pos %= 4;
		outFile << endl;
	}
	outFile.close();
	return 0;
}

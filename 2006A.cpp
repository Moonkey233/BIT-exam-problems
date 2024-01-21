#include <iostream>
#include <string>

using namespace std;

int main(){
	int x;
	cin >> x;
	string str;
	for(int i = 0; i < x; ++i){
		cin >> str;
		for(int j = 0; j < str.length(); ++j)
			if(str[j] >= '0' && str[j] <= '9')
				cout << j+1 << " ";
		cout << endl;
	}
	return 0;
}

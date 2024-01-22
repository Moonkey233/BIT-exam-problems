#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int stringCmp(string a, string b) {
	for(int i = 0; i < a.length() && i < b.length(); ++i){
		if(a[i] > b[i]) return 1;
		else if(a[i] < b[i]) return -1;
	}
	if(a.length() > b.length()) return 1;
	else if(a.length() < b.length()) return -1;
	else return 0;
}

int partition(string *ary, int low, int high) {
	string pivot = ary[low];
	while(low < high) {
		while(low < high && stringCmp(ary[high], pivot) > 0 ) --high;
		if(low < high) ary[low++] = ary[high];
		while(low < high && stringCmp(ary[low], pivot) < 0) ++low;
		if(low < high) ary[high--] = ary[low];
	}
	ary[low] = pivot;
	return low;
}

void qSort(string *ary, int low, int high) {
	if(low < high) {
		int mid = partition(ary, low, high);
		qSort(ary, low, mid - 1);
		qSort(ary, mid + 1, high);
	}
}

int main() {
	string str, word[1003];
	int cnt = 0, flag = 0, cntW;
	stringstream ss;
	getline(cin, str);
	for(int i = 0; i < str.length(); ++i)
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
	for(int i = 0; i <= str.length(); ++i) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			ss << str[i];
			flag = 1;
		} else {
			if(flag) {
				word[cnt++] = ss.str();
				ss.str("");
			}
			flag = 0;
		}
	}
	qSort(word, 0, cnt - 1);
	for(int i = 0; i < cnt; ++i){
		cntW = 1;
		while(word[i] == word[i+1]) {
			++i;
			++cntW;
		}
		cout << word[i] << ":" << cntW << endl; 
	}
	return 0;
}

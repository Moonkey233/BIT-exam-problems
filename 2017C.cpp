#include <bits/stdc++.h>
using namespace std;
void judge(const int &score, const string &str){
	cout << score << "分制 ";
	int w = 0, l = 0, cnt = 0;
	for(auto &c : str){
		if(c == 'W') ++w;
		else ++l;
		if(w == score || l == score) {
			cout << "第" << ++cnt << "局: " << w << ":" << l << " ";
			w = 0;
			l = 0;
		}
	}
	if(w != 0 || l != 0) cout << "第" << ++cnt << "局: " << w << ":" << l << endl;
}
int main(){
	string str;
	char ch;	
	while((ch = getchar()) != 'E') if(ch == 'W' || ch == 'L') str += ch;
	judge(11, str);
	judge(21, str);
	return 0;
}

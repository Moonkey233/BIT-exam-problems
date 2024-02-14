#include <bits/stdc++.h>
using namespace std;
typedef struct Student{
	string name;
	vector <int> v;
	double avg;
	int cnt;
}S;
int cmpAvg(S a, S b){ return a.avg > b.avg; }
int cmpCnt(S a, S b){ return a.cnt > b.cnt; }
int main(){
	int i;
	string buf;
	vector <S> stu;
	while(getline(cin, buf)){
		S s;
		if(find(buf.begin(), buf.end(), ' ') == buf.end()) break;
		stringstream ss;
		ss.str("");
		for(i = 0; i < buf.length() && buf[i] != ' '; ++i) ss << buf[i];
		s.name = ss.str();
		while(++i < buf.length() && buf[i] == ' ');
		if(i >= buf.length()) continue;
		for(; i < buf.length(); ++i){
			if(buf[i] == ' ') continue;
			else s.v.push_back(buf[i] - '0');
		}
		stu.push_back(s);
	}
	for(auto &e : stu){
		e.cnt = 0;
		double sum = 0;
		for(auto &ele: e.v){
			if(ele <= 2) ++e.cnt;
			sum += ele;
		}
		e.avg = sum / e.v.size();
	}
	sort(stu.begin(), stu.end(), cmpAvg);
	for(auto &e : stu) printf("%s %1.1f\n", e.name.c_str(), e.avg);
	cout << endl;
	sort(stu.begin(), stu.end(), cmpCnt);
	for(auto &e : stu) if(e.cnt >= 2) cout << e.name << " " << e.cnt << endl;
	return 0;
}

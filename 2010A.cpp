#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	vector<int> v;
	cout<<"请输入您的数据:"<<endl;
	getline(cin,s,',');
	istringstream sin(s);
	for(int a; sin>>a; )
		v.push_back(a);
	while(1) {
		string t;
		char ch;
		cout<<"请输入命令:";
		getline(cin, t, ',');
		istringstream tin(t);
		tin>>ch;
		if(ch=='a') {
			int b;
			tin>>b;
			v.push_back(b);
			for(int i=0; i<v.size(); i++)
				cout<<v[i]<<" ";
			cout<<endl;
		}
		if(ch=='s') {
			sort(v.begin(),v.end());
			for(int i=0; i<v.size(); i++)
				cout<<v[i]<<" ";
			cout<<endl;
		}
		if(ch=='d') {
			vector<int>::iterator rase;
			int c;
			tin>>c;
			for(int i=0; i<v.size(); i++) {
				if(c==v[i]) {
					rase=v.begin()+i;
					v.erase(rase);
				}
			}
			for(int j=0; j<v.size(); j++)
				cout<<v[j]<<" ";
			cout<<endl;
		}
		if(ch=='c') {
			char ch1,ch2;
			int c,d;
			tin>>ch1;
			tin>>c>>ch2;
			tin>>d;
			for(int i=0; i<v.size(); i++) {
				if(v[i]==c) {
					v[i]=d;
				}
			}
			for(int j=0; j<v.size(); j++)
				cout<<v[j]<<" ";
			cout<<endl;
		}
		if(ch=='0') {
			return 0;
		}
	}
}

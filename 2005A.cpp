#include<iostream>
#include<string>

using namespace std;

int main() {
	string str1,str2;
	cout<<"ÇëÊäÈëÁ½¸ö×Ö·û´®£º";
	cin>>str1>>str2;
	if(str1.length()>str2.length())
		cout<<str1<<" is long than "<<str2<<endl;
	else if(str1.length()==str1.length())
		cout<<str1<<" and "<<str2<<" is equal long"<<endl;
	else
		cout<<str2<<" is long than "<<str1<<endl;
	return 0;
}

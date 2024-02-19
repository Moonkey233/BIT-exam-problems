#include <bits/stdc++.h> //-90 -32 12 16 24 36 45 59 98 120
using namespace std;
int main(){
	string str, num;
	getline(cin, str);
	str += " ";
	vector<int> v;
	for(auto &ch : str){
		if(ch == ' '){
			v.push_back(stoi(num));
			num = "";
			continue;
		} else {
			if(ch != '-' && ch != '+' && (ch < '0' || ch > '9')) break;
			num += ch;
		}
	}
	sort(v.begin(), v.end());
	int target;
	while(cin >> target){
		int low = 0, high = v.size() - 1, mid = (low + high) / 2, cnt = 0;
		while(v[mid] != target && low <= high){
			if(v[mid] < target) {
				low = mid + 1;
				mid = (low + high) / 2;
			} else {
				high = mid - 1;
				mid = (low + high) / 2;
			}
			++cnt;
		}
		if(v[mid] == target) cout << "��" << mid + 1 << "��Ԫ����" << target << ", �Ƚϴ���Ϊ" << cnt + 1 << endl;
		else cout << "����ʧ��, �Ƚϴ���Ϊ" << cnt << endl; 
	}
	return 0;
}

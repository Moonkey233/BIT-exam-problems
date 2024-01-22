#include <iostream>
#include <cstring>

using namespace std;

int cntA[103][1003], a[103];

int partition(int *ary, int low, int high){
	int pivot = ary[low];
	while(low < high){
		while(low < high && ary[high] > pivot) --high;
		if(low < high) ary[low++] = ary[high];
		while(low < high && ary[low] < pivot) ++low;
		if(low < high) ary[high--] = ary[low];
	}
	ary[low] = pivot;
	return low;
}

void qSort(int *ary, int low, int high){
	if(low < high){
		int mid = partition(ary, low, high);
		qSort(ary, low, mid - 1);
		qSort(ary, mid + 1, high);   
	}
}

int main(){
	int t, n, k, maxK;
	cin >> t;
	while(t--){
		memset(cntA, 0, sizeof cntA);
		memset(a, 0, sizeof a);
		maxK = 0;
		cin >> n;
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		for(int i = 0; i < n; ++i){
			cin >> k;
			if(maxK < k) maxK = k;
			++cntA[k][a[i]];
		}
		qSort(a, 0, n - 1);
		for(int i = 1; i <= maxK; ++i){
			cout << i << "={";
			int cnt = 0;
			for(int j = 0; j < n; ++j){
				while(a[j] == a[j+1] && a[j+1] != 0) ++j;
				if(cnt++) cout << ",";
				cout << a[j] << "=" << cntA[i][a[j]];
			}
			cout << "}" << endl;
		}
	}
	return 0;
}

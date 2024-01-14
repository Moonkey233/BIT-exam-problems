#include <iostream>

using namespace std;

int partition(char *str, int low, int high) {
	char pivot = str[low];
	while(low < high) {
		while(low < high && str[high] > pivot) --high;
		if(low < high) str[low++] = str[high];
		while(low < high && str[low] < pivot) ++low;
		if(low < high) str[high--] = str[low];
	}
	str[low] = pivot;
	return low;
}

int quickSort(char *str, int low, int high) {
	if(low < high) {
		int mid = partition(str, low, high);
		quickSort(str, low, mid - 1);
		quickSort(str, mid + 1, high);
	}
}

int main() {
	char str[20] = {0};
	cin >> str;
	int len;
	for(int i = 0; str[i] != '\0'; ++i) ++len;
	quickSort(str, 0, len-1);
	cout << str << endl;
	return 0;
}

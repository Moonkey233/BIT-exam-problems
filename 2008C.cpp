#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	int res;
	try {
		int divisor = 0;
		if (divisor != 0) res = 10 / divisor;
		else throw runtime_error("Division by zero");
	} catch (const exception &e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	try {
		int arr[5] = {1, 2, 3, 4, 5};
		int index = 10;
		if (index >= 0 && index < 5) {
			int value = arr[index];
			cout << "Value: " << value << endl;
		} else throw runtime_error("Array index out of bounds");
	} catch (const exception &e) {
		cout << "Caught exception: " << e.what() << endl;
	}
	return 0;
}

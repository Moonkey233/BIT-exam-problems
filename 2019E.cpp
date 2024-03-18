#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void n_to_m(ll n, ll m) {
	if(n%m != n) n_to_m(n/m, m);
	if(n%m < 10) cout << n%m;
	else if(n%m < 36) cout << (char)(n%m-10+'A');
	else cout << (n%m-36+'a');
}
int main() {
	ll m, n;
	cin >> m >> n;
	n_to_m(n, m);
	return 0;
}

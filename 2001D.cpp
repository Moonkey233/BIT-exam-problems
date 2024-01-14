#include <iostream>

using namespace std;

typedef struct node {
	int number;
	int flag;
	struct node *next;
} NODE;

NODE* init(int n) {
	if (n == 0) return 0;
	NODE *p = new NODE;
	p->flag = 1, p->number = 1, p->next = 0;
	NODE *t = 0, *q = p;
	for(int i = 2; i <= n; ++i) {
		t = new NODE;
		t->flag = 1, t->number = i, t->next = 0;
		q->next = t;
		q = t;
	}
	q->next = p;
	return p;
}

int main() {
	int n, mod = 1;
	cin >> n;
	if(n <= 0) return -1;
	NODE *p = init(n), *q = p;
	int cnt = n;
	while(cnt) {
		if(q->flag == 1) {
			if(mod % 3 == 0) {
				q->flag = -1;
				--cnt;
				cout << q->number << " ";
			}
			++mod;
		}
		q = q->next;
	}
	q = p;
	NODE *t = p->next;
	for(int i = 0; i < n; ++i) {
		delete q;
		q = t;
		if(i < n - 1) t = t->next;
	}
}

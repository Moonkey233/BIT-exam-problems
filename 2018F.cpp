#include <bits/stdc++.h>
using namespace std;
typedef struct node{
	int data;
	struct node *next;
}Node, *List;
int main(){
	int n;
	vector<int> ary;
	cin >> n;
	while(n != 0){
		ary.push_back(n);
		cin >> n;
	}
	List l1 = new Node, l2 = new Node;
	l1->next = nullptr, l2->next = nullptr;
	for(auto &e : ary) {
		if(e & 1){
			Node *temp = l1;
			while(temp->next && e < temp->next->data) temp = temp->next;
			Node *p = new Node;
			p->data = e;
			p->next = temp->next;
			temp->next = p;
		} else {
			Node *temp = l2;
			while(temp->next && e > temp->next->data) temp = temp->next;
			Node *p = new Node;
			p->data = e;
			p->next = temp->next;
			temp->next = p;
		}
	}
	Node *temp = l1->next;
	cout << "l1";
	while(temp) {
		cout << "->" << temp->data;
		temp = temp->next;
	}
	temp = l2->next;
	cout << endl << "l2";
	while(temp) {
		cout << "->" << temp->data;
		temp = temp->next;
	}
	temp = l1->next;
	while(temp) {
		free(l1);
		l1 = temp;
		temp = temp->next;
	}
	temp = l2->next;
	while(temp) {
		free(l2);
		l2 = temp;
		temp = temp->next;
	}
	free(l1), free(l2);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef struct BiNode{
	char data;
	struct BiNode *lchild, *rchild;	
}BiNode, *BiTree;

void buildTree(BiTree &t, string post, string in){
	if(post == "" || in == "") return;
	t = new BiNode;
	t -> lchild = nullptr;
	t -> rchild = nullptr;
	t->data = post[post.length() - 1];
	int pos = in.find(t->data);
	buildTree(t->lchild, post.substr(0, pos), in.substr(0, pos));
	buildTree(t->rchild, post.substr(pos, post.length() - pos - 1), in.substr(pos + 1));
}

void preVisit(BiTree t){
	if(t){
		cout << t->data;
		preVisit(t->lchild);
		preVisit(t->rchild);
	}
}

deleteTree(BiTree &t){
	if(t){
		deleteTree(t->lchild);
		deleteTree(t->rchild);
		delete t;
		t = nullptr;
	}
}

int main() {
	BiTree t = nullptr;
	string post, in;
	cin >> post >> in;
	buildTree(t, post, in);
	preVisit(t);
	deleteTree(t);
	return 0;
}

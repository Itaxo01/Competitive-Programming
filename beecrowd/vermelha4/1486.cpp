#include <bits/stdc++.h>
using namespace std;


class node{
	public:
		int data;
		node *right;
		node *left;
		void insert(int d){
			if(d > data)
				if(right != nullptr) right->insert(d);
				else right = new node(d);
			else
				if(left != nullptr) left->insert(d);
				else left = new node(d);
		}
	
		node(int d){
			data = d;
			right = nullptr;
			left = nullptr;
		}
};
class btree{
	public:
		node *root;
		int size;
		void insert(int d){
			if(size == 0){
				size++;
				root = new node(d);
			}
			else root->insert(d);
		}
		btree(){
			root = nullptr;
			size = 0;
		}
};
int ct = 1;

void bfs(btree *b){
	queue<node*> q;
	q.push(b->root);
	bool first = true;
	while(!q.empty()){
		node *e = q.front(); q.pop();
		if(!first) cout<<" ";
		first = false;
		cout<<e->data;
		if(e->left != nullptr) q.push(e->left);
		if(e->right != nullptr) q.push(e->right);
	}
}

void work(){
	int n; cin>>n;
	btree *b = new btree();
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		b->insert(a);
	}
	printf("Case %d:\n", ct++);
	bfs(b);
	cout<<"\n\n";
}

int main(){
	int n; cin>>n;
	while(n--) work();
}
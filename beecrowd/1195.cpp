#include <bits/stdc++.h>

using namespace std;

class binary_tree{
	binary_tree *left, *right;
	int data;
	public:
		binary_tree(int data){
			this->data = data;
			left = right = NULL;
		}
		binary_tree(){
			this->data = -1;
			left = right = NULL;
		}
		void insert(int data){
			if(this->data == -1) this->data = data;
			else if(data < this->data){
				if(left == NULL) left = new binary_tree(data);
				else left->insert(data);
			}
			else{
				if(right == NULL) right = new binary_tree(data);
				else right->insert(data);
			}
		}
		void post(){
			if(left != NULL) left->post();
			if(right != NULL) right->post();
			cout<<" "<<data;
		}

		void in(){
			if(left != NULL) left->in();
			cout<<" "<<data;
			if(right != NULL) right->in();
		}

		void pre(){
			cout<<" "<<data;
			if(left != NULL) left->pre();
			if(right != NULL) right->pre();
		}
};



int main(){
	int n; cin>>n; 
	int c = 1;
	while(n--){
		int a; cin>>a;
		binary_tree tree = binary_tree();
		for(int i = 0; i<a; i++){
			int c; cin>>c;
			tree.insert(c);
		}
		printf("Case %d:\n", c++);
		cout<<"Pre.:"; tree.pre(); cout<<endl;
		cout<<"In..:"; tree.in(); cout<<endl;
		cout<<"Post:"; tree.post(); cout<<endl<<endl;
	}
}
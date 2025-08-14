#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int ALPHABET_SIZE = 26; 

struct Node { 
    int len; 
	 ll value = 0;
	 Node *prev;
	 Node *next[ALPHABET_SIZE];

    Node(int l = 0, Node *s = nullptr) : len(l), prev(s) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            next[i] = nullptr;
        }
    }
};

struct Eertree {
    string s; 
    vector<Node*> tree;
    int num; 
    Node *suff; 
	 
	 ll res = 0; 

    Eertree(string aux_s = "") {
		tree.emplace_back(new Node(-1)); 
		tree.emplace_back(new Node(0)); 
		tree[0]->prev = tree[0]; 
		tree[1]->prev = tree[0]; 

		num = 2;
		suff = tree[1];

		for(char e: aux_s) {
			add(e);
		}
    }

	 void add(char ch) {
        s += ch;
        int c = ch - 'a';
        Node *cur = suff; 

		  int N = s.size();
        while (true) {
            if (N - cur->len - 2 >= 0 && s[N - cur->len - 2] == ch) {
                break;
            }
            cur = cur->prev;
        }

        if (cur->next[c] != 0) {
            suff = cur->next[c];
            return;
        }
		  
        tree.emplace_back(new Node(cur->len + 2));
		  suff = tree[num++];

        cur->next[c] = suff;
		  
        if (suff->len == 1) {
			  suff->prev = tree[1];
			  res += suff->value = (c+1);
			  return;
			}

			suff->value = cur->value + 2*(c+1);
			res += suff->value;

        while (true) {
            cur = cur->prev;
            if (N - cur->len - 2 >= 0 && s[N - cur->len - 2] == ch) {
                suff->prev = cur->next[c];
                break;
            }
        }
    }
};

int main() {
	int n; cin>>n;
	string s; cin>>s;

	Eertree *er = new Eertree(s);
	cout<<er->res<<endl;
}
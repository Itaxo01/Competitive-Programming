#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; 
	while(cin>>n){
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		map<int, int> quantia;
		int answer = -1;
		bool stack = true, queue = true, p_q = true;
		for(int i = 0; i<n; i++){
			int a, b; cin>>a>>b;
			if(answer == 3) continue;
			if(a == 1){
				if(stack) s.push(b);
				if(queue) q.push(b);
				if(p_q) pq.push(b);
				quantia[b]++;
			} else {
				if(quantia[b] <= 0) answer = 3;
				if(stack){
					if(s.top() != b) stack = false;
					else s.pop();
				}
				if(queue){
					if(q.front() != b) queue = false;
					else q.pop();
				}
				if(p_q){
					if(pq.top() != b) p_q = false;
					else pq.pop();
				}
			}
		}
		if(answer == 3) printf("impossible\n");
		else {
			answer = stack+queue+p_q;

			if(answer > 1) printf("not sure\n");
			else if(answer == 0) printf("impossible\n");
			else {
				if(stack) printf("stack\n");
				if(queue) printf("queue\n");
				if(p_q) printf("priority queue\n");
			}
		}
	}





}
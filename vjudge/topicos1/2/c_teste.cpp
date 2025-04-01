#include <bits/stdc++.h>
using namespace std;

bool um_(vector<int> &v, int b){
	for(int i = 0; i<b; i++){
		if(v[i] == 0) return false;
	} return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b; cin>>a>>b;
	// Depois de muitas horas, olhei o editorial.
	vector<int> entrada(a);
	for(int i = 0; i<a; i++){
		cin>>entrada[i];
		entrada[i]--;
	}

	int maior = 0;
	
	if(b*b <= a){
		vector<int> v(b, 0);
		map<vector<int>, int> m;
		m[v] = 0;
		for(int i = 0; i<a; i++){
			int c = entrada[i];
			v[c]++;
			if(um_(v, b)){
				for(int i = 0; i<b; i++){
					v[i]--;
				}
			}

			if(m.find(v) != m.end()){
				maior = max(maior, i-m[v]+1);
				//cout<<m[v]<<" - "<<i<<endl;
			} else m[v] = i+1;
		}
	} else {
		vector<int> v(b, 0);
		map<int, int> pos_num;
		pos_num[0] = b;
		
		
		int elements = 0;
		int j = 0;
		while(elements < b*(a/b)){
			int add = entrada[j];
			pos_num[v[add]]--;
			if(pos_num[v[add]] == 0) pos_num.erase(v[add]);
			v[add]++;
			pos_num[v[add]]++;
			elements++;
			j++;
		}
		bool left_right = true;
		for(int max_elements = b*(a/b); max_elements>=b; max_elements-=b){
			if(left_right){
				int pos = elements;
				while(elements > max_elements){
					int last = entrada[pos];
					pos_num[v[last]]--;
					if(pos_num[v[last]] == 0) pos_num.erase(v[last]);
					v[last]--;
					pos_num[v[last]]++;
					elements--;
					pos--;
				}
				left_right = !left_right;
				int front = 0;
				for(int j = pos; j<a; j++){
					int small = (*pos_num.begin()).first;
					int big = (*prev(pos_num.end())).first;
					if(small == big) {
						maior = small*b;
						goto finnaly;
					}
					int add = entrada[j];
					pos_num[v[add]]--;
					if(pos_num[v[add]] == 0) pos_num.erase(v[add]);
					v[add]++;
					pos_num[v[add]]++;
	
					int remove = entrada[front];
					pos_num[v[remove]]--;
					if(pos_num[v[remove]] == 0) pos_num.erase(v[remove]);
					v[remove]--;
					pos_num[v[remove]]++;
					front++;
				}
			} else {
				int pos = a-elements;
				while(elements > max_elements){
					int last = entrada[pos];
					pos_num[v[last]]--;
					if(pos_num[v[last]] == 0) pos_num.erase(v[last]);
					v[last]--;
					pos_num[v[last]]++;
					elements--;
					pos++;
				}
				left_right = !left_right;

				int back = a-1;
				for(int j = pos-1; j>=0; j--){
					int small = (*pos_num.begin()).first;
					int big = (*prev(pos_num.end())).first;
					if(small == big) {
						maior = small*b;
						goto finnaly;
					}
					int add = entrada[j];
					pos_num[v[add]]--;
					if(pos_num[v[add]] == 0) pos_num.erase(v[add]);
					v[add]++;
					pos_num[v[add]]++;
	
					int remove = entrada[back];
					pos_num[v[remove]]--;
					if(pos_num[v[remove]] == 0) pos_num.erase(v[remove]);
					v[remove]--;
					pos_num[v[remove]]++;
					back--;
				}
			}
			int small = (*pos_num.begin()).first;
			int big = (*prev(pos_num.end())).first;
			if(small == big) {
				maior = small*b;
				goto finnaly;
			}
		}
	}
	finnaly:
	cout<<maior<<endl;
}
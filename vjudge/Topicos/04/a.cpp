#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	int n; cin>>n;
	cin.ignore();

	for(int k = 0; k<n; ++k){
		string a;
		getline(cin, a);
		int size = a.size();
		int j = 0;
		int primeiro = 0, ultimo = 0;
		bool first = true;
		
		for(int i = 0; i<s.size(); ++i){
			if(s[i]==a[j]){
				if(first) primeiro = i;
				first = false;
				++j;
				if(j==size){
					ultimo = i;
					break;
				}
			}
		}

		if(j==a.size()) cout<<"Matched "<<primeiro<<" "<<ultimo<<endl;
		else cout<<"Not matched"<<endl;
	}
}
#include <bits/stdc++.h>
using namespace std;


int main(){
	int n; cin>>n;
	while(n--){
		string a, b; cin>>a>>b;
		if(a.size()>b.size()) swap(a, b);
		int i = 0;
		int counter = 0;
		if(a[i]==b[i]) counter++;
		while(a[i] == b[i]){
			counter++;
			i++;
			if(i>=a.size()) break;
		}
		counter+= a.size()-i;
		counter+= b.size()-i;
		cout << counter<<endl;
	}

}
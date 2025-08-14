#include <bits/stdc++.h>
using namespace std;


void constructLps(string &pat, vector<int> &lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();
    vector<int> lps(m);
    vector<int> res;
    constructLps(pat, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, q; cin>>n>>q;
	string s; cin>>s;



	map<string, int> mem;
	for(int i = 0; i<q; i++){	
		int a, b; cin>>a>>b;
		int m = b-a+1;
		string k = s.substr(a-1, m);
		if(mem.find(k) == mem.end()){
			int sum = 0;
			int inicio = 0, fim = 0;
			for(int e: search(k, s)){
				if(fim > e){
					fim = e + m;
				} else {
					sum += fim-inicio;
					inicio = e, fim = e+m;
				}
			}
			sum += fim-inicio;
			mem[k] = sum;
		}
		cout<<mem[k]<<endl;
	}


}
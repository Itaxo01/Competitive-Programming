#include <bits/stdc++.h>

using namespace std;
int a;
int m[152][152];

int kadane(int* arr, int* start, int* finish){
    int maxSum = INT_MIN, i;
	
	*finish = -1;

    int local_start = 0;
	for(int k = 0; k<(a/2); k++){
		int sum = 0;
		for (i = k; i < k+(a/2); ++i) {
			sum += arr[i];
			if (sum < 0) {
				sum = 0;
				local_start = i + 1;
			}
			else if (sum > maxSum) {
				maxSum = sum;
				*start = local_start;
				*finish = i;
			}
		}
	}

    if (*finish != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < a; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

void findMaxSum()
{
    int maior = INT_MIN;
    int temp[a], soma, start, finish;

    for (int l = 0; l < a; l++) {
        memset(temp, 0, sizeof(temp));
		for (int r = l; r < l+(a/2) && r < a; r++) {
            for (int i = 0; i < a; i++){
                temp[i] += m[i][r];
				// cout<<temp[i]<<" ";
				// cout<<m[i][r]<<" ";
			}
			// cout<<endl;
            soma = kadane(temp, &start, &finish);
			// cout<<start<<" "<<finish<<" "<<l<<" "<<r<<" "<<soma<<endl;
			maior = max(soma, maior);
        }
    }
	cout<<maior<<endl;
}

int main(){
	int n; cin>>n;
	while(n--){
		cin>>a;
		int M[a][a];
		for(int i = 0; i<a; i++){
			for(int j = 0; j<a; j++){
				cin>>M[i][j];
			}
		}
		a *=2;
		for(int i = 0; i<a; i++){
			memset(m[i], 0, a*sizeof(int));
			for(int j = 0; j<a; j++){
				m[i][j] = M[i%(a/2)][j%(a/2)];
			}
		}
		// for(int i = 0; i<a; i++){
		// 	for(int j = 0; j<a; j++){
		// 		cout<<m[i][j]<<" ";
		// 	}cout<<endl;
		// }
		findMaxSum();
		
	}
}
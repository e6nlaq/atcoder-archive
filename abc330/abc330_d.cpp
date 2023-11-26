#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;

	vector<string> S(N);
	for(int i = 0; i < N; ++i){
		cin >> S[i];
	}

	vector<int> A(N,0), B(N,0);
	for (int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(S[i][j] == 'o'){
				A[i]++;
				B[j]++;
			}
		}
	}

	int64_t ans = 0;
	for (int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j){
			if(S[i][j] == 'o'){
				ans += (A[i] - 1) * (B[j] - 1);
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, L, R;
	cin >> N >> L >> R;

	vector<int> X(N);
	for (int i = 0; i < N; ++i)
	{
		int A;
		cin >> A;

		if(L <= A && R >= A){
			X[i] = A;
		}else if(A<L){
			X[i] = L;
		}else{
			X[i] = R;
		}
	}

	for(int i = 0; i < N; ++i){
		cout << X[i] << (i != N - 1 ? " " : "\n");
	}

	return 0;
}

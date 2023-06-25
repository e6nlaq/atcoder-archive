#include<bits/stdc++.h>
using namespace std;

#define co(x) cout<<(x)<<endl
using ll = long long;
using vll = vector<ll>;

int main()
{


	ll N, K;
	cin >> N >> K;
	vll A(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	vll R(N + 11);
	for (int i = 1; i <= N - 1; i++)
	{
		if (i == 1)
			R[i] = 1;
		else
			R[i] = R[i - 1];

		while (R[i] < N && A[R[i] + 1] - A[i] <= K)
			R[i]++;
	}

	ll ans = 0;
	for (int i = 1; i <= N - 1; i++)
		ans += R[i] - i;

	co(ans);

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, D;
	cin >> N >> D;

	vector<long long> T(N);
	for (long long i = 0; i < N; i++)
		cin >> T[i];

	for (long long i = 0; i < N - 1; i++)
	{
		if (T[i + 1] - T[i] <= D)
		{
			cout << T[i + 1] << endl;
			exit(0);
		}
	}

	cout << -1 << endl;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;

	vector<long long> C(N), R(N);

	for (int i = 0; i < N; i++)
		cin >> C[i];
	for (int i = 0; i < N; i++)
		cin >> R[i];

	if (count(C.begin(), C.end(), T) == 0)
		T = C[0];

	pair<int, int> ans = make_pair(-1, -1);
	for (int i = 0; i < N; i++)
	{
		if (C[i] == T && R[i] > ans.second)
		{
			ans.first = i + 1;
			ans.second = R[i];
		}
	}

	cout << ans.first << endl;

	return 0;
}

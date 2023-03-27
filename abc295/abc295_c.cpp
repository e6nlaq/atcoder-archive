
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	map<long long, int> dat;
	long long ans = 0;

	for (int i = 0; i < N; i++)
	{
		long long A;
		cin >> A;

		dat[A]++;
		if (dat[A] == 2)
		{
			ans++;
			dat[A] = 0;
		}
	}

	cout << ans << endl;

	return 0;
}
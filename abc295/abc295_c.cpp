
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main()
{
	int N;
	cin >> N;
	unordered_map<int, int> dat;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;

		dat[A]++;
		if (dat[A] != 0 && dat[A] % 2 == 0)
		{
			ans++;
			dat[A] -= 2;
		}
	}

	cout << ans << endl;

	return 0;
}
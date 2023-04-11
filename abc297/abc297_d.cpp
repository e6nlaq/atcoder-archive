
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A, B, ans = 0;
	cin >> A >> B;

	while (A != B)
	{
		if (B > A)
			swap(A, B);

		ans += floorl(A / (B + 1));
		A -= B * floorl(A / (B + 1));
	}

	cout << ans << endl;

	return 0;
}
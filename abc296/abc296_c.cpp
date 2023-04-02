
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, X;
	set<long long> A;

	cin >> N >> X;
	for (long long i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		A.insert(tmp);
	}

	for (auto B : A)
	{
		if (A.count(X + B))
		{
			cout << "Yes" << endl;
			exit(0);
		}
	}

	cout << "No" << endl;

	return 0;
}
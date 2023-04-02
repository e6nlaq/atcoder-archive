
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string S;

	cin >> N >> S;

	for (int i = 0; i < N - 1; i++)
	{
		if (S[i] == S[i + 1])
		{
			cout << "No" << endl;
			exit(0);
		}
	}

	cout << "Yes" << endl;

	return 0;
}
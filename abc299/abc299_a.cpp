#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (S[i] == '|')
			flag = !flag;
		else if (S[i] == '*')
		{
			cout << (flag ? "in" : "out") << endl;
			return 0;
		}
	}

	return 0;
}

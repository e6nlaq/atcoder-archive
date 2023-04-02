
#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 0; i < 8; i++)
	{
		string S;
		cin >> S;

		for (int j = 0; j < 8; j++)
		{
			if (S[j] == '*')
			{
				cout << (char)('a' + j) << 8 - i << endl;
				exit(0);
			}
		}
	}

	return 0;
}
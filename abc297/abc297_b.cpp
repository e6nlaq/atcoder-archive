
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int pos1 = S.find('B');
	int pos2 = S.rfind('B');

	pos1 %= 2;
	pos2 %= 2;

	if (pos1 == pos2)
	{
		cout << "No" << endl;
		return 0;
	}

	bool check = false;
	for (int i = 0; i < 8; i++)
	{
		if (S[i] == 'R')
		{
			check ^= 1;
		}

		if (S[i] == 'K' && !check)
		{

			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}
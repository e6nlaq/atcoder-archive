
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;

	while (H--)
	{
		string S;
		cin >> S;

		while (S.find("TT") != string::npos)
		{
			S.replace(S.find("TT"), 2, "PC");
		}
		cout << S << endl;
	}

	return 0;
}
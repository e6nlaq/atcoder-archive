
#include <bits/stdc++.h>
using namespace std;

int manhat(int r1, int r2, int c1, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}

int ctoi(char c)
{
	return c - '0';
}

int main()
{
	int R, C;
	cin >> R >> C;

	vector<vector<char>> B(R, vector<char>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (isdigit(B[i][j]))
			{
				for (int k = 0; k < R; k++)
				{
					for (int l = 0; l < C; l++)
					{
						if (B[k][l] == '#' && manhat(i + 1, k + 1, j + 1, l + 1) <= ctoi(B[i][j]))
						{
							B[k][l] = '.';
						}
					}
				}
				B[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << B[i][j];
		}
		cout << endl;
	}

	return 0;
}
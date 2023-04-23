#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rot90(vector<vector<int>> arr)
{
	int x = arr[0].size();
	int y = arr.size();

	vector<vector<int>> ret(x, vector<int>(y));
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			ret[j][i] = arr[i][j];
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x / 2; j++)
		{
			int temp = ret[i][j];
			ret[i][j] = ret[i][x - j - 1];
			ret[i][x - j - 1] = temp;
		}
	}

	return ret;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int _ = 0; _ < 4; _++)
	{
		A = rot90(A);
		bool ok = true;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (A[i][j] == 1 & B[i][j] == 0)
				{
					ok = false;
				}
			}
		}

		if (ok)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}
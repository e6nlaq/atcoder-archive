
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	const set<string> words = {"and", "not", "that", "the", "you"};

	for (int i = 0; i < N; i++)
	{
		string W;
		cin >> W;

		if (words.count(W))
		{
			cout << "Yes" << endl;
			exit(0);
		}
	}

	cout << "No" << endl;

	return 0;
}
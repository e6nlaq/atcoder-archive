#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;

	map<int, multiset<int>> box;
	map<int, set<int>> card;

	while (Q--)
	{
		int query;
		cin >> query;

		if (query == 1)
		{
			int i, j;
			cin >> i >> j;

			card[i].insert(j);
			box[j].insert(i);
		}
		else if (query == 2)
		{
			int i;
			cin >> i;

			for (auto x : box[i])
			{
				cout << x << " ";
			}
			cout << endl;
		}
		else
		{

			int i;
			cin >> i;

			for (auto x : card[i])
			{
				cout << x << " ";
			}
			cout << endl;
		}
	}

	return 0;
}

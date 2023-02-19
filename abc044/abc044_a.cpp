#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
	int N, K, X, Y,money = 0;

	cin >> N >> K >> X >> Y;

	rep(i, N + 1) {
		if (i <= K) money += X;
		else money += Y;
	}

	cout << money << endl;

	return 0;

}
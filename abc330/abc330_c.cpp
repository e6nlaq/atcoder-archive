#include<bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T &a, T b){
	if(a > b){
		a = b;
	}
}

int64_t solve(int64_t a, int64_t b){
	if(a>b)
		return a - b;
	else
		return b - a;
}

int main(){
	int64_t D;
	cin >> D;

	int64_t ans = INT64_MAX;
	for (int64_t i = 0; i * i <= D;++i){
		auto tmp = floor(sqrt(D - i * i));

		chmin(ans, solve(D, i * i + tmp * tmp));
		chmin(ans, solve(D, i * i + (tmp + 1) * (tmp + 1)));
	}

	cout << ans << endl;

	return 0;
}

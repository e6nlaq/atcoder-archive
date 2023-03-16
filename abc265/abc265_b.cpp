#include <bits/stdc++.h>
#include <iomanip>
#include <time.h>
#include <ctime>
using namespace std;

/**
 *	Author : x__0
 *	Create : 2022-08-21 21:13:19
 *	Charset : UTF-8 with BOM (Code page 65001)
 *	IDE : Microsoft Visual Studio Code	Version 1.70.2
 *	This source code is available under the CC0 license.
**/

#pragma region AtCoder Template

// 型省略
using uint = unsigned;
using ll = long long;
using li = long int;
using ull = unsigned long long;
using str = string;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vc = vector<char>;
using vs = vector<string>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vpii = vector<pii>;
using vpsi = vector<psi>;
using mapci = map<char,int>;
using mapsi = map<string,int>;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define intrep(i, n) for(int i = 1; i < (int)(n) + 1;i++)
#define arep(i, a, n) for(int i = (a);i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define endl "\n"
#define bre break
#define is ==
#define el else
#define elif else if
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define Yaybad(bool) if(bool){cout<<"Yay!"<<endl;}else{cout<<":("<<endl;}
#define GoodBad(bool) if(bool){cout<<"Good"<<endl;}else{cout<<"Bad"<<endl;}
#define pb push_back
#define mp make_pair
#define debug(x) cout << "Debug:" << x << endl;
#define fix(x) cout << fixed << setprecision(x);
#define fastio cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
#define sorv(x) sort(all((x)));reverse(all((x)));
#define tos(s) to_string(s);

// 定数
const string STRNUL = "";
const char CHARNUL = (char)0;
const int INFINT = 2e9;
const ll INFLL = 2e18;
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

// 素数チェック
bool isprime(int x) {
	if (x < 2) return false;

	if (x % 2 != 0 && x % 3 != 0 && x % 5 != 0 && x % 7 != 0) return true;
	return false;
}

// 偶数チェック
bool iseven(int x) {
	if (x % 2 == 0) return true;
	return false;
}

// 奇数チェック
bool isodd(int x) {
	if (x % 2 != 0) return true;
	return false;
}

// char -> int変換
int ctoi(char c) {
	if (isdigit(c)) return c - '0';
	return 0;
}

// char -> longlong変換
ll ctoll(char c){
	if(isdigit(c)) return c - '0';
	return 0;
}

// 1 + 2 + 3 + 4 + ... x
int minisum(int x) {
	int ans = 0;
	for (int i = 1;i <= x;i++) {
		ans += i;
	}
	return ans;
}

// i * 高さ / 2
double hei2(int i,int height){
	return i * height / 2;
}

// 商のみ割り算
int div(double d , double i){
	return floor(d / i);
}

void flip(bool &b){
	b = !b;
}

////////////////////
// 以下プログラム記述 //
///////////////////

#pragma endregion

int main(){
	fastio;

	long long N,M,T,bon = 0;
	cin >> N >> M >> T;
	vll A(N),X(M + 1),Y(M + 1);
	bool ok = true;

	rep(i, N - 1){
		cin >> A[i];
	}
	rep(i, M){
		cin >> X[i] >> Y[i];
	}

	rep(i, N){
		if(X[bon] - 1 is i){
			T += Y[bon];
			bon++;
		}
		T -= A[i];
		if(T <= 0){
			ok = false;
			break;
		}
		
	}

	YesNo(ok);

	return 0;

}
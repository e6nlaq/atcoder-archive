
/*---------------------------------------------------



	   Welcome to my template!

	　　∧＿∧        @x__0
	　 ( 　･ω･)      ver5.1.1
	＿(__つ/￣￣￣ /  CC BY 4.0
	　　＼/　　　　 /  C++ GCC 9.2.0
	　　　　￣￣￣￣￣
		   Let's write Code!


---------------------------------------------------*/

// 更新履歴
//
// 5.0.0
// 更新履歴をすべて削除
// 更新履歴を日本語化
// 新カテゴリ「高速化」を追加 (提供:https://zenn.dev/antyuntyun)
// 関数 printを追加
// すべての関数をinline化
// ほとんどの引数を定数化
// ctoll関数及びaverl関数が5.1.0で廃止予定になりました
// 型エイリアスllがlong longから__int128_tに変更になりました
// ullも上記のとおりです
// ファイルの先頭が変わりました
//
// 5.0.1
// ullのバグにより元に戻しました。
//
// 5.0.2
// タイトルのインシデントを減らしました。
// 構造体Weekを追加しました。
//
// 5.0.3
// 定数PIをacos(-1)に変更しました。
//
// 5.0.4
// llをlonglongに変更しました。
//
// 5.0.5
// 互換性関数lcm及びgcdを追加
//
// 5.0.6
// 5.0.5で追加された関数をすべて削除
//
// 5.0.7
// repマクロを一部変更
//
// 5.0.8
// 型エイリアスmii,mllを追加
//
// 5.0.9
// 関数vcinを追加
//
// 5.0.10
// 関数minisumを変更
//
// 5.1.0
// double関係の型を追加
// srev関数を追加
// マクロdebugを関数に変更
// 不要になった関数を削除
//
// 5.1.1
// グローバル変数を追加

#pragma region AtCoder Template

// #include <atcoder/scc>
// #ifdef _LOCAL__
// #include "./include/bits/stdc++.h"
// #else
#include <bits/stdc++.h>
// #endif
using namespace std;
// using namespace atcoder;

// 高速化
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define fastio                         \
	cin.tie(nullptr);                  \
	cout.tie(nullptr);                 \
	ios::sync_with_stdio(false);       \
	cout << fixed << setprecision(15); \
	srand((unsigned)time(NULL));

// 型省略
#define var auto
using uint = unsigned;
using ll = long long;
// using ll = __int128_t;
using ull = unsigned long long;
using li = long int;
using ld = long double;
using str = string;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vd = vector<ld>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using psi = pair<string, int>;
using psl = pair<string, ll>;
using pci = pair<char, int>;
using pcl = pair<char, ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpsi = vector<psi>;
using vpci = vector<pci>;
using vvd = vector<vd>;
using mci = map<char, int>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using mcl = map<char, ll>;
using msi = map<string, int>;
using msl = map<string, ll>;
using msvi = map<string, vi>;
using sll = set<ll>;
using stll = stack<ll>;
using qll = queue<ll>;
using qi = queue<int>;
using qd = queue<ld>;
using qs = queue<string>;
using qc = queue<char>;

// マクロ
#define rep(i, n) for (ull i = 0; i < (ull)(n); i++)
#define rrep(i, n) for (ull i = (n); i = 0; i--)
#define irep(i, n) for (ll i = 1; i < (ll)(n) + 1; i++)
#define arep(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define adrep(i, a, d, n) for (ll i = (a); i < (ll)(n); i += d)
#define rwhile(b) while (!(b))

// 省略define
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define endl "\n"
#define br break
#define is ==
#define el else
#define elif else if
#define YESNO(bool)            \
	if (bool)                  \
	{                          \
		cout << "YES" << endl; \
	}                          \
	else                       \
	{                          \
		cout << "NO" << endl;  \
	}
#define yesno(bool)            \
	if (bool)                  \
	{                          \
		cout << "yes" << endl; \
	}                          \
	else                       \
	{                          \
		cout << "no" << endl;  \
	}
#define YesNo(bool)            \
	if (bool)                  \
	{                          \
		cout << "Yes" << endl; \
	}                          \
	else                       \
	{                          \
		cout << "No" << endl;  \
	}
#define Yaybad(bool)            \
	if (bool)                   \
	{                           \
		cout << "Yay!" << endl; \
	}                           \
	else                        \
	{                           \
		cout << ":(" << endl;   \
	}
#define GoodBd(bool)            \
	if (bool)                   \
	{                           \
		cout << "Good" << endl; \
	}                           \
	else                        \
	{                           \
		cout << "Bad" << endl;  \
	}
#define ACWA(bool)            \
	if (bool)                 \
	{                         \
		cout << "AC" << endl; \
	}                         \
	else                      \
	{                         \
		cout << "WA" << endl; \
	}
#define pb push_back
#define mp make_pair
#define tos to_string
#define sz size()
#define exit return 0
#define co(x) cout << (x) << endl

// 定数
const string sl = "";
const char cl = '\0';
const ll nl = 0LL;
const int INFINT = 2147483647;
const ll INFLL = 9223372036854775807;
const long double PI = acos(-1);
const ll mod1 = pow(10, 9) + 1;
const char sp = ' ';
const ll j2_32 = pow(2, 32);
const ll j2_m32 = pow(2, -32);
const ll j2_10 = pow(2, 10);

// 構造体

// 曜日の構造体です。日曜日が0となります
enum Week
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

// 関数類

/**
 * @brief 素数をチェックします
 *
 * @param num 判定する数値
 * @return bool 素数かどうか
 */
inline bool isprime(const int num)
{
	if (num < 2)
		return false;
	else if (num == 2)
		return true;
	else if (num % 2 == 0)
		return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

/**
 * @brief 偶数かどうかチェックします(2,4...)
 *
 * @param x 判定する数値です
 * @return bool 偶数かどうか
 */
inline bool iseven(const int x)
{
	if (x % 2 == 0)
		return true;
	return false;
}

/**
 * @brief 奇数かどうかをチェックします(1,3...)
 *
 * @param x 判定する数値です
 * @return bool 奇数かどうか
 */
inline bool isodd(const int x)
{
	if (x % 2 != 0)
		return true;
	return false;
}

/**
 * @brief char型の数値をint型に変換します
 *
 * @param c 変換する文字
 * @return int 変換した数値
 */
inline int ctoi(const char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	return 0;
}

/**
 * @brief 1+2+3+4+...n
 *
 * @param n
 * @return int
 */
inline int minisum(const int n)
{
	return n * (n + 1) / 2;
}

/**
 * @brief bool型変数の値を反転します。
 *
 * @param b 反転する変数
 */
inline void flip(bool &b)
{
	b = !b;
}

/**
 * @brief 平均を求めます。
 *
 * @tparam T 返り値の型
 * @param arg 入力がいくつあるか
 * @param arg1 入力1
 * @param arg2 入力2
 * @param arg3 入力3
 * @param arg4 入力4
 * @param arg5 入力5
 * @param arg6 入力6
 * @param arg7 入力7
 * @param arg8 入力8
 * @param arg9 入力9
 * @param arg10 入力10
 * @return double 平均
 */
template <typename T>
inline T aver(int arg, int arg1, int arg2, int arg3 = 0, int arg4 = 0, int arg5 = 0, int arg6 = 0, int arg7 = 0, int arg8 = 0, int arg9 = 0, int arg10 = 0)
{
	return (arg1 + arg2 + arg3 + arg4 + arg5 + arg6 + arg7 + arg8 + arg9 + arg10) / arg;
}

/**
 * @brief 数値を桁数で0埋めします
 *
 * @tparam T 桁数の型
 * @param i 桁数
 * @param s 埋める文字列
 * @return string 0埋め後の文字列
 */
template <typename T>
inline string zerou(const T i, string s)
{
	while (s.size() != i)
		s = '0' + s;
	return s;
}

/**
 * @brief T型をchar型に変換します
 *
 * @tparam T 変換する型
 * @param i 変換する数値
 * @return char 変換後の文字
 */
template <typename T>
inline char to_char(const T i)
{
	return '0' + i;
}

/**
 * @brief i < j の場合iをjで置き換えます
 *
 * @tparam T1_ iの型
 * @tparam T2_ jの型
 * @param i 上書きする変数
 * @param j 比較する変数
 * @return bool 置き換えたかどうか
 */
template <typename T1_, typename T2_>
inline bool chmax(T1_ &i, const T2_ j)
{
	if (i < j)
	{
		i = j;
		return true;
	}
	return false;
}

/**
 * @brief i > j の場合iをjで置き換えます
 *
 * @tparam T1_ iの型
 * @tparam T2_ jの型
 * @param i 上書きする変数
 * @param j 比較する変数
 * @return bool 置き換えたかどうか
 */
template <typename T1_, typename T2_>
inline bool chmin(T1_ &i, const T2_ j)
{
	if (i > j)
	{
		i = j;
		return true;
	}
	return false;
}

/**
 * @brief 10進数の数字を2進数の文字に変更します
 *
 * @param n 変換する文字
 * @return string 2進数に変換した文字。
 * @author https://onl.bz/WdFt4ei
 */
inline string tobinary(int n)
{
	string r;
	while (n != 0)
	{
		r += (n % 2 == 0 ? "0" : "1");
		n /= 2;
	}
	return r;
}

/**
 * @brief 配列内の全要素を出力します
 *
 * @tparam T 配列の型(vector<T>)
 * @param v 配列
 * @param s 区切り文字(規定ではスペース)
 * @author https://zenn.dev/antyuntyun
 */
template <typename T>
inline void print(const vector<T> &v, string s = " ")
{
	rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}

/**
 * @brief 配列を入力します
 *
 * @tparam Tp1 配列の型
 * @param v 入力する配列
 */
template <typename Tp1>
inline void vcin(vector<Tp1> &v)
{
	rep(i, v.size()) cin >> v[i];
}

/**
 * @brief 文字列を反転した文字列を返します
 *
 * @param s 反転する文字列
 * @return string 反転後の文字列
 */
inline string srev(string s)
{
	reverse(all(s));
	return s;
}

/**
 * @brief コードのデバッグ出力用関数です
 *
 * @tparam arg1 変数の型
 * @param x 出力する変数
 */
template <typename arg1>
inline void debug(arg1 x)
{
#ifdef _LOCAL_
	cout << "\033[32mDebug\033[m: " << x << endl;
#else
	cerr << "Debug: " << x << endl;
#endif
}

#pragma endregion

/* Variables */
ll N;
ll ans = 0;
// bool ans = true;
// string ans = "";

/* Main Function */

int main(int argc, char const *argv[])
{
	fastio;

	int a, b, c;
	string s;

	cin >> a >> b >> c >> s;

	cout << a + b + c << sp << s << endl;

	return 0;
}

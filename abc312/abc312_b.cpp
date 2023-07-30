/*------------------------------------------------------------



	   Welcome to my program!

	　　∧＿∧        AtCoder / Codeforces
	　 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	　　＼/　　　　 /  C++ GCC 11.3.0 + Boost 1.82.0
	　　　　￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/

// Return Code 139(out_of_range)が出たら試す
// #define _GLIBCXX_DEBUG

// Boost系
// #include <boost/multiprecision/cpp_int.hpp>			 // クソでか整数
// #include <boost/multiprecision/cpp_dec_float.hpp>	 // クソでか小数
// #include <boost/math/constants/constants.hpp>		 // ウルトラ円周率
// #include <boost/date_time/gregorian/gregorian.hpp>	 // 申し訳程度の日付演算

// #include <boost/algorithm/string/split.hpp>			 // 文字列をcharで分割(split)
// #include <boost/algorithm/string/classification.hpp> // 上の文字指定に必要
// #include <boost/algorithm/string/iter_find.hpp>		 // 文字列をstringで分割(iter_split)
// #include <boost/algorithm/string/finder.hpp>		 // 上の文字列指定に必要

// #include <boost/algorithm/string/join.hpp>			 // 他の言語のjoinを実装するやつ
// #include <boost/algorithm/string/replace.hpp>		 // 全部置き換え

// #include <boost/dynamic_bitset.hpp>					 // サイズ変更可bitset
// #include <boost/range/algorithm/for_each.hpp>		 // 関数でforeach文

// #include <boost/assert.hpp> // 上位デバッグ

// Boost名前空間省略
// namespace mu = boost::multiprecision;
// namespace ag = boost::algorithm;

// AtCoder Library
/*
#include <atcoder/all>
using namespace atcoder;
/* */

#pragma region AtCoder Template

#include <bits/stdc++.h>
using namespace std;

// ローカル環境チェック
#if __has_include("./lib/debug_print.hpp")
#include "./lib/debug_print.hpp"
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#define _LOCAL_ 1
#else
#define debug(...) (static_cast<void>(0))
#endif

// 高速化
#pragma GCC target("avx,avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define fastio                         \
	cin.tie(nullptr);                  \
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
using vd = vector<double>;
using vld = vector<ld>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using psi = pair<string, int>;
using psl = pair<string, ll>;
using pci = pair<char, int>;
using pcl = pair<char, ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvb = vector<vb>;
using vvld = vector<vld>;
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
using spll = set<pair<ll, ll>>;
using spdd = set<pair<ld, ld>>;
using stll = stack<ll>;
using qll = queue<ll>;
using qi = queue<int>;
using qd = queue<ld>;
using qs = queue<string>;
using qc = queue<char>;

template <typename Tp1, typename Tp2>
using unmap = unordered_map<Tp1, Tp2>;

template <typename Tp>
using unset = unordered_set<Tp>;

template <typename Tp>
using reverse_queue = priority_queue<Tp, vector<Tp>, greater<Tp>>;

// マクロ
#define rep(i, n) for (ull i = 0; i < (ull)(n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)
#define irep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define arep(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define adrep(i, a, d, n) for (ll i = (a); i < (ll)(n); i += d)
#define until(b) while (!(b)) // なにがrwhileだ!untilだぞ!

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
#define exit exit(0)
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
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

// 色々なテンプレ(完全コピペ)

template <class T>
size_t HashCombine(const size_t seed, const T &v)
{
	return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}
/* pair用 */
template <class T, class S>
struct std::hash<std::pair<T, S>>
{
	size_t operator()(const std::pair<T, S> &keyval) const noexcept
	{
		return HashCombine(std::hash<T>()(keyval.first), keyval.second);
	}
};
/* vector用 */
template <class T>
struct std::hash<std::vector<T>>
{
	size_t operator()(const std::vector<T> &keyval) const noexcept
	{
		size_t s = 0;
		for (auto &&v : keyval)
			s = HashCombine(s, v);
		return s;
	}
};
/* tuple用 */
template <int N>
struct HashTupleCore
{
	template <class Tuple>
	size_t operator()(const Tuple &keyval) const noexcept
	{
		size_t s = HashTupleCore<N - 1>()(keyval);
		return HashCombine(s, std::get<N - 1>(keyval));
	}
};
template <>
struct HashTupleCore<0>
{
	template <class Tuple>
	size_t operator()(const Tuple &keyval) const noexcept { return 0; }
};
template <class... Args>
struct std::hash<std::tuple<Args...>>
{
	size_t operator()(const tuple<Args...> &keyval) const noexcept
	{
		return HashTupleCore<tuple_size<tuple<Args...>>::value>()(keyval);
	}
};

std::string
operator""_s(char const *str, std::size_t)
{
	return str;
}

std::string
operator*(std::string const &str, int n)
{
	if (n < 1)
		return "";
	std::string result;
	result.reserve(str.length() * n);
	for (int i = 0; i < n; ++i)
	{
		result += str;
	}
	return result;
}

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

/// @brief 二次元配列の全要素を出力します
/// @tparam T 配列の型(vector<vector<T>>)
/// @param v 二次元配列
/// @param s 区切り文字
template <typename T>
inline void print(const vector<vector<T>> &v, string s = " ")
{
	rep(i, v.size())
	{
		rep(j, v[i].size()) cout << v[i][j] << (j != (ll)v[i].size() - 1 ? s : "\n");
	}
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

/// @brief 二つの配列を入力します。
/// @tparam Tp1 1つめの配列の型
/// @tparam Tp2 2つめの配列の型
/// @param v 1つめの配列
/// @param b 2つめの配列
/// @throw v.size()!=b.size()の場合に投げられます。
template <typename Tp1, typename Tp2>
inline void vcin(vector<Tp1> &v, vector<Tp2> &b)
{
	assert(v.size() == b.size());
	rep(i, v.size()) cin >> v[i] >> b[i];
}

/// @brief 二次元配列を入力します。
/// @tparam Tp1 vector<vector<Tp1>>の型
/// @param v 二次元配列
template <typename Tp1>
inline void vcin(vector<vector<Tp1>> &v)
{
	rep(i, v.size())
	{
		rep(j, v[i].size())
		{
			cin >> v[i][j];
		}
	}
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

/// @brief long longでべき乗します
/// @param x x^nのx
/// @param n x^nのn
/// @return x^n
inline long long pow_ll(long long x, long long n)
{
	long long ret = x;
	if (n == 0)
		return 1;
	for (long long i = 1; i < n; i++)
	{
		ret *= x;
	}
	return ret;
}

/// @brief N進数の文字から10進数の数値に変換します
/// @param c N進数の文字
/// @return 変換した10進数の数値
inline int ntodec(const char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	case 'G':
		return 16;
	case 'H':
		return 17;
	case 'I':
		return 18;
	case 'J':
		return 19;
	case 'K':
		return 20;
	case 'L':
		return 21;
	case 'M':
		return 22;
	case 'N':
		return 23;
	case 'O':
		return 24;
	case 'P':
		return 25;
	case 'Q':
		return 26;
	case 'R':
		return 27;
	case 'S':
		return 28;
	case 'T':
		return 29;
	case 'U':
		return 30;
	case 'V':
		return 31;
	case 'W':
		return 32;
	case 'X':
		return 33;
	case 'Y':
		return 34;
	case 'Z':
		return 35;
	default:
		return -1;
	}
}

/// @brief 10進数の数値をN進数の文字に変換します
/// @param n 10進数の数値
/// @return N進数の文字
inline char decton(const int n)
{
	switch (n)
	{
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	case 16:
		return 'G';
	case 17:
		return 'H';
	case 18:
		return 'I';
	case 19:
		return 'J';
	case 20:
		return 'K';
	case 21:
		return 'L';
	case 22:
		return 'M';
	case 23:
		return 'N';
	case 24:
		return 'O';
	case 25:
		return 'P';
	case 26:
		return 'Q';
	case 27:
		return 'R';
	case 28:
		return 'S';
	case 29:
		return 'T';
	case 30:
		return 'U';
	case 31:
		return 'V';
	case 32:
		return 'W';
	case 33:
		return 'X';
	case 34:
		return 'W';
	case 35:
		return 'Z';
	default:
		return '\0';
	}
}

/// @brief N進数の文字列をM進数に直して出力します。
/// @param str N進数の文字
/// @param n 文字の進数
/// @param m 出力の進数
/// @return M進数の文字
inline string n_ary(string str, int n, int m)
{
	unsigned long tmp = 0;
	string ret;

	for (int i = 0; i < str.length(); i++)
	{
		tmp += (unsigned long)ntodec(str[str.length() - 1 - i]) * pow_ll(n, i);
	}

	if (tmp == 0)
		return "0";
	while (tmp != 0)
	{
		ret = decton(tmp % m) + ret;
		tmp /= m;
	}
	return ret;
}

/// @brief nを素因数分解します
/// @tparam T nの型
/// @param n 素因数分解する数
/// @return 不明
template <typename T>
inline map<T, T> prime_factor(T n)
{
	map<T, T> ret;
	for (T i = 2; i * i <= n; i++)
	{
		T tmp = 0;
		while (n % i == 0)
		{
			tmp++;
			n /= i;
		}
		ret[i] = tmp;
	}
	if (n != 1)
		ret[n] = 1;
	return ret;
}

/// @brief Nの約数の数を求めます
/// @tparam T Nの型
/// @param N 約数の数を求める数
/// @return Nの約数の数
template <typename T>
inline T divisor_num(T N)
{
	map<T, T> pf = prime_factor(N);
	T ret = 1;
	for (auto p : pf)
	{
		ret *= (p.second + 1);
	}
	return ret;
}

/// @brief nの約数を全列挙します。(計算量: O(sqrt(N)))
/// @param n 全列挙する約数
/// @return nの約数
inline vll divisor(ll n)
{
	vll ret;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ret.push_back(i);
			if (i * i != n)
				ret.push_back(n / i);
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

/// @brief 文字列が数字のみか判定します O(|S|)
/// @param s 判定する文字列
/// @return 数値でできた文字列かどうか
inline bool isint(string s)
{
	rep(i, s.size())
	{
		if (!isdigit(s[i]))
		{
			return false;
		}
	}

	return true;
}

/// @brief 二次元配列を90度時計回りに回転する
/// @tparam T 配列の型(vector<vector<T>>)
/// @param arr 二次元配列
/// @return 返り値
template <typename T>
inline vector<vector<T>> rot90(vector<vector<T>> A)
{
	ll N = A.size(), M = A[0].size();
	vector<vector<T>> ret(M, vector<T>(N));

	ll _i = 0, _j = 0;

	rep(j, M)
	{
		for (ll i = N - 1; i >= 0; i--)
		{
			ret[_i][_j] = A[i][j];
			_j++;
		}
		_j = 0;
		_i++;
	}

	return ret;
}

/// @brief 回文かどうか判定
/// @param str 文字列
/// @return 回文かどうか
inline bool ispalind(const string str)
{
	int n = str.length();
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - i - 1])
		{
			return false;
		}
	}
	return true;
}

/// @brief startからnまでの順列を生成
/// @param n 最大値
/// @param start 開始値
/// @return startからnまでの順列
inline vector<ll> range(ll n, ll start = 0)
{
	vector<ll> ret(n - start);
	ll oi = 0;
	for (ll i = start; i <= n; i++)
	{
		ret[oi] = i;
		oi++;
	}

	return ret;
}

/// @brief 10進法で表した時の各桁の和を求めます
/// @param s 10進法で表した文字列
/// @return 各桁の和
inline ll csum(string s)
{
	ll ret = 0;
	rep(i, s.size())
	{
		ret += ctoi(s[i]);
	}

	return ret;
}

/// @brief csumの数値用の補完関数
/// @param n 数値
/// @return 各桁の和
inline ll csum(ll n)
{
	return csum(to_string(n));
}

/// @brief 階乗を計算する
/// @param n nの階乗
/// @return nの階乗
inline ll fact(ll n)
{
	ll ret = 1;
	rep(i, n)
	{
		ret *= i + 1;
	}
	return ret;
}

/// @brief 平方数かどうかを判定
/// @param N 判定する数
/// @return 平方数かどうか
inline bool is_squere(long long N)
{
	long long r = (long long)floor(sqrt((long double)N)); // 切り捨てした平方根
	return (r * r) == N;
}

/// @brief 一次元の累積和を返します
/// @tparam T vectorの型
/// @param v 加工する前の配列
/// @return 加工後の配列(長さは |v|+1 となります。)
template <typename T>
inline vector<T> cumulative(vector<T> v)
{
	vector<T> cum(v.size() + 1);
	cum[0] = 0;
	for (int i = 1; i <= v.size(); i++)
	{
		cum[i] = cum[i - 1] + v[i - 1];
	}
	return cum;
}

/// @brief 二次元の累積和を返します
/// @tparam T vector<vector<>>の型
/// @param v 加工前の配列
/// @return 加工後の配列(長さはそれぞれ+1になります)
template <typename T>
inline vector<vector<T>> cumulative(vector<vector<T>> v)
{
	assert(v.size() > 0);
	ll H = v.size(), W = v[0].size();
	vector<vector<T>> ret(H + 1, vector<T>(W + 1, 0));
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			ret[i][j] = ret[i][j - 1] + v[i - 1][j - 1];
		}
	}

	for (int j = 1; j <= W; j++)
	{
		for (int i = 1; i <= H; i++)
		{
			ret[i][j] += ret[i - 1][j];
		}
	}

	return ret;
}

/// @brief ランダムな数値を返す
/// @param l 最小値
/// @param r 最大値
/// @return
inline ll random(ll l, ll r)
{
	return l + (rand() % (r - l));
}

/// @brief 高速全探索 O(N log N)
/// @tparam _Tp 配列の型
/// @param v 配列
/// @param x 探索するやつ
/// @return 数
template <typename _Tp>
inline long long count(std::vector<_Tp> v, _Tp x)
{
	std::sort(v.begin(), v.end());

	auto l = std::lower_bound(v.begin(), v.end(), x);
	auto u = std::upper_bound(v.begin(), v.end(), x);

	if (*l != x)
	{
		return 0;
	}

	if (u == v.end())
	{
		return v.size() - (l - v.begin());
	}
	else
	{
		return (u - v.begin()) - (l - v.begin());
	}
}

#pragma endregion

/* Variables */
ll N, M, Q;
ll H, W;
string dump = "";
ll t = -1;

/* Main Function */

bool check(vs s)
{
	// debug("Hello");
	rep(i, 3) if (s[i].substr(0, 4) != "###.") return false;

	for (int i = 6; i < s.size(); i++)
	{
		if (s[i].substr(5) != ".###")
			return false;
	}

	if (s[3].substr(0, 4) != "...." || s[5].substr(5) != "....")
		return false;

	return true;
}

int main()
{
	fastio;

	cin >> N >> M;

	vector<string> S(N);
	vcin(S);

	vector<pair<ll, ll>> ans;

	rep(i, N - 8)
	{
		rep(j, M - 8)
		{
			debug(i, j);
			vector<string> chk(9);
			for (int k = 0; k < 9; k++)
			{
				// debug(S[k + i]);
				chk[k] = S.at(k + i).substr(j, 9);
			}

			if (check(chk))
			{
				ans.emplace_back(make_pair(i + 1, j + 1));
			}
		}
	}

	sort(all(ans));

	rep(i, ans.size())
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}

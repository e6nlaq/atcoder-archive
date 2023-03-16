
/*---------------------------------------------------



	   Welcome to my template!

	　　∧＿∧        @x__0
	　 ( 　･ω･)      ver 5.2.6
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
//
// 5.1.2
// 関数 atfindを追加
//
// 5.2.0
// AC Libraryに対応
//
// 5.2.1
// https://qiita.com/Shiro-san/items/9376c8898a0882482a6a
// より関数を拝借
//
// 5.2.2
// 緊急処理
//
// 5.2.3
// 素因数分解・Nの約数の数を求める関数の追加
//
// 5.2.4
// 名前とか変えた
//
// 5.2.5
// 型追加
//
// 5.2.6
// 関数isint,v2cin追加

#pragma region AtCoder Template

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

// マクロ
#define rep(i, n) for (ull i = 0; i < (ull)(n); i++)
#define rrep(i, n) for (ull i = (n); i = 0; i--)
#define irep(i, n) for (ll i = 1; i < (ll)(n) + 1; i++)
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
inline void vprint(const vector<T> &v, string s = " ")
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

/// @brief 配列の要素を検索します
/// @tparam arg1 配列の型
/// @tparam arg2 要素の型
/// @param v 配列
/// @param a 要素
/// @return 配列内の要素の添字
template <typename arg1, typename arg2>
inline ll atfind(arg1 v, arg2 a)
{
	auto it = find(all(v), a);

	if (it != v.end())
		return it - v.begin();
	else
		return -1;
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

/// @brief 2つの配列(vector)に入力します
/// @tparam T1 1つめの配列の型
/// @tparam T2 2つめの配列の型
/// @param v1 1つめの配列
/// @param v2 2つめの配列
template <typename T1, typename T2>
inline void v2cin(vector<T1> &v1, vector<T2> &v2)
{
	assert(v1.size() == v2.size());

	rep(i, v1.size())
	{
		cin >> v1[i] >> v2[i];
	}
}

/* last update: 2022-08-03 */

#ifndef DEBUG_PRINT_HPP
#define DEBUG_PRINT_HPP

#define INCLUDED(n) ((defined _GLIBCXX_##n) || (defined _LIBCPP_##n))

#if __cplusplus < 201703L
#warning Please use C++17 (or later version).
#endif
#if !INCLUDED(ALGORITHM)
#warning Please include <algorithm> before including debug_print.hpp.
#endif
#if !INCLUDED(CCTYPE)
#warning Please include <cctype> before including debug_print.hpp.
#endif
#if !INCLUDED(IOSTREAM)
#warning Please include <iostream> before including debug_print.hpp.
#endif
#if !INCLUDED(ITERATOR)
#warning Please include <iterator> before including debug_print.hpp.
#endif
#if !INCLUDED(STRING_VIEW)
#warning Please include <string_view> before including debug_print.hpp.
#endif
#if !INCLUDED(TYPE_TRAITS)
#warning Please include <type_traits> before including debug_print.hpp.
#endif

namespace debug_print
{
	std::ostream &os = std::cerr;

	template <class Tp>
	auto has_cbegin(int) -> decltype(std::cbegin(std::declval<Tp>()), std::true_type{});
	template <class Tp>
	auto has_cbegin(...) -> std::false_type;
	template <class Tp>
	auto has_value_type(int) -> decltype(std::declval<typename Tp::value_type>(), std::true_type{});
	template <class Tp>
	auto has_value_type(...) -> std::false_type;

	template <class Tp>
	[[maybe_unused]] constexpr bool is_iterable_container_v = decltype(has_cbegin<Tp>(int{}))::value;
	template <class Tp>
	[[maybe_unused]] constexpr bool is_container_v = decltype(has_value_type<Tp>(int{}))::value || is_iterable_container_v<Tp>;

	template <>
	[[maybe_unused]] constexpr bool is_iterable_container_v<std::string_view> = false;
	template <>
	[[maybe_unused]] constexpr bool is_container_v<std::string_view> = false;
#if INCLUDED(STRING)
	template <>
	[[maybe_unused]] constexpr bool is_iterable_container_v<std::string> = false;
	template <>
	[[maybe_unused]] constexpr bool is_container_v<std::string> = false;
#endif

	template <class Tp, class... Ts>
	struct first_element
	{
		using type = Tp;
	};
	template <class... Ts>
	using first_t = typename first_element<Ts...>::type;

	template <class Tp, std::enable_if_t<!decltype(has_value_type<Tp>(int{}))::value, std::nullptr_t> = nullptr>
	auto check_elem(int) -> decltype(*std::cbegin(std::declval<Tp>()));
	template <class Tp, std::enable_if_t<decltype(has_value_type<Tp>(int{}))::value, std::nullptr_t> = nullptr>
	auto check_elem(int) -> typename Tp::value_type;
	template <class Tp>
	auto check_elem(...) -> void;

	template <class Tp>
	using elem_t = decltype(check_elem<Tp>(int{}));

	template <class Tp>
	[[maybe_unused]] constexpr bool is_multidim_container_v = is_container_v<Tp> && is_container_v<elem_t<Tp>>;

	template <class Tp>
	std::enable_if_t<!is_container_v<Tp>> out(const Tp &);
	void out(const char &);
	void out(const char *);
	void out(const std::string_view &);

#if INCLUDED(STRING)
	void out(const std::string &);
#endif

#ifdef __SIZEOF_INT128__
	void out(const __int128 &);
	void out(const unsigned __int128 &);
#endif

	template <class Tp1, class Tp2>
	void out(const std::pair<Tp1, Tp2> &);

#if INCLUDED(TUPLE)
	template <class... Ts>
	void out(const std::tuple<Ts...> &);
#endif

#if INCLUDED(STACK)
	template <class... Ts>
	void out(std::stack<Ts...>);
#endif

#if INCLUDED(QUEUE)
	template <class... Ts>
	void out(std::queue<Ts...>);
	template <class... Ts>
	void out(std::priority_queue<Ts...>);
#endif

	template <class C>
	std::enable_if_t<is_iterable_container_v<C>> out(const C &);

	template <class Tp>
	std::enable_if_t<!is_container_v<Tp>> out(const Tp &arg)
	{
		os << arg;
	}

	void out(const char &arg)
	{
		os << '\'' << arg << '\'';
	}

	void out(const char *arg)
	{
		os << '\"' << arg << '\"';
	}

	void out(const std::string_view &arg)
	{
		os << '\"' << arg << '\"';
	}

#if INCLUDED(STRING)
	void out(const std::string &arg)
	{
		os << '\"' << arg << '\"';
	}
#endif

#ifdef __SIZEOF_INT128__
	void out(const __int128 &arg)
	{
		int sign = (arg < 0) ? (-1) : 1;
		if (sign == -1)
			os << '-';
		__int128 base = sign;
		while (sign * arg >= sign * base * 10)
			base *= 10;
		while (base)
		{
			os << static_cast<char>('0' + (arg / base % 10));
			base /= 10;
		}
	}

	void out(const unsigned __int128 &arg)
	{
		unsigned __int128 base = 1;
		while (arg >= base * 10)
			base *= 10;
		while (base)
		{
			os << static_cast<char>('0' + (arg / base % 10));
			base /= 10;
		}
	}
#endif

	template <class Tp1, class Tp2>
	void out(const std::pair<Tp1, Tp2> &arg)
	{
		os << '(';
		out(arg.first);
		os << ", ";
		out(arg.second);
		os << ')';
	}

#if INCLUDED(TUPLE)
	template <class T, std::size_t... Is>
	void print_tuple(const T &arg, std::index_sequence<Is...>)
	{
		static_cast<void>(((os << (Is == 0 ? "" : ", "), out(std::get<Is>(arg))), ...));
	}

	template <class... Ts>
	void out(const std::tuple<Ts...> &arg)
	{
		os << '(';
		print_tuple(arg, std::make_index_sequence<sizeof...(Ts)>());
		os << ')';
	}
#endif

#if INCLUDED(STACK)
	template <class... Ts>
	void out(std::stack<Ts...> arg)
	{
		if (arg.empty())
		{
			os << "<empty stack>";
			return;
		}
		os << "[ ";
		while (!arg.empty())
		{
			out(arg.top());
			os << ' ';
			arg.pop();
		}
		os << ']';
	}
#endif

#if INCLUDED(QUEUE)
	template <class... Ts>
	void out(std::queue<Ts...> arg)
	{
		if (arg.empty())
		{
			os << "<empty queue>";
			return;
		}
		os << "[ ";
		while (!arg.empty())
		{
			out(arg.front());
			os << ' ';
			arg.pop();
		}
		os << ']';
	}
	template <class... Ts>
	void out(std::priority_queue<Ts...> arg)
	{
		if (arg.empty())
		{
			os << "<empty priority_queue>";
			return;
		}
		os << "[ ";
		while (!arg.empty())
		{
			out(arg.top());
			os << ' ';
			arg.pop();
		}
		os << ']';
	}
#endif

	template <class Container>
	std::enable_if_t<is_iterable_container_v<Container>> out(const Container &arg)
	{
		if (std::distance(std::cbegin(arg), std::cend(arg)) == 0)
		{
			os << "<empty container>";
			return;
		}
		os << "[ ";
		std::for_each(std::cbegin(arg), std::cend(arg), [](const elem_t<Container> &elem)
					  {
      out(elem);
      os << ' '; });
		os << ']';
	}

	template <class Tp>
	std::enable_if_t<!is_multidim_container_v<Tp>>
	print(std::string_view name, const Tp &arg)
	{
		os << name << ": ";
		out(arg);
		if constexpr (is_container_v<Tp>)
			os << '\n';
	}

	template <class Tp>
	std::enable_if_t<is_multidim_container_v<Tp>>
	print(std::string_view name, const Tp &arg)
	{
		os << name << ": ";
		if (std::distance(std::cbegin(arg), std::cend(arg)) == 0)
		{
			os << "<empty multidimensional container>\n";
			return;
		}
		std::for_each(std::cbegin(arg), std::cend(arg),
					  [&name, is_first_elem = true](const elem_t<Tp> &elem) mutable
					  {
						  if (is_first_elem)
							  is_first_elem = false;
						  else
							  for (std::size_t i = 0; i < name.length() + 2; i++)
								  os << ' ';
						  out(elem);
						  os << '\n';
					  });
	}

	template <class Tp, class... Ts>
	void multi_print(std::string_view names, const Tp &arg, const Ts &...args)
	{
		if constexpr (sizeof...(Ts) == 0)
		{
			names.remove_suffix(
				std::distance(
					names.crbegin(),
					std::find_if_not(names.crbegin(), names.crend(),
									 [](const char c)
									 { return std::isspace(c); })));
			print(names, arg);
			if constexpr (!is_container_v<Tp>)
				os << '\n';
		}
		else
		{
			std::size_t comma_pos = 0;

			for (std::size_t i = 0, paren_depth = 0, inside_quote = false; i < names.length(); i++)
			{
				if (!inside_quote && paren_depth == 0 && i > 0 && names[i - 1] != '\'' && names[i] == ',')
				{
					comma_pos = i;
					break;
				}
				if (names[i] == '\"' || names[i] == '\'')
				{
					if (i > 0 && names[i - 1] == '\\')
						continue;
					inside_quote ^= true;
				}
				if (!inside_quote && names[i] == '(' && (i == 0 || names[i - 1] != '\''))
					paren_depth++;
				if (!inside_quote && names[i] == ')' && (i == 0 || names[i - 1] != '\''))
					paren_depth--;
			}

			const std::size_t first_varname_length = comma_pos - std::distance(
																	 names.crend() - comma_pos,
																	 std::find_if_not(
																		 names.crend() - comma_pos, names.crend(),
																		 [](const char c)
																		 { return std::isspace(c); }));
			print(names.substr(0, first_varname_length), arg);

			if constexpr (!is_container_v<Tp>)
			{
				if constexpr (is_container_v<first_t<Ts...>>)
					os << '\n';
				else
					os << " | ";
			}

			const std::size_t next_varname_begins_at = std::distance(
				names.cbegin(),
				std::find_if_not(
					names.cbegin() + comma_pos + 1, names.cend(),
					[](const char c)
					{ return std::isspace(c); }));
			names.remove_prefix(next_varname_begins_at);

			multi_print(names, args...);
		}
	}
} // namespace debug_print

#undef INCLUDED

#endif // DEBUG_PRINT_HPP

#pragma endregion

/* Variables */
ll N, M;
ll ans = 0;
// bool ans = true;
// string ans = "";
string S = "";

/* Main Function */

bool timeok(int H, int M)
{
	// debug_print::print(H, M);
	return (H >= 0 && H <= 23 && M >= 0 && M <= 59);
}

bool misstime(int H, int M)
{
	int A = floor(H / 10), B = H % 10, C = floor(M / 10), D = M % 10;
	int AC = A * 10 + C;
	int BD = B * 10 + D;

	return timeok(AC, BD);
}

int main(int argc, char const *argv[])
{
	fastio;

	ll H, M;

	cin >> H >> M;

	while (true)
	{
		if (M >= 60)
		{
			H++;
			M = 0;
		}
		if (H >= 24)
		{
			H = 0;
		}

		if (misstime(H, M))
		{
			cout << H << " " << M << endl;
			exit;
		}
		M++;
	}

	return 0;
}

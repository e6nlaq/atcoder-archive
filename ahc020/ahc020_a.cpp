/*---------------------------------------------------



	   Welcome to my program!

	?????        @x__0
	? ( ????)
	?(__?/??? /  MIT License
	???/???? /  C++ GCC 11.3.0 + Boost 1.82.0
	?????????
		   Let's write Code!


---------------------------------------------------*/

// Return Code 139(out_of_range)??????
// #define _GLIBCXX_DEBUG

// Boost?
// #include <boost/multiprecision/cpp_int.hpp>			 // ??????
// #include <boost/multiprecision/cpp_dec_float.hpp>	 // ??????
// #include <boost/math/constants/constants.hpp>		 // ???????
// #include <boost/date_time/gregorian/gregorian.hpp>	 // ??????????

// #include <boost/algorithm/string/split.hpp>			 // ????char???(split)
// #include <boost/algorithm/string/classification.hpp> // ?????????
// #include <boost/algorithm/string/iter_find.hpp>		 // ????string???(iter_split)
// #include <boost/algorithm/string/finder.hpp>		 // ??????????

// #include <boost/algorithm/string/join.hpp>			 // ?????join???????
// #include <boost/algorithm/string/replace.hpp>		 // ??????

// #include <boost/dynamic_bitset.hpp>					 // ??????bitset
// #include <boost/range/algorithm/for_each.hpp>		 // ???foreach?

// #include <boost/assert.hpp> // ??????

// Boost??????
// namespace mu = boost::multiprecision;
// namespace ag = boost::algorithm;

#pragma region AtCoder Template

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#ifdef _LOCAL_
#include "./lib/debug_print.hpp"
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// ???
#pragma GCC target("avx,avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define fastio                         \
	cin.tie(nullptr);                  \
	ios::sync_with_stdio(false);       \
	cout << fixed << setprecision(15); \
	srand((unsigned)time(NULL));

// ???
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
#define unmap unordered_map
#define unset unordered_set

// ???
#define rep(i, n) for (ull i = 0; i < (ull)(n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)
#define irep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define arep(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define adrep(i, a, d, n) for (ll i = (a); i < (ll)(n); i += d)
#define until(b) while (!(b)) // ???rwhile?!until??!

// ??define
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

// ??
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

// ???????(?????)

template <class T>
size_t HashCombine(const size_t seed, const T &v)
{
	return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}
/* pair? */
template <class T, class S>
struct std::hash<std::pair<T, S>>
{
	size_t operator()(const std::pair<T, S> &keyval) const noexcept
	{
		return HashCombine(std::hash<T>()(keyval.first), keyval.second);
	}
};
/* vector? */
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
/* tuple? */
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

// ???

/**
 * @brief ??????????
 *
 * @param num ??????
 * @return bool ??????
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
 * @brief ?????????????(2,4...)
 *
 * @param x ????????
 * @return bool ??????
 */
inline bool iseven(const int x)
{
	if (x % 2 == 0)
		return true;
	return false;
}

/**
 * @brief ??????????????(1,3...)
 *
 * @param x ????????
 * @return bool ??????
 */
inline bool isodd(const int x)
{
	if (x % 2 != 0)
		return true;
	return false;
}

/**
 * @brief char?????int???????
 *
 * @param c ??????
 * @return int ??????
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
 * @brief bool????????????
 *
 * @param b ??????
 */
inline void flip(bool &b)
{
	b = !b;
}

/**
 * @brief ??????0?????
 *
 * @tparam T ????
 * @param i ??
 * @param s ??????
 * @return string 0???????
 */
template <typename T>
inline string zerou(const T i, string s)
{
	while (s.size() != i)
		s = '0' + s;
	return s;
}

/**
 * @brief T??char???????
 *
 * @tparam T ?????
 * @param i ??????
 * @return char ??????
 */
template <typename T>
inline char to_char(const T i)
{
	return '0' + i;
}

/**
 * @brief i < j ???i?j???????
 *
 * @tparam T1_ i??
 * @tparam T2_ j??
 * @param i ???????
 * @param j ??????
 * @return bool ?????????
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
 * @brief i > j ???i?j???????
 *
 * @tparam T1_ i??
 * @tparam T2_ j??
 * @param i ???????
 * @param j ??????
 * @return bool ?????????
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
 * @brief 10??????2???????????
 *
 * @param n ??????
 * @return string 2??????????
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
 * @brief ?????????????
 *
 * @tparam T ????(vector<T>)
 * @param v ??
 * @param s ?????(????????)
 * @author https://zenn.dev/antyuntyun
 */
template <typename T>
inline void print(const vector<T> &v, string s = " ")
{
	rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}

/// @brief ???????????????
/// @tparam T ????(vector<vector<T>>)
/// @param v ?????
/// @param s ?????
template <typename T>
inline void print(const vector<vector<T>> &v, string s = " ")
{
	rep(i, v.size())
	{
		rep(j, v[i].size()) cout << v[i][j] << (j != (ll)v[i].size() - 1 ? s : "\n");
	}
}

/**
 * @brief ????????
 *
 * @tparam Tp1 ????
 * @param v ??????
 */
template <typename Tp1>
inline void vcin(vector<Tp1> &v)
{
	rep(i, v.size()) cin >> v[i];
}

/// @brief ????????????
/// @tparam Tp1 1???????
/// @tparam Tp2 2???????
/// @param v 1?????
/// @param b 2?????
/// @throw v.size()!=b.size()???????????
template <typename Tp1, typename Tp2>
inline void vcin(vector<Tp1> &v, vector<Tp2> &b)
{
	assert(v.size() == b.size());
	rep(i, v.size()) cin >> v[i] >> b[i];
}

/// @brief ????????????
/// @tparam Tp1 vector<vector<Tp1>>??
/// @param v ?????
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
 * @brief ????????????????
 *
 * @param s ???????
 * @return string ???????
 */
inline string srev(string s)
{
	reverse(all(s));
	return s;
}

/// @brief long long???????
/// @param x x^n?x
/// @param n x^n?n
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

/// @brief N???????10???????????
/// @param c N?????
/// @return ????10?????
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

/// @brief 10??????N???????????
/// @param n 10?????
/// @return N?????
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

/// @brief N???????M????????????
/// @param str N?????
/// @param n ?????
/// @param m ?????
/// @return M?????
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

/// @brief n?????????
/// @tparam T n??
/// @param n ????????
/// @return ??
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

/// @brief N??????????
/// @tparam T N??
/// @param N ?????????
/// @return N?????
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

/// @brief n???????????(???: O(sqrt(N)))
/// @param n ???????
/// @return n???
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

/// @brief ?????????????? O(|S|)
/// @param s ???????
/// @return ?????????????
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

/// @brief ??????90??????????
/// @tparam T ????(vector<vector<T>>)
/// @param arr ?????
/// @return ???
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

/// @brief ????????
/// @param str ???
/// @return ??????
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

/// @brief start??n????????
/// @param n ???
/// @param start ???
/// @return start??n?????
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

/// @brief 10?????????????????
/// @param s 10?????????
/// @return ????
inline ll csum(string s)
{
	ll ret = 0;
	rep(i, s.size())
	{
		ret += ctoi(s[i]);
	}

	return ret;
}

/// @brief csum?????????
/// @param n ??
/// @return ????
inline ll csum(ll n)
{
	return csum(to_string(n));
}

/// @brief ???????
/// @param n n???
/// @return n???
inline ll fact(ll n)
{
	ll ret = 1;
	rep(i, n)
	{
		ret *= i + 1;
	}
	return ret;
}

/// @brief ??????????
/// @param N ?????
/// @return ???????
inline bool is_squere(long long N)
{
	long long r = (long long)floor(sqrt((long double)N)); // ?????????
	return (r * r) == N;
}

/// @brief ????????????
/// @tparam T vector??
/// @param v ????????
/// @return ??????(??? |v|+1 ??????)
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

/// @brief ????????????
/// @tparam T vector<vector<>>??
/// @param v ??????
/// @return ??????(???????+1?????)
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

#pragma endregion

/* Variables */
ll N, M, Q;
ll H, W;
ll sum = 0, cnt = 0;
ll ans = 0;
// string N;
// ll ans = INFLL - 1LL;
// ld ans = 0;
// bool ans = true;
// string ans = "";
string S = "", T = "";
string dump = "";

/* Main Function */

int main()
{
	fastio;

	cin >> N >> M;

	vll P(N);
	rep(i, N)
	{
		P[i] = rand() % 5000;
	}
	vll B(M);
	rep(i, M)
	{
		B[i] = rand() % 2;
	}

	print(P);
	print(B);

	return 0;
}

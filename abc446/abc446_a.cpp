/*------------------------------------------------------------


               Welcome!
               @x__0 / @e6nlaq

            　　∧＿∧        Competitive Programming
            　 ( 　･ω･)      AtCoder, Codeforces and yukicoder
            ＿(__つ/￣￣￣ /
            　　＼/　　　　 /  C++ GCC 14.2.0
            　　　　￣￣￣￣￣

     ______________________________
    |  _____                       |
    |  |   |                       |
    |  | V |  I'm not a robot      |
    |  |___|                       |
    |______________________________| XD

------------------------------------------------------------*/

/* #region AtCoder Template */

#include <bits/stdc++.h>

#include <cctype>
using namespace std;

// ローカル環境チェック
#if __has_include("./cpp-dump/cpp-dump.hpp")
#define LOCAL
#define _GLIBCXX_DEBUG
#endif

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

#ifdef LOCAL
#include "./debug.hpp"

namespace cp = cpp_dump;

// clangdを黙らせる
const auto _unnsedcpnamespaceunwarn = cp::options::es_value;
#else
#define debug(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#endif

// 高速化
#pragma GCC target("avx,avx2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

// 型省略
using uint = unsigned;
using ll = long long;
// using ll = __int128_t;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vd = vector<double>;
using vld = vector<ld>;
using vull = vector<ull>;
using vpll = vector<pll>;
using pdd = pair<ld, ld>;
using psl = pair<string, ll>;
using pcl = pair<char, ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvb = vector<vb>;
using vvld = vector<vld>;
using vvd = vector<vd>;
using mll = map<ll, ll>;
using mcl = map<char, ll>;
using msl = map<string, ll>;
using sll = set<ll>;
using spll = set<pair<ll, ll>>;
using spdd = set<pair<ld, ld>>;
using stll = stack<ll>;
using qll = queue<ll>;
using qd = queue<ld>;
using qs = queue<string>;
using qc = queue<char>;
using int128_t = __int128_t;

template <typename Tp1, typename Tp2>
using unmap = unordered_map<Tp1, Tp2>;

template <typename Tp>
using unset = unordered_set<Tp>;

template <typename Tp>
using reverse_queue = priority_queue<Tp, vector<Tp>, greater<Tp>>;

template <typename T>
using vec2 = vector<vector<T>>;

template <typename T>
using vec3 = vector<vector<vector<T>>>;

#if __cplusplus >= 202002L
#define cpp20

template <typename T>
concept number = integral<T> || floating_point<T>;

#endif

// マクロ
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define irep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define arep(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define adrep(i, a, d, n) for (ll i = (a); i < (ll)(n); i += d)
#define until(b) while (!(b))

// 省略define
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define elif else if

// LOCALはflush欲しいよ～
#ifndef LOCAL
#define endl "\n"
#endif

template <typename T>
    requires convertible_to<T, bool>
inline void YESNO(T b) {
    cout << (b ? "YES" : "NO") << endl;
}

template <typename T>
    requires convertible_to<T, bool>
inline void yesno(T b) {
    cout << (b ? "yes" : "no") << endl;
}

template <typename T>
    requires convertible_to<T, bool>
inline void YesNo(T b) {
    cout << (b ? "Yes" : "No") << endl;
}

template <typename T, typename tr, typename fal>
    requires convertible_to<T, bool>
inline void outif(T b, tr tru, fal fals) {
    if (b) {
        cout << tru << endl;
    } else {
        cout << fals << endl;
    }
}

#define exit exit(0)

void co() {
    cout << endl;
}

template <typename Head, typename... Tail>
void co(Head head, Tail... tail) {
    cout << head;

    if constexpr (sizeof...(tail) > 0) {
        cout << " ";
    }

    co(tail...);
}

// 定数

const string sl = "";
constexpr char cl = '\0';
constexpr ll nl = 0LL;
constexpr ll INFINT = 2047483647;
constexpr ll INFLL = (1LL << 61);  // だいたい
const ll mod1 = pow(10, 9) + 1;
constexpr char sp = ' ';
const ll j2_32 = pow(2, 32);
const ll j2_m32 = pow(2, -32);
const ll j2_10 = pow(2, 10);
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};
const vector<int> ex = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> ey = {-1, 0, 1, -1, 1, -1, 0, 1};
const string spa = " ";
constexpr bool except = true;

mt19937_64 rng;

// 色々なテンプレ(完全コピペ)

template <class T>
size_t HashCombine(const size_t seed, const T& v) {
    return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}
/* pair用 */
template <class T, class S>
struct std::hash<std::pair<T, S>> {
    size_t operator()(const std::pair<T, S>& keyval) const noexcept {
        return HashCombine(std::hash<T>()(keyval.first), keyval.second);
    }
};
/* vector用 */
template <class T>
struct std::hash<std::vector<T>> {
    size_t operator()(const std::vector<T>& keyval) const noexcept {
        size_t s = 0;
        for (auto&& v : keyval)
            s = HashCombine(s, v);
        return s;
    }
};
/* tuple用 */
template <int N>
struct HashTupleCore {
    template <class Tuple>
    size_t operator()(const Tuple& keyval) const noexcept {
        size_t s = HashTupleCore<N - 1>()(keyval);
        return HashCombine(s, std::get<N - 1>(keyval));
    }
};
template <>
struct HashTupleCore<0> {
    template <class Tuple>
    size_t operator()(const Tuple& keyval) const noexcept { return 0; }
};
template <class... Args>
struct std::hash<std::tuple<Args...>> {
    size_t operator()(const tuple<Args...>& keyval) const noexcept {
        return HashTupleCore<tuple_size<tuple<Args...>>::value>()(keyval);
    }
};

std::string
operator""_s(char const* str, std::size_t) {
    return str;
}

std::string
operator*(std::string const& str, int n) {
    if (n < 1)
        return "";
    std::string result;
    result.reserve(str.length() * n);
    for (int i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

// https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128 parse(string& s) {
    __int128 ret = 0;
    for (ull i = 0; i < s.length(); i++)
        if ('0' <= s[i] && s[i] <= '9')
            ret = 10 * ret + s[i] - '0';

    if (s[0] == '-') {
        ret = -ret;
    }

    return ret;
}

istream& operator>>(std::istream& is, __int128_t& value) {
    string tmp;
    is >> tmp;

    value = parse(tmp);

    return is;
}

// 関数類

// O(√N)
inline bool isprime(const ull num) noexcept {
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    for (ull i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// O(1)
inline int ctoi(const char c) {
    assert(c >= '0' && c <= '9');
    return c - '0';
}

// O(1)
inline ull minisum(const ull n) noexcept {
    return n * (n + 1ULL) / 2ULL;
}

// 数値0埋め
// O(N)
inline string zerou(const ull i, string s) noexcept {
    while (s.size() != i)
        s = '0' + s;
    return s;
}

inline string zerou(const ull i, const ull n) noexcept {
    return zerou(i, to_string(n));
}

/**
 * @brief T型をchar型に変換します
 *
 * @tparam T 変換する型
 * @param i 変換する数値
 * @return char 変換後の文字
 */
inline char to_char(const ull i) {
    assert(i <= 9);
    return '0' + i;
}

template <typename T1, typename T2>
    requires totally_ordered_with<T1, T2> && assignable_from<T1&, T2>
inline bool chmax(T1& i, const T2 j) noexcept {
    if (i < j) {
        i = j;
        return true;
    }
    return false;
}

template <typename T1, typename T2>
    requires totally_ordered_with<T1, T2> && assignable_from<T1&, T2>
inline bool chmin(T1& i, const T2 j) noexcept {
    if (i > j) {
        i = j;
        return true;
    }
    return false;
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
inline void print(const vector<T>& v, const string& s = " ") noexcept {
    rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");
}

template <typename A, typename B>
inline void print(const vector<pair<A, B>>& v, const string& s = "\n") noexcept {
    rep(i, v.size()) cout << v[i].first << " " << v[i].second << s;
}

/// @brief 二次元配列の全要素を出力します
/// @tparam T 配列の型(vector<vector<T>>)
/// @param v 二次元配列
/// @param s 区切り文字
template <typename T>
inline void print(const vector<vector<T>>& v, string const& s = " ") noexcept(except) {
    rep(i, v.size()) {
        rep(j, v[i].size()) cout << v[i][j] << (j != (ll)v[i].size() - 1 ? s : "\n");
    }
}

template <typename T>
inline istream& operator>>(istream& os, vector<T>& v) {
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    rep(i, v.size()) {
        cin >> v[i];
    }

    return os;
}

/**
 * @brief 文字列を反転した文字列を返します
 *
 * @param s 反転する文字列
 * @return string 反転後の文字列
 */
inline string srev(string s) noexcept {
    reverse(all(s));
    return s;
}

// 整数べき乗
// O(log N)
inline unsigned long long pow_ll(unsigned long long x, unsigned long long n) noexcept {
    ull ret = 1LL;
    while (n > 0) {
        if (n & 1LL)
            ret *= x;
        x *= x;
        n >>= 1LL;
    }

    return ret;
}

template <typename T>
inline vector<vector<T>> make_vec2(const ull H, const ull W, const T& init) {
    return vector<vector<T>>(H, vector<T>(W, init));
}

template <typename T>
inline vector<vector<T>> make_vec2(const ull H, const ull W) {
    return vector<vector<T>>(H, vector<T>(W));
}

template <typename T>
inline vector<vector<vector<T>>> make_vec3(const ull X, const ull Y, const ull Z, const T& init) {
    return vector<vector<vector<T>>>(X, make_vec2<T>(Y, Z, init));
}

template <typename T>
inline vector<vector<vector<T>>> make_vec3(const ull X, const ull Y, const ull Z) {
    return vector<vector<vector<T>>>(X, make_vec2<T>(Y, Z));
}

/// @brief N進数の文字から10進数の数値に変換します
/// @param c N進数の文字
/// @return 変換した10進数の数値
inline int ntodec(const char c) {
    switch (c) {
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
inline char decton(const int n) {
    switch (n) {
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
inline string n_ary(const string& str, const int n, const int m) {
    unsigned long tmp = 0;
    string ret;

    for (unsigned long long i = 0; i < str.length(); i++) {
        tmp += (unsigned long)ntodec(str[str.length() - 1 - i]) * pow_ll(n, i);
    }

    if (tmp == 0)
        return "0";
    while (tmp != 0) {
        ret = decton(tmp % m) + ret;
        tmp /= m;
    }
    return ret;
}

/// @brief
/// @tparam T nの型
/// @param n 素因数分解する数
/// @return 不明
template <typename T>
inline map<T, T> prime_factor_map(T n) {
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++) {
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret[i] = tmp;
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

// 素因数分解
// O(sqrt(N))
vector<pair<ll, ll>> prime_factor(ll N) {
    vector<pair<ll, ll>> res;

    for (ll p = 2; p * p <= N; ++p) {
        if (N % p != 0) {
            continue;
        }

        int e = 0;
        while (N % p == 0) {
            ++e;
            N /= p;
        }

        res.emplace_back(p, e);
    }

    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

// 約数の個数
// O(sqrt(N))
inline ull divisor_num(const ll N) {
    map<ll, ll> pf = prime_factor_map(N);
    ull ret = 1;
    for (auto p : pf) {
        ret *= (p.second + 1);
    }
    return ret;
}

/// @brief nの約数を全列挙します。(計算量: O(sqrt(N)))
/// @param n 全列挙する約数
/// @return nの約数
inline vll divisor(const ll n) {
    vll ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
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
inline bool isint(const string& s) noexcept {
    rep(i, s.size()) {
        if (!isdigit(s[i])) {
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
[[nodiscard]] inline vector<vector<T>> rot90(const vector<vector<T>>& A) {
    ll N = A.size(), M = A[0].size();
    vector<vector<T>> ret(M, vector<T>(N));

    ll _i = 0, _j = 0;

    rep(j, M) {
        for (ll i = N - 1; i >= 0; i--) {
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
inline bool ispalind(const string& str) noexcept {
    ull n = str.length();
    for (ull i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

inline bool ispalind(const string& str, ull x, ull n) {
    assert(x < str.size());
    assert(x + n <= str.size());

    for (ull i = 0; i < n / 2; i++) {
        if (str[x + i] != str[(x + n) - i - 1]) {
            return false;
        }
    }
    return true;
}

/// @brief 10進法で表した時の各桁の和を求めます
/// @param s 10進法で表した文字列
/// @return 各桁の和
inline ll csum(const string& s) noexcept {
    ll ret = 0;
    rep(i, s.size()) {
        ret += ctoi(s[i]);
    }

    return ret;
}

/// @brief csumの数値用の補完関数
/// @param n 数値
/// @return 各桁の和
inline ll csum(const ll n) noexcept {
    return csum(to_string(n));
}

/// @brief 階乗を計算する
/// @param n nの階乗
/// @return nの階乗
inline ll fact(const ll n) noexcept {
    ll ret = 1;
    rep(i, n) {
        ret *= i + 1;
    }
    return ret;
}

/// @brief 一次元の累積和を返します
/// @tparam T vectorの型
/// @param v 加工する前の配列
/// @return 加工後の配列(長さは |v|+1 となります。)
template <typename T>
inline vector<T> cum(const vector<T>& v) noexcept {
    vector<T> ans(v.size() + 1);
    ans[0] = 0;
    for (ull i = 1; i <= v.size(); i++) {
        ans[i] = ans[i - 1] + v[i - 1];
    }
    return ans;
}

/// @brief 二次元の累積和を返します
/// @tparam T vector<vector<>>の型
/// @param v 加工前の配列
/// @return 加工後の配列(長さはそれぞれ+1になります)
template <typename T>
inline vec2<T> cum(const vec2<T>& v) {
    assert(v.size() > 0);
    ull H = v.size(), W = v[0].size();
    auto ret = make_vec2<T>(H + 1, W + 1, 0);
    for (ull i = 1; i <= H; i++) {
        for (ull j = 1; j <= W; j++) {
            ret[i][j] = ret[i][j - 1] + v[i - 1][j - 1];
        }
    }

    for (ull j = 1; j <= W; j++) {
        for (ull i = 1; i <= H; i++) {
            ret[i][j] += ret[i - 1][j];
        }
    }

    return ret;
}

template <typename T>
inline vec3<T> cum(const vec3<T>& v) {
    assert(v.size() > 0 && v[0].size() > 0);
    ll x = v.size();
    ll y = v[0].size();
    ll z = v[0][0].size();
    auto ret = make_vec3<T>(x + 1, y + 1, z + 1, 0);

    for (ll i = 0; i < x; ++i) {
        for (ll j = 0; j < y; ++j) {
            for (ll k = 0; k < z; ++k) {
                ret[i + 1][j + 1][k + 1] =
                    ret[i][j + 1][k + 1] + ret[i + 1][j][k + 1] +
                    ret[i + 1][j + 1][k] - ret[i][j][k + 1] - ret[i][j + 1][k] -
                    ret[i + 1][j][k] + ret[i][j][k] + v[i][j][k];
            }
        }
    }

    return ret;
}

// 0-indexed
template <typename T>
inline ll cumcnt(const vec2<T>& z, ll lx, ll ly, ll rx, ll ry) {
    lx++;
    ly++;
    rx++;
    ry++;
    return z[rx][ry] + z[lx - 1][ly - 1] - z[lx - 1][ry] - z[rx][ly - 1];
}

template <typename T>
inline ll cumcnt(const vec3<T>& z, ll lx, ll ly, ll lz, ll rx, ll ry, ll rz) {
    lx++;
    ly++;
    lz++;
    rx++;
    ry++;
    rz++;
    return z[rx][ry][rz] - z[lx - 1][ry][rz] - z[rx][ly - 1][rz] - z[rx][ry][lz - 1] + z[lx - 1][ly - 1][rz] + z[lx - 1][ry][lz - 1] + z[rx][ly - 1][lz - 1] - z[lx - 1][ly - 1][lz - 1];
}

#ifdef cpp20
template <integral T>
#else
template <typename T>
#endif
inline vector<T> cumxor(const vector<T>& x) {
    vector<T> ans(x.size() + 1);
    ans[0] = 0;
    irep(i, x.size()) {
        ans[i] = ans[i - 1] ^ x[i - 1];
    }

    return ans;
}

/// @brief ランダムな数値を返す
/// @param l 最小値
/// @param r 最大値
/// @return
inline ll randint(const ll l, const ll r) noexcept {
    if (l == r)
        return l;
    return l + (rng() % (r - l + 1));
}

/// @brief 高速全探索 O(log N)
/// @tparam T 配列の型
/// @param v 配列
/// @param x 探索するやつ
/// @return 数
template <typename T>
inline long long bound_count(const vector<T>& v, const T& x) noexcept {
    auto l = lower_bound(v.begin(), v.end(), x);
    auto u = upper_bound(v.begin(), v.end(), x);

    if (*l != x) {
        return 0;
    }

    if (u == v.end()) {
        return v.size() - (l - v.begin());
    } else {
        return (u - v.begin()) - (l - v.begin());
    }
}

/// @brief 配列の最近値を求める
/// @tparam T 配列の型
/// @param v 配列
/// @param x 最近値を求める値
/// @return xの最近値
template <typename T>
inline T recent(const vector<T>& v, const T& x) noexcept {
    auto it = lower_bound(all(v), x);

    if (it == v.end())
        return *prev(v.end(), 1);
    else {
        if (it == v.begin())
            return *v.begin();
        else {
            if (abs(*it - x) < abs(*prev(it, 1) - x))
                return *it;
            else
                return *prev(it, 1);
        }
    }
}

/// @brief 文字列圧縮
/// @param str 圧縮する文字列
/// @return 圧縮後
inline vector<pair<char, ull>> rlencode(const string& str) noexcept {
    ull n = (ull)str.size();
    vector<pair<char, ull>> ret;
    for (ull l = 0; l < n;) {
        ull r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {
        };
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

template <typename T>
inline vector<pair<T, ull>> rlencode(const vector<T>& v) noexcept {
    ull n = (ull)v.size();
    vector<pair<T, ull>> ret;
    for (ull l = 0; l < n;) {
        ull r = l + 1;
        for (; r < n && v[l] == v[r]; r++) {
        };
        ret.push_back({v[l], r - l});
        l = r;
    }
    return ret;
}

template <typename T>
inline map<T, ll> counter(const vector<T>& v) noexcept {
    map<T, ll> dat;
    rep(i, v.size()) {
        dat[v[i]]++;
    }

    return dat;
}

inline map<char, ll> counter(const string& s) noexcept {
    map<char, ll> dat;
    rep(i, s.size()) {
        dat[s[i]]++;
    }

    return dat;
}

/// @brief ユークリッド距離
/// @param x1
/// @param y1
/// @param x2
/// @param y2
/// @return
inline ld euclidean(const ld x1, const ld y1, const ld x2, const ld y2) noexcept {
    ld dx = x2 - x1;
    ld dy = y2 - y1;

    ld distance = sqrt(dx * dx + dy * dy);

    return distance;
}

/// @brief 配列の範囲(閉区間)に属する値の個数を計算
/// @tparam T 配列の値型
/// @param v 配列
/// @param l 左端
/// @param r 右端
/// @return
template <typename T>
inline ll lencnt(const vector<T>& v, const T& l, const T& r) noexcept {
    return upper_bound(all(v), r) - lower_bound(all(v), l);
}

using GraphKey = ll;

struct CostEdge {
    GraphKey to;
    ll cost;

#if __cplusplus >= 202002L
    auto operator<=>(const CostEdge& e) const {
        return this->cost <=> e.cost;
    }
#endif

    bool operator==(const CostEdge& e) const {
        return this->cost == e.cost;
    }
};

struct FromCostEdge : CostEdge {
    GraphKey from;
};

ostream& operator<<(ostream& os, const CostEdge& cost) {
    os << "{ to: " << cost.to << ", cost: " << cost.cost << " }";

    return os;
}

using Edge = GraphKey;

using Graph = vector<vector<Edge>>;
using CostGraph = vector<vector<CostEdge>>;

inline CostEdge make_cost(const GraphKey to, const ll cost) noexcept {
    return CostEdge{to, cost};
}

inline CostGraph to_costgraph(const Graph& g) noexcept {
    CostGraph ans(g.size());
    rep(i, g.size()) {
        rep(j, g[i].size()) {
            ans[i].emplace_back(CostEdge{g[i][j], 1});
        }
    }

    return ans;
}

inline pair<GraphKey, ll> __tree_diamiter_dfs(const CostGraph& G, ll u, ll par) {  // 最遠点間距離と最遠点を求める
    pair<GraphKey, ll> ret = make_pair((GraphKey)0, u);
    for (auto e : G[u]) {
        if (e.to == par)
            continue;
        auto next = __tree_diamiter_dfs(G, e.to, u);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}

// 木の直径
inline GraphKey tree_diamiter(const CostGraph& G) {
    pair<GraphKey, ll> p = __tree_diamiter_dfs(G, 0LL, -1LL);
    pair<GraphKey, ll> q = __tree_diamiter_dfs(G, p.second, -1LL);
    return q.first;
}

// 木の直径
// O(V)
inline GraphKey tree_diamiter(const Graph& G) {
    return tree_diamiter(to_costgraph(G));
}

inline vector<ll> dijkstra(const CostGraph& G, ll start = 0, ll init = 0) {
    ll n = G.size();
    assert(0 <= start && start < n);
    vector<bool> kakutei(n, false);
    vll cur(n, INFLL);

    reverse_queue<pll> q;
    cur[start] = init;
    q.push(make_pair(cur[start], start));

    while (!q.empty()) {
        ll pos = q.top().second;
        q.pop();

        if (kakutei[pos])
            continue;

        kakutei[pos] = true;
        rep(i, G[pos].size()) {
            ll nex = G[pos][i].to;
            ll cost = G[pos][i].cost;
            if (cur[nex] > cur[pos] + cost) {
                cur[nex] = cur[pos] + cost;
                q.push(make_pair(cur[nex], nex));
            }
        }
    }

    return cur;
}

inline vector<ll> dijkstra(const CostGraph& G, vll& prv, ll start = 0, ll init = 0) {
    ll n = G.size();
    assert(0 <= start && start < n);
    vector<bool> kakutei(n, false);
    vll cur(n, INFLL);
    prv.resize(G.size(), -1);

    reverse_queue<pll> q;
    cur[start] = init;
    q.push(make_pair(cur[start], start));

    while (!q.empty()) {
        ll pos = q.top().second;
        q.pop();

        if (kakutei[pos])
            continue;

        kakutei[pos] = true;
        rep(i, G[pos].size()) {
            ll nex = G[pos][i].to;
            ll cost = G[pos][i].cost;
            if (cur[nex] > cur[pos] + cost) {
                cur[nex] = cur[pos] + cost;
                prv[nex] = pos;
                q.push(make_pair(cur[nex], nex));
            }
        }
    }

    return cur;
}

inline vector<ll> get_path(const vector<ll>& prev, ll t) {
    vector<ll> path;
    for (ll cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());  // 逆順なのでひっくり返す
    return path;
}

inline vector<ll> dijkstra(const Graph& G, ll start = 0, ll init = 0) {
    return dijkstra(to_costgraph(G), start, init);
}

inline vector<ll> dijkstra(const Graph& G, vll& prv, ll start = 0, ll init = 0) {
    return dijkstra(to_costgraph(G), prv, start, init);
}

inline vector<vector<ll>> warshall_floyd(const CostGraph& G) {
    ll n = G.size();
    vvll d = make_vec2<ll>(n, n, INFLL);

    rep(i, n) {
        d[i][i] = 0;
    }

    rep(i, n) {
        rep(j, G[i].size()) {
            d[i][G[i][j].to] = G[i][j].cost;
        }
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    return d;
}

inline vector<vector<ll>> warshall_floyd(const Graph& G) {
    return warshall_floyd(to_costgraph(G));
}

template <ull bit, ull n>
class CustomBit {
   public:
    explicit CustomBit(ull val = 0) {
        this->__val = val;
        this->__max_val = pow_ll(bit, n) - 1;
        this->__reload();
    }

    ull to_ull() const {
        return this->__val;
    }

    // O(1)
    ull max_val() const {
        return this->__max_val;
    }

    // O(1)
    array<ull, n> get_all() const {
        return this->__dat;
    }

    // O(1)
    ull get(ull x) const {
        assert(x < n);

        return this->__dat[x];
    }

    // O(1)
    constexpr ull size() const {
        return n;
    }

    constexpr void set(ull x, ull val) {
        assert(val < bit);
        this->__dat[x] = val;

        this->__reload_val();
    }

    CustomBit& operator++(int) {
        this->__val++;
        this->__reload();

        return *this;
    }

    CustomBit& operator++() {
        auto tmp = *this;
        ++this->__val;

        this->__reload();

        return tmp;
    }

   private:
    ull __val;
    array<ull, n> __dat;
    ull __max_val;

    void __reload() {
        assert(0 <= this->__val && this->__val <= this->__max_val);
        auto tmp = this->__val;
        for (ll i = 0; i < n; ++i) {
            this->__dat[i] = tmp % bit;
            tmp /= bit;
        }
    }

    void __reload_val() {
        this->__val = 0;
        ull a = 1;
        for (ll i = 0; i < n; ++i) {
            this->__val += a * this->__dat[i];
            a *= bit;
        }
    }
};

template <ull bit, ull n>
ostream& operator<<(ostream& os, const CustomBit<bit, n>& bits) {
    os << "[";
    for (ll i = 0; i < n; ++i) {
        os << bits.get(i) << (i != n - 1 ? ", " : "");
    }
    os << "](bit: " << bit << ")";

    return os;
}

/// @brief Union-Find 木
/// @note 1.4 高速化 + 省メモリ化
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/union-find
class UnionFind {
   public:
    UnionFind() = default;

    /// @brief Union-Find 木を構築します。
    /// @param n 要素数
    explicit UnionFind(size_t n)
        : m_parentsOrSize(n, -1) {}

    /// @brief 頂点 i の root のインデックスを返します。
    /// @param i 調べる頂点のインデックス
    /// @return 頂点 i の root のインデックス
    ll find(ll i) {
        if (m_parentsOrSize[i] < 0) {
            return i;
        }

        // 経路圧縮
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }

    /// @brief a のグループと b のグループを統合します。
    /// @param a 一方のインデックス
    /// @param b 他方のインデックス
    void merge(ll a, ll b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            // union by size (小さいほうが子になる）
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
                std::swap(a, b);
            }

            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }

    /// @brief a と b が同じグループに属すかを返します。
    /// @param a 一方のインデックス
    /// @param b 他方のインデックス
    /// @return a と b が同じグループに属す場合 true, それ以外の場合は false
    bool connected(ll a, ll b) {
        return (find(a) == find(b));
    }

    /// @brief i が属するグループの要素数を返します。
    /// @param i インデックス
    /// @return i が属するグループの要素数
    ll size(ll i) {
        return -m_parentsOrSize[find(i)];
    }

   private:
    // m_parentsOrSize[i] は i の 親,
    // ただし root の場合は (-1 * そのグループに属する要素数)
    std::vector<ll> m_parentsOrSize;
};

inline vector<FromCostEdge> to_fromcostedges(const CostGraph& g) {
    vector<FromCostEdge> dat;
    rep(i, g.size()) {
        rep(j, g[i].size()) {
            dat.emplace_back(FromCostEdge{{g[i][j].to, g[i][j].cost}, i});
        }
    }

    return dat;
}

/// @brief 最小・最大全域木
/// @param e 辺(ソート済み)
/// @param v 頂点数
/// @return
/// @see https://x.gd/7JLRg
inline ll get_mst(const vector<FromCostEdge>& edges, ll v) {
    UnionFind uf(v);
    ll sum = 0;

    for (const auto& edge : edges) {
        if (!uf.connected(edge.from, edge.to)) {
            uf.merge(edge.from, edge.to);
            sum += edge.cost;
        }
    }

    return sum;
}

template <typename T>
inline T sum(const vector<T>& v) {
    T ans = 0;
    rep(i, v.size()) ans += v[i];

    return ans;
}

#ifdef cpp20
template <number T>
#else
template <typename T>
#endif
inline vector<T> zaatsu(const vector<T>& A) {
    vector<T> B = A;

    // B を小さい順にソート
    sort(B.begin(), B.end());

    // B から重複を除去する
    B.erase(unique(B.begin(), B.end()), B.end());

    // 座標圧縮した結果を求める
    vector<T> res(A.size());
    for (ull i = 0; i < A.size(); ++i) {
        res[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    }

    return res;
}

#ifdef cpp20
// https://x.gd/yonBS
class Doubling {
   public:
    explicit Doubling(const vll& x, ull max_k) {
        k = bit_width(max_k);
        n = x.size();
        dp = make_vec2<ll>(k + 1, n);
        this->max_k = max_k;

        rep(j, n) dp[0][j] = x[j];

        irep(i, k) {
            rep(j, n) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }

    ull to(ull pos, ull k) const {
        assert(k <= max_k);
        ll now = pos;
        for (ull i = 0; k > 0; ++i) {
            if (k & 1) now = dp[i][now];

            k >>= 1;
        }

        return now;
    }

   private:
    ull n;
    ull k;
    ull max_k;
    vvll dp;
};

inline void gmerge(Graph& g, ull a, ull b) {
    assert(a < g.size());
    assert(b < g.size());
    g[a].emplace_back(b);
    g[b].emplace_back(a);
}

inline void gmerge(CostGraph& g, ull a, ull b, ll c) {
    assert(a < g.size());
    assert(b < g.size());
    g[a].emplace_back(make_cost(b, c));
    g[b].emplace_back(make_cost(a, c));
}

// https://x.gd/a7Yhv
inline constexpr ll mmod(ll x, ll m) noexcept {
    return (x % m + m) % m;
}

// Hash
constexpr ll HMOD = (1LL << 61LL) - 1LL;
ll HB = 0;
vll HPOW;
bool inited_hpow = false;

inline void fastio() noexcept {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    rng = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
    HB = randint(150, HMOD - 10);
}

inline vll str_to_vec(const string& s) {
    vll ans(s.size());
    rep(i, s.size()) {
        ans[i] = s[i];
    }

    return ans;
}

inline ll hmod_mul(ll x, ll y) {
    int128_t t = int128_t(x) * int128_t(y);
    t = (t >> 61) + (t & HMOD);

    if (t >= HMOD) return t - HMOD;
    return ll(t);
}

inline void init_hash(ll n) {
    HPOW.resize(n + 1);
    HPOW[0] = 1;
    irep(i, n) HPOW[i] = hmod_mul(HPOW[i - 1], HB);

    inited_hpow = true;
}

inline vll rolling_hash(const vll& a) {
    assert(inited_hpow);

    vll h(a.size() + 1);
    h[0] = 0;
    irep(i, a.size()) h[i] = (hmod_mul(h[i - 1], HB) + (a[i - 1] % HMOD)) % HMOD;

    return h;
}

inline vll rolling_hash(const string& s) {
    return rolling_hash(str_to_vec(s));
}

inline ll get_hash(const vll& h, ll l, ll r) {
    ll val = h[r + 1] - hmod_mul(h[l], HPOW[r - l + 1]);
    if (val < 0) val += HMOD;

    return val;
}

struct TopologicalResult {
    vector<int> sort;
    bool just_one;
};

inline TopologicalResult topological_sort(const Graph& graph) noexcept {
    // 各頂点の入次数を管理する配列
    std::vector<int> indegrees(graph.size());

    // 入次数を計算する
    for (const auto& v : graph) {
        for (const auto& to : v) {
            ++indegrees[to];
        }
    }

    // 入次数が 0 の頂点を管理するキュー（辞書順最小の結果を得るため、優先度付きキューを使用する）
    std::priority_queue<int, std::vector<int>, std::greater<>> q;

    // 現時点で入次数が 0 の頂点をすべてキューに追加する
    for (int i = 0; i < static_cast<int>(graph.size()); ++i) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    // 結果（トポロジカル順序）を格納する配列
    std::vector<int> result;

    bool one = true;

    while (!q.empty()) {
        if (1 < q.size()) {
            one = false;
        }

        // 入次数が 0 の頂点のうち、頂点番号が小さいものから取り出す
        const int from = q.top();
        q.pop();

        // トポロジカル順序に追加する
        result.push_back(from);

        // その頂点から出る各辺について
        for (const auto& to : graph[from]) {
            // その先の頂点の入次数を減らし、新たに 0 になったらキューに追加する
            if (--indegrees[to] == 0) {
                q.push(to);
            }
        }
    }

    // 閉路が存在する（頂点をすべて処理できていない）場合
    if (result.size() < graph.size()) {
        // 空の配列を返す
        return {{}, false};
    }

    return {result, one};
}

// 共通部分もってる?
inline bool has_kyotsu(pll l, pll r) noexcept {
    if (l.first <= r.first && r.second <= l.second) return true;
    if (r.first <= l.first && l.second <= r.second) return true;
    if (r.first <= l.first && l.first <= r.second && r.second <= l.second) return true;
    if (l.first <= r.first && r.first <= l.second && l.second <= r.second) return true;

    return false;
}

// 共通部分取得
inline pll get_kyotu(pll l, pll r) noexcept {
    assert(has_kyotsu(l, r));
    return {max(l.first, r.first), min(l.second, r.second)};
}

// nCk
template <typename mint>
class Combination {
   private:
    static const int MAX = 510000;
    mint fac[MAX], finv[MAX], inv[MAX];

   public:
    // テーブルを作る前処理
    Combination() {
        const int MOD = mint::mod();
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i;
            inv[i] = MOD - inv[MOD % i] * (MOD / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }

    // 二項係数計算
    mint COM(int n, int k) const {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * finv[k] * finv[n - k];
    }
};

class imos {
   private:
    vll dat;

   public:
    imos(ll n, ll init = 0) : dat(n + 1, 0) {
        add(0, n, init);
    }

    // [l, r) に x を加える
    // O(1)
    void add(ull l, ull r, ll x) {
        assert(l <= r && r <= dat.size());
        dat[l] += x;
        dat[r] -= x;
    }

    // O(n)
    vll get() const {
        vll res(dat.size() - 1);
        res[0] = dat[0];
        arep(i, 1, res.size()) res[i] = res[i - 1] + dat[i];

        return res;
    }
};

template <integral T>
struct PrimeFact {
    vector<T> spf;

    // O(N log log N)
    PrimeFact(T N) { init(N); }

    void init(T N) {
        spf.assign(N + 1, 0);
        for (T i = 0; i <= N; i++) spf[i] = i;
        for (T i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    // O(log N)
    map<T, T> get(T n) {
        assert(1 <= n && n < spf.size());
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};

/**
 * @brief 切り上げ(無限大方向)除算を行います
 * @tparam T 整数型
 * @param a 被除数
 * @param b 0でない除数 (b != 0)
 * @return T ceil(a / b) の値（正の無限大方向に丸め）
 * @throw std::invalid_argument bが0の場合
 * @note 計算量: O(1)
 * @note a や b が負の場合も正の無限大方向に丸めます
 */
template <std::integral T>
inline constexpr T div_ceil(T a, T b) {
    if (b == 0) {
        throw std::invalid_argument("div_ceil: division by zero");
    }

    T res = a / b;
    T rem = a % b;

    // 剰余があり、かつaとbが同符号（結果が正）の場合に切り上げる
    if (rem != 0 && (a > 0 == b > 0)) {
        res++;
    }
    return res;
}

// https://nyaannyaan.github.io/library/math/isqrt.hpp
// floor(sqrt(n)) を返す (ただし n が負の場合は 0 を返す)
long long isqrt(long long n) {
    if (n <= 0) return 0;
    long long x = sqrt(n);
    while ((x + 1) * (x + 1) <= n) x++;
    while (x * x > n) x--;
    return x;
}

inline bool is_squere(const ll N) noexcept {
    long long r = isqrt(N);  // 切り捨てした平方根
    return (r * r) == N;
}

template <integral T>
int digits(T n) {
    using UnsignedT = std::make_unsigned_t<T>;
    UnsignedT x;
    if (n < 0)
        x = -static_cast<UnsignedT>(n);
    else
        x = n;
    x |= 1;

    if constexpr (sizeof(UnsignedT) <= 4) {  // 32bit or less
        static const int lower_bound_table[] = {9, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0};
        static const unsigned int pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

        int lower_bound = lower_bound_table[std::countl_zero(static_cast<unsigned int>(x))];
        return lower_bound + (pow[lower_bound] <= x);
    } else {  // 64bit
        static const int lower_bound_table[] = {
            19, 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13, 13, 13,
            12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 7, 6, 6, 6,
            5, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0};
        static const unsigned long long pow[] = {
            1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
            10000000000ULL, 100000000000ULL, 1000000000000ULL, 10000000000000ULL,
            100000000000000ULL, 1000000000000000ULL, 10000000000000000ULL,
            100000000000000000ULL, 1000000000000000000ULL, 10000000000000000000ULL};

        int lower_bound = lower_bound_table[std::countl_zero(x)];
        return lower_bound + (pow[lower_bound] <= x);
    }
}

template <typename T>
inline T emit(const T& a, const T& b, const T& x) {
    assert(a == x ^ b == x);
    if (a == x) return b;
    return a;
}

// Thank you, Tamiji!
template <typename S, typename T>
struct default_map : map<S, T> {
    T def;
    explicit default_map(T def) : def(def) {}
    T& operator[](const S& i) { return map<S, T>::emplace(i, def).first->second; }
};

#endif

/* #endregion */

/* Variables */

#ifndef LIBTEST

ll N, M, K, Q;
ll H, W;
string S = "";
string dump = "";
ll codeforces_t = -1;

/* Main Function */

int main() {
    fastio();

    cin >> S;

    S[0] = tolower(S[0]);
    cout << "Of" << S << endl;

    return 0;
}

#endif

/* 文字化け注意 */

/*------------------------------------------------------------


               Welcome to my program!
               @x__0 / @e6nlaq

            　　∧＿∧        AtCoder / Codeforces  etc...
            　 ( 　･ω･)
            ＿(__つ/￣￣￣ /
            　　＼/　　　　 /  C++ GCC 14.2.0
            　　　　￣￣￣￣￣
                               Let's write Codes!


------------------------------------------------------------*/

// Return Code 139(out_of_range)が出たら試す
// #define _GLIBCXX_DEBUG

/* #region AtCoder Template */

#include <bits/stdc++.h>
using namespace std;

// ローカル環境チェック
#if __has_include("./cpp-dump/cpp-dump.hpp")
#define LOCAL
#endif

// AC Library(C++17では使えないので注意)
#if defined(LOCAL) || defined(ATCODER)
#include <atcoder/all>
using namespace atcoder;
#endif

#ifdef LOCAL
#include "./cpp-dump/cpp-dump.hpp"

#ifdef ATCODER_MODINT_HPP
namespace cpp_dump::_detail {

template <int m>
inline std::string export_var(
    const atcoder::static_modint<m> &mint, const std::string &indent, std::size_t last_line_length,
    std::size_t current_depth, bool fail_on_newline, const export_command &command) {
    return export_var(mint.val(), indent, last_line_length, current_depth, fail_on_newline, command);
}

template <int m>
inline std::string export_var(
    const atcoder::dynamic_modint<m> &mint, const std::string &indent, std::size_t last_line_length,
    std::size_t current_depth, bool fail_on_newline, const export_command &command) {
    return export_var(mint.val(), indent, last_line_length, current_depth, fail_on_newline, command);
}

}  // namespace cpp_dump::_detail
#endif

#define debug(...) cpp_dump(__VA_ARGS__)
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cpp_dump::log_label::filename(true));

// 色数を増やす
CPP_DUMP_SET_OPTION_GLOBAL(es_value.log, "\x1b[02m");                 // log: 灰色
CPP_DUMP_SET_OPTION_GLOBAL(es_value.expression, "\x1b[38;5;39m");     // reserved: 明るい青
CPP_DUMP_SET_OPTION_GLOBAL(es_value.reserved, "\x1b[34m");            // expression: 青
CPP_DUMP_SET_OPTION_GLOBAL(es_value.number, "\x1b[38;5;150m");        // number: 明るい緑
CPP_DUMP_SET_OPTION_GLOBAL(es_value.character, "\x1b[38;5;172m");     // character: オレンジ
CPP_DUMP_SET_OPTION_GLOBAL(es_value.escaped_char, "\x1b[38;5;220m");  // escaped_char: 明るいオレンジ
CPP_DUMP_SET_OPTION_GLOBAL(es_value.op, "\x1b[02m");                  // op: 灰色
CPP_DUMP_SET_OPTION_GLOBAL(es_value.identifier, "\x1b[32m");          // identifier: 緑
CPP_DUMP_SET_OPTION_GLOBAL(es_value.member, "\x1b[96m");              // member: 明るいシアン
CPP_DUMP_SET_OPTION_GLOBAL(es_value.unsupported, "\x1b[31m");         // unsupported: 赤
CPP_DUMP_SET_OPTION_GLOBAL(es_value.bracket_by_depth, (std::vector<std::string>{
                                                          "\x1b[33m",  // bracket_by_depth[0]: 黄色
                                                          "\x1b[35m",  // bracket_by_depth[1]: マゼンタ
                                                          "\x1b[36m",  // bracket_by_depth[2]: シアン
                                                      }));
CPP_DUMP_SET_OPTION_GLOBAL(es_value.class_op, "\x1b[02m");   // class_op: 灰色
CPP_DUMP_SET_OPTION_GLOBAL(es_value.member_op, "\x1b[02m");  // member_op: 灰色
CPP_DUMP_SET_OPTION_GLOBAL(es_value.number_op, "");          // number_op: デフォルト

// クラスやメンバ、数値の演算子(::, <>, (), -, +, etc...)に
// 色(class_op, member_op, number_op)を付ける
CPP_DUMP_SET_OPTION_GLOBAL(detailed_class_es, true);
CPP_DUMP_SET_OPTION_GLOBAL(detailed_member_es, true);
CPP_DUMP_SET_OPTION_GLOBAL(detailed_number_es, true);

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
#define endl "\n"
#define elif else if

template <typename T>
inline void YESNO(T b) {
    cout << (b ? "YES" : "NO") << endl;
}

template <typename T>
inline void yesno(T b) {
    cout << (b ? "yes" : "no") << endl;
}

template <typename T>
inline void YesNo(T b) {
    cout << (b ? "Yes" : "No") << endl;
}

template <typename T, typename tr, typename fal>
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
size_t HashCombine(const size_t seed, const T &v) {
    return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}
/* pair用 */
template <class T, class S>
struct std::hash<std::pair<T, S>> {
    size_t operator()(const std::pair<T, S> &keyval) const noexcept {
        return HashCombine(std::hash<T>()(keyval.first), keyval.second);
    }
};
/* vector用 */
template <class T>
struct std::hash<std::vector<T>> {
    size_t operator()(const std::vector<T> &keyval) const noexcept {
        size_t s = 0;
        for (auto &&v : keyval)
            s = HashCombine(s, v);
        return s;
    }
};
/* tuple用 */
template <int N>
struct HashTupleCore {
    template <class Tuple>
    size_t operator()(const Tuple &keyval) const noexcept {
        size_t s = HashTupleCore<N - 1>()(keyval);
        return HashCombine(s, std::get<N - 1>(keyval));
    }
};
template <>
struct HashTupleCore<0> {
    template <class Tuple>
    size_t operator()(const Tuple &keyval) const noexcept { return 0; }
};
template <class... Args>
struct std::hash<std::tuple<Args...>> {
    size_t operator()(const tuple<Args...> &keyval) const noexcept {
        return HashTupleCore<tuple_size<tuple<Args...>>::value>()(keyval);
    }
};

std::string
operator""_s(char const *str, std::size_t) {
    return str;
}

std::string
operator*(std::string const &str, int n) {
    if (n < 1)
        return "";
    std::string result;
    result.reserve(str.length() * n);
    for (int i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

template <typename T>
inline istream &operator>>(istream &os, vector<T> &v) {
#ifdef LOCAL
    assert(v.size() != 0);
#endif
    rep(i, v.size()) {
        cin >> v[i];
    }

    return os;
}

/* #endregion */

/* Variables */
ll N, M, K, Q;
ll H, W;
string S = "";
string dump = "";
ll codeforces_t = -1;

/* Main Function */

int main() {
    cin >> Q;
    while (Q--) {
        cin >> N >> M;
        vll A(N), B(N);
        cin >> A >> B;

        rep(i, N) {
            A[i] %= M;
            B[i] %= M;
        }

        sort(rall(A));
        multiset<ll> b;
        rep(i, N) b.insert(B[i]);
        ll ans = 0;
        rep(i, N) {
            auto it = b.lower_bound(M - A[i]);
            if (it != b.end()) {
                ans += (A[i] + *it) % M;
                b.erase(it);
            } else {
                auto it = b.begin();
                ans += (A[i] + *it) % M;
                b.erase(it);
            }
        }
        co(ans);
    }

    return 0;
}

/* 文字化け注意 */

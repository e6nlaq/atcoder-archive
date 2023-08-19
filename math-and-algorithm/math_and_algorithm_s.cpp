#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;

ll nc2(ll n) { return n*(n-1)/2; }

int main() {
    int n,t; cin >> n;
    vector<int> a(3);
    for(int i = 0; i < n; i++) {
        cin >> t;
        a[t-1]++;
    }

    cout << nc2(a[0]) + nc2(a[1]) + nc2(a[2]) << endl;
}

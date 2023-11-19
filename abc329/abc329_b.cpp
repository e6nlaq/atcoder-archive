#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    set<int> dat;
    for (int i = 0; i < N; ++i){
        int A;
        cin >> A;

        dat.emplace(A);
    }

    dat.erase(*dat.rbegin());

    cout << *dat.rbegin() << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> dat(N, 0);
    pair<int, int> tmp;

    for (int i = 0; i < M; ++i){
        int A;
        cin >> A;

        A--;
        dat[A]++;

        if (dat[A] > tmp.second || (dat[A] == tmp.second && A < tmp.first))
        {
            tmp.first = A;
            tmp.second = dat[A];
        }

        cout << tmp.first + 1 << endl;
    }

    return 0;
}
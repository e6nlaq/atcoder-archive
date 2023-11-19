#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    map<char, int> dat;
    char mae = S[0];
    int cnt = 1;

    for (int i = 1; i < N; ++i){
        if(S[i]!=mae){
            dat[mae] = max(dat[mae], cnt);
            cnt = 1;
        }else{
            cnt++;
        }
        mae = S[i];
    }

    dat[mae]=max(dat[mae], cnt);

    int ans = 0;
    for(auto x:dat){
        ans += x.second;
    }

    cout << ans << endl;

    return 0;
}
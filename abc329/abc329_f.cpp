#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin>>N>>Q;

    vector<int> C(N);
    for (int i = 0; i < N; ++i){
        cin >> C[i];
    }

    vector<set<int>> dat(N);
    for(int i = 0; i < N; ++i){
        dat[i].emplace(C[i]);
    }

    while(Q--){
        int a,b;
        cin >> a >> b;

        a--;
        b--;

        if(dat[a].size()<dat[b].size()){
            dat[b].merge(dat[a]);
            dat[a].clear();
        }
        else{
            dat[a].merge(dat[b]);
            dat[b].clear();
            swap(dat[a],dat[b]);
        }

        cout << dat[b].size() << endl;
    }

    return 0;
}
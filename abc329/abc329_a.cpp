#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); ++i)
    {
        cout << S[i] << (i != S.size() - 1 ? " " : "\n");
    }

    return 0;
}
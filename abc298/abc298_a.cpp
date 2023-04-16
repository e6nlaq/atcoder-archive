#include<bits/stdc++.h>
using namespace std;int main(){string n,s;cin>>n>>s;cout<<(count(begin(s),end(s),'o')>0&count(begin(s),end(s),'x')<1?"Yes":"No");return 0;}
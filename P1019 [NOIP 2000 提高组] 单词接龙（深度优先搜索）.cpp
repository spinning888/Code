#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,ans=0;
int mark[25]={0};
char c;
string ss[25];

string check(string s,string t){
    int len1=s.length(),len2=t.length();
    for(int i=1;i<min(len1,len2);i++){
       if(s.substr(len1-i,i)==t.substr(0,i)){
            return s.substr(0,len1-i)+t;
       }
    }
    return "-1";
}

void dfs(string s){
    ans=max(ans,(int)s.length());
    for(int i=0;i<n;i++){
        if(mark[i]==2) continue;
        if(check(s,ss[i])!="-1"){
            mark[i]++;
            string next=check(s,ss[i]);
            dfs(next);
            mark[i]--;
        }
    }
}

void solve() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ss[i];
    }
    cin>>c;
    for(int i=0;i<n;i++){
        if(ss[i][0]==c){
            mark[i]++;
            dfs(ss[i]);
            mark[i]--;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

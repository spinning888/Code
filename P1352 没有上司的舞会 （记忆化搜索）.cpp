#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int memo[6010][2]={0},happy[6010];
vector<int> v[6010];

int dfs(int i,int s){
    if(memo[i][s]) return memo[i][s];
    if(s){
        int sum=happy[i];
        for(int j=0;j<v[i].size();j++){
            sum+=dfs(v[i][j],0);
        }
        memo[i][s]=sum;
    }else{
        int sum=0;
        for(int j=0;j<v[i].size();j++){
            sum+=max(dfs(v[i][j],0),dfs(v[i][j],1));
        }
        memo[i][s]=sum;
    }
    return memo[i][s];
}

void solve(){
   cin>>n;
   for(int i=1;i<=n;i++){
        cin>>happy[i];
   }
   for(int i=1;i<=n-1;i++){
        int l,k;
        cin>>l>>k;
        v[k].push_back(l);
   }
   int ans=INT_MIN;
   for(int i=1;i<=n;i++){
        ans=max(ans,max(dfs(i,0),dfs(i,1)));
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

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
struct matrix{
    ll c[3][3];
    matrix(){memset(c,0,sizeof c);}
}F,A,res,ans;
ll n;

matrix operator*(matrix &x,matrix &y){
    matrix t;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++)
                t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j])%mod;
    return t;
}

void quickpow(ll n){
    for(int i=1;i<=2;i++) res.c[i][i]=1;
    while(n){
        if(n&1) res=res*A;
        A=A*A;
        n>>=1;
    }
}

void solve(){
    cin>>n;
    if(n<=2){
        cout<<"1"<<endl;
        return;
    }
    F.c[1][1]=F.c[1][2]=1;
    A.c[1][1]=A.c[1][2]=A.c[2][1]=1;
    quickpow(n-2);
    ans=F*res;
    cout<<ans.c[1][1]%mod<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500010;
int n,d,k;
int a[N][2];
ll f[N],sum=0;

bool check(int g){
    int l=max(1,d-g),r=d+g;
    memset(f,-127,sizeof f);
    f[0]=0;
    int pl=0,pr=0;
    for(int i=1;i<=n;i++){
        while(a[i][0]-a[pl][0]>r) pl++;
        while(a[i][0]-a[pr][0]>=l) pr++;
        for(int j=pr-1;j>=pl;j--){
            f[i]=max(f[i],f[j]+a[i][1]);
            if(f[i]>=k) return true;
        }
    }
    return false;
}

void solve(){
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        if(a[i][1]>0) sum+=a[i][1];
    }
    if(sum<k){
        cout<<"-1"<<endl;
        return;
    }
    int l=0,r=max(0,a[n][0]-d);
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

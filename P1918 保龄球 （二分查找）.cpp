#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e7+10;
int n,t,l,r,x,ans,a[N],b[N];

bool cmp(int i,int j){
	return a[i]<a[j];
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i],b[i]=i;
	}
    sort(b+1,b+n+1,cmp);
    cin>>t;
    while(t--){
        cin>>x;
        l=1,r=n,ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[b[mid]]==x){
                ans=b[mid];
                break;
            }else if(a[b[mid]]<x)l=mid+1;
            else r=mid-1;
        }
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

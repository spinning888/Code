#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
int n,ans=0,minn=0;//minn要初始化为0
int a[N],b[N];


void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];//前缀和
	}
	ans=b[1];
	//最小区间和=b[i]-min(b[j])(j<i)
	for(int i=1;i<=n;i++){
		ans=max(ans,b[i]-minn);
		minn=min(minn,b[i]);
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}

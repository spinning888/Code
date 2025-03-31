#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int s[N],a[N][N];
int l,r,ans=0,minn=INT_MAX;

void dfs(int p,int n){
	if(p>s[n]){//完成当科题目
		minn=min(max(l,r),minn);
		return;
	}
	if(l>=minn||r>=minn) return;
	l+=a[n][p];
	dfs(p+1,n);
	l-=a[n][p];
	r+=a[n][p];
	dfs(p+1,n);
	r-=a[n][p];
	return;
}

void solve(){
	for(int i=1;i<=4;i++){
		cin>>s[i];
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=s[i];j++){
			cin>>a[i][j];
		}
		l=0,r=0;
		dfs(1,i);//第i科第一题开始
		ans+=minn;
		minn=INT_MAX;
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}

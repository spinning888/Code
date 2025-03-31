#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=10005;
int n,tot=0;
int vis[N]={0},a[N];

void print(int n){
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i!=n) cout<<"+";
	}
	cout<<endl;
}

void dfs(int x,int k){
	if(x==0&&k>2){//k>2避免输出n一个数的情况
		print(k-1);
		return;
	}
	for(int i=a[k-1];i<=x;i++){//字典序，后一个数大于等于前一个数，注意i<=x
		a[k]=i;
		dfs(x-i,k+1);
	}
	return;
}

void solve(){
	cin>>n;
	a[0]=1;//避免0+0+.....
	dfs(n,1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}

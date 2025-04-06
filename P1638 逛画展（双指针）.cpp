#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e7+10;
int n,m,l,r,s=0,ansl=0,ansr=0,ans;
int a[N],b[N];


void solve(){
	cin>>n>>m;
	l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1,ans=n;
	for(int i=1;i<=n;i++){
		if(!b[a[i]]) s++;
		b[a[i]]++;
		if(s==m){
			while(b[a[l]]>1){
				b[a[l]]--;
				l++;
			}
			if(i-l<ans){
				ans=i-l;
				ansl=l;
				ansr=i;
			}
		}
	}
	cout<<ansl<<" "<<ansr<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}

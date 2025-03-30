#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=100005;
int A[N],C[N];
int la,lc;

void div(int A[],int b,int C[]){
	ll r=0;//r为当前被除数
	//从最高位开始处理
	for(int i=la-1;~i;i--){
		r=r*10+A[i];//从被除数拉下一位数
		C[la-i-1]=r/b;
		r%=b;
	}
	reverse(C,C+lc);
	while(lc&&!C[lc]) lc--;//删除前导零
}

void solve(){
	string a;
	int b;
	cin>>a>>b;
	lc=la=a.size();
	for(int i=la-1;~i;i--){
		A[la-i-1]=a[i]-'0';
	}
	div(A,b,C);
	for(int i=lc;~i;i--){
		cout<<C[i];
	}
	cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=100005;
int A[N],B[N],C[N];
int la,lb,lc;

//依据C[i+j]=A[i]+B[j],如C1=A0B1+A1B0
void mul(int A[],int B[],int C[]){
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			C[i+j]+=A[i]*B[j];
			C[i+j+1]+=C[i+j]/10;
			C[i+j]%=10;
		}
	}
	while(lc&&!C[lc]) lc--;//当有一个乘数为0时删除前导零
}

void solve(){
	string a,b;
	cin>>a>>b;
	la=a.size(),lb=b.size();
	lc=max(la,lb);
    for(int i=la-1;~i;i--){
		A[la-i-1]=a[i]-'0';//c的为la-1,a应为0
	}
	for(int i=lb-1;~i;i--){
		B[lb-i-1]=b[i]-'0';
	}
	mul(A,B,C);
	for(int i=lc;~i;i--){//注意是lc不是lc-1
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
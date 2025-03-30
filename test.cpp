#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=100005;
int A[N],B[N],C[N];
int la,lb,lc;

void add(int A[],int B[],int C[]){
	for(int i=0;i<lc;i++){
		C[i]+=A[i]+B[i];
		C[i+1]=C[i]/10;
		C[i]%=10;
	}
	if(C[lc]) lc++;
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
	add(A,B,C);
	for(int i=lc-1;~i;i--){
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
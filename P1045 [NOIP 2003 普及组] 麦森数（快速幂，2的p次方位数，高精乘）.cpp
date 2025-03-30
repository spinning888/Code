#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int rev[1005],f[1005],sav[1005];//sav用来存储计算的结果

//计算新的rev，并赋给rev
void mul1(){
	memset(sav,0,sizeof(sav));
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			sav[i+j-1]+=rev[i]*f[j];
			sav[i+j]+=sav[i+j-1]/10;
			sav[i+j-1]%=10;
		}
	}
	memcpy(rev,sav,sizeof(rev));
}

//计算底数的平方，并赋给f
void mul2(){
	memset(sav,0,sizeof(sav));
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			sav[i+j-1]+=f[i]*f[j];
			sav[i+j]+=sav[i+j-1]/10;
			sav[i+j-1]%=10;
		}
	}
	memcpy(f,sav,sizeof(f));
}

void solve(){
	int p;
	cin>>p;
	cout<<(int)(p*log10(2)+1);
	//快速幂计算2的p次方
	rev[1]=1;
	f[1]=2;
	while(p!=0){
		if(p%2) mul1();
		p/=2;
		mul2();
	}
	rev[1]--;
	for(int i=500;i>=1;i--){
		if(i%50==0) cout<<endl;
		cout<<rev[i];
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();
    return 0;
}

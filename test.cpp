#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=100005;
int A[N],B[N],C[N];
int la,lb,lc;

bool cmp(int A[],int B[]){
	if(la!=lb) return la>lb;
	for(int i=la-1;~i;i--){
		if(A[i]!=B[i]) return A[i]>B[i];
	}
	return true;//避免输出-0

}
void sub(int A[],int B[],int C[]){
	for(int i=0;i<lc;i++){
		if(A[i]<B[i]){
			A[i]+=10;
			A[i+1]--;
		}
		C[i]=A[i]-B[i];
	}
	while(lc&&!C[lc]) lc--;//删除前导零
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
	if(!cmp(A,B)){
		swap(A,B);
		cout<<"-";
	}
	sub(A,B,C);
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
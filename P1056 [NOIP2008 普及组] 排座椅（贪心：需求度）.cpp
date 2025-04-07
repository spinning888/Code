#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1000010;
int m,n,k,l,d,ans=0;

struct node{
    int x,y;
}g[N],v[N];

bool cmp1(node a,node b){
    return a.y>b.y;
}

bool cmp2(node a,node b){
    return a.x<b.x;
}

void solve(){
	cin>>m>>n>>k>>l>>d;
    for(int i=1;i<=m;i++){
        g[i].x=i;
    }
    for(int i=1;i<=n;i++){
        v[i].x=i;
    }
	for(int i=1;i<=d;i++){
        int dx,dy,tx,ty;
        cin>>dx>>dy>>tx>>ty;
        if(dx==tx){
            g[min(dy,ty)].y++;
	    }
        if(dy==ty){
            v[min(dx,tx)].y++;
	    }
    }
    sort(g+1,g+m+1,cmp1);
    sort(v+1,v+n+1,cmp1);
    sort(g+1,g+l+1,cmp2);
    sort(v+1,v+k+1,cmp2);
    for(int i=1;i<=k;i++){
        cout<<v[i].x<<(i==k?"\n":" ");
    }
    for(int i=1;i<=l;i++){
        cout<<g[i].x<<(i==l?"\n":" ");
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

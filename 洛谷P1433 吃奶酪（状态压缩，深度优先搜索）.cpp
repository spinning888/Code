#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1001;
double n;
double ans=DBL_MAX,f[20][33000]={0};

struct point{
    int num;
    double x;
    double y;
    bool vis=false;
}p[20];

double dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void dfs(const point& a,int cnt,int mark,double s){
    if(cnt==n){
        ans=min(ans,s);
        return;
    }
    for(int i=0;i<n;i++){
        if(p[i].vis) continue;
        int tmpmark=mark+(1<<i);
        if(f[i][tmpmark]==0||f[i][tmpmark]>f[a.num][mark]+dis(a,p[i])){
            f[i][tmpmark]=f[a.num][mark]+dis(a,p[i]);
            p[i].vis=true;
            dfs(p[i],cnt+1,tmpmark,s+dis(a,p[i]));
            p[i].vis=false;
        }
    }
    
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].num=i;
    }
    point p={0,0,0,false};
    dfs(p,0,0,0);
    cout<<fixed<<setprecision(2)<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

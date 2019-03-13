/*
TOI14
Task: Logistic
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int n,m,u,v,w,s,d,f,c[maxn];
int dp[maxn][maxn][2];
bool vis[maxn][maxn][2];
vector<pair<int,int>> a[maxn];
struct pa{
    int val;
    int nod;
    int lf;
    bool cp;
    bool operator<(const pa z)const{
        return val>z.val;
    }
}p;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    scanf("%d%d%d%d",&s,&d,&f,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
        dp[i][j][0]=1e9;
        dp[i][j][1]=1e9;
    }
    }
    priority_queue<pa> q;
    dp[s][0][1]=0;
    q.push({0,s,0,1});
    while(!q.empty()){
        while(!q.empty()&&vis[q.top().nod][q.top().lf][q.top().cp]){
            q.pop();
        }
        if(q.empty())
            break;
        p=q.top();
        vis[p.nod][p.lf][p.cp]=true;
        if(p.cp){
            if(!vis[p.nod][f][0])
            if(dp[p.nod][f][0]>dp[p.nod][p.lf][1]){
                dp[p.nod][f][0]=dp[p.nod][p.lf][1];
                q.push({dp[p.nod][f][0],p.nod,f,0});
            }
        }
        for(int i=p.lf+1;i<=f;i++){
            if(!vis[p.nod][i][p.cp]){
                if(dp[p.nod][p.lf][p.cp]+c[p.nod]*(i-p.lf)<dp[p.nod][i][p.cp]){
                    dp[p.nod][i][p.cp]=dp[p.nod][p.lf][p.cp]+c[p.nod]*(i-p.lf);
                    q.push({dp[p.nod][i][p.cp],p.nod,i,p.cp});
                }
            }
        }
        for(auto i:a[p.nod]){
            if(p.lf>=i.second)
            if(!vis[i.first][p.lf-i.second][p.cp]){
                if(dp[i.first][p.lf-i.second][p.cp]>dp[p.nod][p.lf][p.cp]){
                    dp[i.first][p.lf-i.second][p.cp]=dp[p.nod][p.lf][p.cp];
                    q.push({dp[i.first][p.lf-i.second][p.cp],i.first,p.lf-i.second,p.cp});
                }
            }
        }
        q.pop();
    }
    printf("%d\n",dp[d][f][0]);
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,t,p,ans,l;
queue<int> q[maxn];
vector<int> a[maxn];
bool vis[maxn],u[maxn],fuck;
void dfs(int nod){
    vis[nod]=true;
    u[nod]=true;
    for(auto i:a[nod]){
        if(!vis[i]){
            dfs(i);
        }
        else if(u[i]){
            fuck=true;
        }
    }
    u[nod]=false;
    t--;
    return;
}

int main(){
    scanf("%d%d%d",&n,&k,&t);
    for(int i=1;i<=n;i++){
     scanf("%d%d",&l,&p);
     q[l].push(i);
     for(int j=1;j<=p;j++){
        scanf("%d",&l);
        a[i].push_back(l);
     }
    }
    for(int i=1;i<=k;i++){
        while(!q[i].empty()){
            if(!vis[q[i].front()]){
                dfs(q[i].front());
            }
            q[i].pop();
        }
        if(t>=0&&!fuck)
            ans=max(ans,i);
    }
    printf("%d\n",ans==0?-1:ans);
}

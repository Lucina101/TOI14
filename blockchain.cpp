#include<bits/stdc++.h>
using namespace std;
int t,q,m,u,v;
struct pa{
int a;
int b;
bool operator <(const pa x)const{
    return a<x.a;
}
};
map<vector<pa>,int> f;
void tree(int x){
    scanf("%d ",&m);
    vector<int> a[m+3];
    for(int i=1;i<m;i++){
    scanf("%d %d",&u,&v);
    if(u<v)
    a[u].push_back(v);
    else
    a[v].push_back(u);
    }
    for(int i=0;i<=m+1;i++){
            sort(a[i].begin(),a[i].end());
        }
    vector<pa> e;
    for(int i=0;i<=m+1;i++){
        for(int j=0;j<a[i].size();j++){
                e.push_back({i,a[i][j]});
            }
        }
    if(x==1){
        f[e]++;
    }
    else{
        printf("%d\n",f[e]);
    }
}
int main(){
    scanf("%d %d",&t,&q);
    for(int r=0;r<t;r++){
        tree(1);
    }
    for(int r=0;r<q;r++){
        tree(2);
    }
}

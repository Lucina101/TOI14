#include<bits/stdc++.h>
using namespace std;
int t,q,m,u,v;
struct pa{
int a;
int b;
bool operator <(const pa x)const{
    if(a!=x.a)
    return a<x.a;
    return b<x.b;
}
};
map<vector<pa>,int> f;
void tree(int x){
    scanf("%d ",&m);
    vector<pa> e;
    for(int i=1;i<m;i++){
    scanf("%d %d",&u,&v);
    if(u<v)
    e.push_back({u,v});
    else
    e.push_back({v,u});
    }
    sort(e.begin(),e.end());
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

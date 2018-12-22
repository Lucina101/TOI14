#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int sum[maxn],n,t,x,ans[maxn],u;
pair<int,int> q[maxn];
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d",&u);
        sum[i]=sum[i-1]+u;
    }
    for(int i=1;i<=t;i++){
        scanf("%d",&x);
        q[i]={x,i};
    }
    sort(q+1,q+1+t);
  /*  for(int i=1;i<=t;i++){
        printf("%d %d\n",a[i].first,a[i].second);
    }*/
    int pt=n;
    for(int i=t;i>=1;i--){
        while(q[i].first<sum[pt])
            pt--;
        ans[q[i].second]=pt;
    }
    for(int j=1;j<=t;j++)
        printf("%d\n",ans[j]);
}

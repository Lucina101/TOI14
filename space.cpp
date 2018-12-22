#include<stdio.h>
#include<math.h>
int n,m,sq,di,tri,ll,ct,f;
char s[2010];
bool a[10010][2010];
void print(){
    printf("\n");
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d",a[i][j]);
            }
            printf("\n");
    }
    printf("\n");
}
void dfs(int x,int y){
    a[x][y]=0;
    ct++;
    if(a[x+1][y]){
        dfs(x+1,y);
    }
    if(a[x-1][y]){
        dfs(x-1,y);
    }
    if(a[x][y+1]){
        dfs(x,y+1);
    }
    if(a[x][y-1]){
        dfs(x,y-1);
    }
    return;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        for(int j=0;s[j]!='\0';j++)
            if(s[j]=='1')
            a[i][j+1]=1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
        if(a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1&&a[i-1][j]==0&&a[i][j-1]==0&&a[i-1][j+1]==0&&a[i+1][j-1]==0){
            ll=0;
            for(int k=i;a[k][j]!=0;k++){
                a[k][j]=0,ll++;
            }
            for(int k=i;k<=i+ll;k++){
                for(int l=j;l<=j+ll;l++){
                    a[k][l]=0;
                }
            }
        sq++;
        }
        }
    }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                ct=0;
                dfs(i,j);
                f=(int)sqrt(ct);
                if(ct==(f*f))
                    tri++;
                else
                    di++;
            }
        }
    }
    printf("%d %d %d\n",sq,di,tri);
}

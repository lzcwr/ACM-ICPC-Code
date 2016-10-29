#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=110;
int dir[8][2]= {{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1}};
int n,dp[maxn][maxn][8];
char mp[maxn][maxn];
bool ok(int x,int y)
{
    if(x>0&&y>0&&x<=n&&y<=n&&mp[x][y]=='.') return true;
    return false;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=1; i<=n; i++)
            scanf("%s",mp[i]+1);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(mp[i][j]=='#') continue;

                for(int k=0; k<4; k++)
                {
                    dp[i][j][k]=1;
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(ok(x,y))
                    {
                        dp[i][j][k]+=dp[x][y][k];

                    }
                }
            }
        for(int i=n; i>=1; i--)
            for(int j=n; j>=1; j--)
            {
                if(mp[i][j]=='#') continue;
                for(int k=4; k<8; k++)
                {
                    dp[i][j][k]+=1;
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(ok(x,y))
                    {
                        dp[i][j][k]+=dp[x][y][k];
                    }
                }
            }
       /* for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<dp[i][j][0]<<' ';
            cout<<endl;
        }*/
        int _max=0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                for(int k=0; k<8; k++)
                    _max=max(_max,dp[i][j][k]+dp[i][j][(k+2)%8]);
            }
        printf("%d\n",_max-1);
    }
    return 0;
}

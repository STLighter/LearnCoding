#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<deque>
#include<stack>
#include<ctime>
#include<bitset>
#include<set>
using namespace std;
typedef long long ll;
void useFile(string f) {
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
}

bool grid[3010][3010];
ll dp[3010][3010];
ll rbcnt[3010][3010];
ll lt[3010][3010][2];
int r,c,k;
void gao(){
    int x,y;
    scanf("%d%d%d",&r,&c,&k);
    memset(grid,0,sizeof(grid));
    memset(dp,0,sizeof(dp));
    memset(rbcnt,0,sizeof(rbcnt));
    memset(lt,0,sizeof(lt));
    for(int i=0;i<k;++i) {
        scanf("%d%d",&x,&y);
        grid[x+1][y+1] = 1;
    }
    for(int i=1;i<=r;++i) {
        for(int j=1;j<=c;++j) {
            lt[i][j][0] = grid[i][j]?0:lt[i-1][j][0]+1;
            lt[i][j][1] = grid[i][j]?0:lt[i][j-1][1]+1;
            rbcnt[i][j] = grid[i][j]?0:min(rbcnt[i-1][j-1]+1, min(lt[i][j][0],lt[i][j][1]));
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + rbcnt[i][j];
        }
    }
    printf("%lld\n", dp[r][c]);
}
int main()
{
	useFile("B-large-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

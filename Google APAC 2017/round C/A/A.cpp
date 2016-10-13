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
int r,c,x,y,s;
double p,q;
bool grid[22][22];
double pro[22][22];
int step[4][2] = {0,1,1,0,0,-1,-1,0};
double ans;
void dfs(int x, int y, int st, double cnt) {
    int tx,ty;
    double tp, tmp;
    if(st!=s) {
        tp = grid[x][y]?pro[x][y]*p:pro[x][y]*q;
    } else {
        tp = 0;
    }
    if(!st) {
        ans = max(ans, cnt+tp);
        return;
    }
    for(int i=0;i<4;++i) {
        tx = x + step[i][0];
        ty = y + step[i][1];
        if(tx>=0&&tx<r&&ty>=0&&ty<c) {
            pro[x][y] -= tp;
            dfs(tx, ty, st - 1, cnt+tp);
            pro[x][y] += tp;
        }
    }
}
void gao(){
    scanf("%d%d%d%d%d",&r,&c,&x,&y,&s);
    scanf("%lf%lf",&p,&q);
    char a,b;
    scanf("%c", &b);
    for(int i=0;i<r;++i) {
        for(int j=0;j<c;++j) {
            scanf("%c%c",&a,&b);
            if(a=='A')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
            pro[i][j] = 1;
        }

    }
    ans = 0;
    dfs(x,y,s,0);
    printf("%.7f\n", ans);
}
int main()
{
	useFile("A-large-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

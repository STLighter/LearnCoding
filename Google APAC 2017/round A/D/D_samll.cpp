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
const int N = 15; 
const int K = 15;
const int M = 1010;
int m,n;
int k[N],l[N];
int a[N][K];
int c[N][K];
int dp[2][M];
void gao(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i)
 	{
	 	scanf("%d%d",&k[i],&l[i]);
 		for(int j=1;j<=k[i];++j) {
		 	scanf("%d",&a[i][j]);
		 }
		 for(int j=2;j<=k[i];++j) {
 			scanf("%d",&c[i][j]);
 			c[i][j]+=c[i][j-1];
 		}
 	}
 	memset(dp,0,sizeof(dp));
 	for(int i=0;i<n;++i) {
	 	for(int j=l[i];j<=k[i];++j) {
	 		int cost = c[i][j] - c[i][l[i]];
	 		int cur = i%2;
	 		int bf = (i+1)%2;
	 		for(int kk=cost;kk<=m;++kk){
		 		dp[cur][kk] = max(dp[bf][kk-cost]+a[i][j],dp[cur][kk]);
		 		dp[cur][kk] = max(dp[cur][kk],kk==0?0:dp[cur][kk-1]);
		 	}
	 	}
	 }
	 printf("%d\n",dp[(n+1)%2][m]);
}
int main()
{
	useFile("D-small-attempt0");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

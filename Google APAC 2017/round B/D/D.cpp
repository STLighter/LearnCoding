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
ll dp[110][110];
ll a[110];
ll n,m;
void init() {
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    a[1] = 1;
    for(int i=2;i<=n;++i) {
        a[i]=a[i-1]*i;
        a[i]%=m;
        ll tmp = 0;
        for(int j=1;j<i;++j) {
            for(int k=1;k<=j;++k) {
                dp[i][k+1] += dp[i-j][1]*dp[j][k];
                dp[i][k+1]%=m;
                tmp += dp[i-j][1]*dp[j][k];
                tmp%=m;
            }
        }
        dp[i][1] = (a[i] - tmp)%m;
        dp[i][1] = (dp[i][1]+m)%m;
    }
}
void gao(){
    scanf("%lld%lld",&n,&m);
    init();
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        ans += i*i%m*dp[n][i]%m;
        ans%=m;
    }
    printf("%lld\n", ans);
}
int main()
{
	useFile("D-small-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

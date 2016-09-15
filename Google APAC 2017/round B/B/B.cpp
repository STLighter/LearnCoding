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
ll a, b, n, k;
ll M = 1000000007;
ll fastPow(ll base, ll x) {
    ll ret = 1;
    while(x) {
        if(x&1) {
            ret*=base;
            ret%=k;
        }
        base*=base;
        base%=k;
        x>>=1;
    }
    return ret%k;
}
void gao(){
    scanf("%lld%lld%lld%lld", &a, &b, &n, &k);
    map<ll, ll> ma;
    ll cnt = n/k;
    ll om = n%k;
    ll tmp;
    for(ll i=1;i<=k;++i) {
        tmp = fastPow(i, a);
        if(i<=om) {
            ma[tmp] += (cnt+1)%M;
        } else {
            ma[tmp] += cnt%M;
        }
        ma[tmp] %= M;
    }
    ll ans = 0;
    for(ll i=1;i<=k;++i) {
        tmp = (k - fastPow(i, b))%k;
        if(i<=om) {
            if(fastPow(i, a) == tmp) {
                ans += ma[tmp]*((cnt+1)%M) - (cnt+1)%M;
                ans = (ans%M+M)%M;
            } else {
                ans += ma[tmp]*((cnt+1)%M);
                ans %= M;
            }
        } else {
            if(fastPow(i, a) == tmp) {
                ans += ma[tmp]*(cnt%M) - cnt%M;
                ans = (ans%M+M)%M;
            } else {
                ans += ma[tmp]*(cnt%M);
                ans %= M;
            }
        }
    }
    printf("%lld\n", ans);
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

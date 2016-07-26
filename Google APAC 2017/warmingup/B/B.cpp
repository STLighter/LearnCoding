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
int n,k;
int a[4][1010];
void gao(){
	map<int,ll> m;
	scanf("%d%d",&n,&k);
	for(int i=0;i<4;++i)
	for(int j=0;j<n;++j)
	scanf("%d",&a[i][j]);
	
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
	++m[a[0][i]^a[1][j]];
	
	ll ans = 0;
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
	ans+=m[k^a[2][i]^a[3][j]];
	
	printf("%lld\n",ans);

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

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
int n,q,l;
int a[1010];
ll b[1000100];
void gao(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;++i) {
		scanf("%d",&a[i]);
	}
	b[0] = 0;
	l=1;
	for(int i=0;i<n;++i) {
		ll sum = a[i];
		b[l++] = sum;
		for(int j=i+1;j<n;++j) {
			sum += a[j];
			b[l++] = sum;
		}
	}
	sort(b+1,b+l);
	ll sum = 0;
	for(int i=0;i<l;++i) {
		b[i]+=sum;
		sum=b[i];
	}
	int x,y;
	for(int i=0;i<q;++i) {
		scanf("%d%d",&x,&y);
		printf("%lld\n",b[y]-b[x-1]);
	}
}
int main()
{
	useFile("D-small-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d:\n",i);
    	gao();
    }
    return 0;
}

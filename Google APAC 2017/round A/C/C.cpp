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
int m;
int c[110];
double f(int m, double r) {
	double ans = 0;
	for(int i=0;i<=m;++i){
		ans*=(1+r);
		ans+=c[i];
	}
	return ans;
}
void gao(){
	scanf("%d",&m);
	for(int i=0;i<=m;++i)
		scanf("%d",&c[i]);
	c[0]=-c[0];
	double l=-1,r=1;
	double a0 = f(m,l);
	double a1 = f(m,r);
	if(a0>a1){
		for(int i=0;i<=m;++i)
		c[i]=-c[i];
	}
	while(r-l>=1e-10){
		double mid = (r+l)/2;
		double ans = f(m,mid);
		if(ans<=0)
			l = mid;
		else if(ans>0)
			r = mid;
	}
	if(f(m,l)==0)
	printf("%.9lf\n", l);
	else
	printf("%.9lf\n", r);
}
int main()
{
	useFile("C-large");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

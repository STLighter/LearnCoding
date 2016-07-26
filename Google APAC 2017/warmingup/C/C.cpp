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
int n,x,k,a,b,c;
void gao(){
	map<int,double> m[2];
	scanf("%d%d%d%d%d%d",&n,&x,&k,&a,&b,&c);
	m[0][x] = 1;
	for(int i=0;i<n;++i) {
		map<int,double> &from = m[i%2];
		map<int,double> &to = m[(i+1)%2]; 
		to.clear();
		for(map<int,double>::iterator it = from.begin();it!= from.end();++it) {
			//printf("%d\n",it->first);
			to[it->first&k] += it->second*a/100.0;
			//printf("%d %.10lf\n",it->first&k, it->second*a/100.0);
			to[it->first|k] += it->second*b/100.0;
			//printf("%d %.10lf\n",it->first|k, it->second*b/100.0);
			to[it->first^k] += it->second*c/100.0;
			//printf("%d %.10lf\n",it->first^k, it->second*c/100.0);
		}
	}
	map<int,double> &cur = m[n%2];
	double ans = 0;
	for(map<int,double>::iterator it = cur.begin();it!= cur.end();++it) {
		ans += it->first*it->second;
	}
	printf("%.10lf\n",ans);
}
int main()
{
	useFile("C-large-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

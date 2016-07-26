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
ll m,n;
ll k[N],l[N];
ll a[N][K];
ll c[N][K];
struct Node {
	ll c,a;
	bool operator< (const Node& x) const {
		if(c==x.c)
			return a>x.a;
		return c<x.c; 
	}
};
vector<Node> collc[10];
void gao(){
	scanf("%lld%lld",&m,&n);
	for(int i=0;i<n;++i)
 	{
	 	scanf("%lld%lld",&k[i],&l[i]);
 		for(int j=1;j<=k[i];++j) {
		 	scanf("%lld",&a[i][j]);
		 }
		 for(int j=2;j<=k[i];++j) {
 			scanf("%lld",&c[i][j]);
 			c[i][j]+=c[i][j-1];
 		}
 	}
 	for(int i=0;i<=8;++i)
 		collc[i].clear();
	Node tmp;
	tmp.c = 0;
	tmp.a = 0;
	collc[0].push_back(tmp);
 	for(int i=0;i<n;++i) {
 		int lenar[10];
 		for(int kk=7;kk>=0;--kk) {
	 		lenar[kk] = collc[kk].size();
	 	}
	 	for(int j=l[i];j<=k[i];++j) {
	 		int cost = c[i][j] - c[i][l[i]];
	 		for(int kk=7;kk>=0;--kk) {
		 		for(int e=0;e<lenar[kk];++e) {
		 			tmp.c = collc[kk][e].c + cost;
		 			tmp.a = collc[kk][e].a + a[i][j];
		 			if(tmp.c<=m)
		 				collc[kk+1].push_back(tmp);
		 		}
		 	}
	 	}
	 	for(int kk=7;kk>=0;--kk) {
	 		sort(collc[kk+1].begin(),collc[kk+1].end());
	 		vector<Node> vtmp;
	 		for(int e=0;e<collc[kk+1].size();++e) {
 			if(e==0||collc[kk+1][e].a>vtmp[vtmp.size()-1].a)
				vtmp.push_back(collc[kk+1][e]);
	 		}
	 		collc[kk+1].clear();
	 		for(int e=0;e<vtmp.size();++e) {
 				collc[kk+1].push_back(vtmp[e]);
	 		}
	 	}
	 			 
	 }
	 printf("%lld\n",collc[8][collc[8].size()-1].a);
}
int main()
{
	useFile("D-large-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

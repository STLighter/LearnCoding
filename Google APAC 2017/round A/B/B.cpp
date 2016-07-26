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
int v[10001];
int ans[10001];
bool used[10001];
vector<int> nodes[10001];
struct Node {
	int _cur;
	int _max;
	friend bool operator <(const Node &a,const Node &b){
		return a._max > b._max;
	}
};
int steps[4][2] = {
	-1,0,
	0,1,
	1,0,
	0,-1
};
void dij(int cur) {
	priority_queue <Node> qu;
	Node tmp;
	tmp._cur=cur;
	tmp._max=0;
	qu.push(tmp);
	while(!qu.empty()) {
		tmp = qu.top();
		qu.pop();
		cur = tmp._cur;
		if(used[cur])
			continue;
		used[cur] = 1;
		ans[cur] = tmp._max;
		
		for(int i=0; i<nodes[cur].size();++i) {
			int next = nodes[cur][i];
			int nextans = max(ans[cur], v[next]);
			if(!used[next]) {
				Node nextnode;
				nextnode._cur = next;
				nextnode._max = nextans;
				qu.push(nextnode);
			}
		}
	}
}

void gao(){
	int n,m;
	cin>>n>>m;
	int lastnode = n*m;
	for(int i=0;i<=n*m;++i)
	nodes[i].clear();
	memset(used,0,sizeof(used));
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			int curnode = i*m+j;
			scanf("%d", &v[curnode]);
			for(int k=0;k<4;++k) {
				int tmpi = i+steps[k][0];
				int tmpj = j+steps[k][1];
				if(tmpi<0||tmpi>=n||tmpj<0||tmpj>=m) {
					nodes[lastnode].push_back(curnode);
				} else {
					int nextnode = tmpi*m+tmpj;
					nodes[curnode].push_back(nextnode);
				}
			}
		}
	}
	dij(lastnode);
	int sum = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) {
			int cur = i*m+j;
			sum += ans[cur]-v[cur];
		}
	}
	printf("%d\n",sum);
}
int main()
{
	useFile("B-large");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

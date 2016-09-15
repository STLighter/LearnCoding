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
int n;
ll l, r, a, b, c1, c2, m;
struct Node {
    ll x,y,m;
    bool operator <(Node &a) const {
        return (x==a.x?y<a.y:x<a.x);
    }
}node[500010];
void gao(){
    scanf("%d%lld%lld%lld%lld%lld%lld%lld", &n, &l, &r, &a, &b, &c1, &c2, &m);
    node[0].x = l;
    node[0].y = r;
    for(int i=1;i<n;++i) {
        Node &bf = node[i-1];
        Node &cur = node[i];
        cur.x = (a*bf.x + b*bf.y + c1)%m;
        cur.y = (a*bf.y + b*bf.x + c2)%m;
    }
    for(int i=1;i<n;++i) {
        Node &cur = node[i];
        if(cur.x>cur.y) {
            swap(cur.x, cur.y);
        }
        cur.m = 0;
    }
    sort(node, node+n);
    ll ans = 0, last = -1;
    for(int i=0;i<n;++i) {
        if(node[i].y <= last)
            continue;
        if(node[i].x > last) {
            ans += node[i].y - node[i].x+1;
        } else {
            ans += node[i].y - last;
        }
        last = node[i].y;
    }
    last = node[0].x - 1;
    node[0].m = node[0].y - node[0].x + 1;
    int id = 0;
    for(int i=1;i<n;++i) {
        Node &bf = node[id];
        Node &cur = node[i];
        ll lb, rb;
        if(cur.y <= bf.y) {
            cur.m = 0;
            lb = max(last+1, cur.x);
            rb = cur.y;
            if(rb>=lb)
                bf.m -= rb - lb + 1;
            last = max(cur.y, last);
        } else if(cur.x > bf.y) {
            cur.m = cur.y - cur.x + 1;
            id = i;
            last = cur.x - 1;
        } else {
            lb = max(last+1, cur.x);
            rb = bf.y;
            bf.m -= rb - lb + 1;
            cur.m = cur.y - bf.y;
            last = bf.y;
            id = i;
        }
    }
    ll mtmp = 0;
    for(int i=0;i<n;++i) {
        mtmp = max(mtmp, node[i].m);
    }
    printf("%lld\n", ans-mtmp);
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

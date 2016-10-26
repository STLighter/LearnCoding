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
const int N = 10010;
const int M = 110;
int n,m,k;
int s[N],t[N],st[M],ans[N];
vector<int> o[N];
vector<int> w[N];
struct Opt {
    int cnt;
    int time;
    int id;
    bool operator < (const Opt &x) const {
        return (time==x.time?s[id]>s[x.id]:time>x.time);
    }
};
int main() {
    int p,to,tw;
    Opt tmp;
    priority_queue<Opt> qu;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i) {
        scanf("%d%d%d", &s[i],&t[i],&p);
        for(int j=0;j<p;++j) {
            scanf("%d%d",&to,&tw);
            o[i].push_back(to);
            w[i].push_back(tw);
        }
        tmp.cnt = 0;
        tmp.time = t[i] + k;
        tmp.id = i;
        qu.push(tmp);
    }
    while(!qu.empty()) {
        tmp = qu.top();
        qu.pop();
        int mm = o[tmp.id][tmp.cnt];

        int time = max(tmp.time, st[mm]);
        time += w[tmp.id][tmp.cnt];
        st[mm] = time;
        ++tmp.cnt;
        tmp.time = time + k;
        if(tmp.cnt == o[tmp.id].size()) {
            ans[tmp.id] = time;
        } else {
            qu.push(tmp);
        }
    }
    for(int i=0;i<n;++i)
        printf("%d\n", ans[i]);
}

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
int a[4010],d[4010],n;
bool used[4010];
vector<int> m[4010];
bool dfs() {
    if(n == 0) {
        return 0;
    }
    int x = 0,y = 0;
    for(int i=0;i<n;++i) {
        x = max(x, a[i]);
        y = max(y, d[i]);
    }
    int l = 0;
    for(int i=0;i<n;++i) {
        if(a[i]!=x&&d[i]!=y) {
            a[l] = a[i];
            d[l] = d[i];
            ++l;
            continue;
        }
        if(a[i]==x&&d[i]==y)
            return 1;
    }
    n = l;
    return dfs();
}
void gao(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        used[i] = 0;
        scanf("%d%d",&a[i],&d[i]);
    }
    if(dfs()) {
        printf("YES\n");
        return;
    }
    printf("NO\n");
    return;
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

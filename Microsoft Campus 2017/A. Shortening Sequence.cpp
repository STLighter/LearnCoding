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
int a[1000010];
int n,l;
int main() {
    int x, cnt = 0;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&x);
        if(l==0||!((x+a[l-1])&1)) {
            a[l++] = x;
        } else {
            cnt += 2;
            --l;
        }
    }
    printf("%d\n", n-cnt);
}

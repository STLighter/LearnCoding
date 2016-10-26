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
bool adj[26][26];
int cnt[26];
int n,m;
string str, tmp;
int main() {
    scanf("%d",&n);
    cin>>str;
    scanf("%d",&m);
    for(int i=0;i<m;++i) {
        cin>>tmp;
        adj[tmp[0]-'a'][tmp[1]-'a'] = adj[tmp[1]-'a'][tmp[0]-'a'] = 1;
    }
    for(int i=0;i<n;++i) {
        int cur = str[i]-'a';
        int tmp = 1;
        for(int j=0;j<26;++j) {
            if(!adj[j][cur]) {
                tmp = max(tmp, cnt[j] + 1);
            }
        }
        cnt[cur] = max(cnt[cur], tmp);
    }
    int ans = 0;
    for(int i=0;i<26;++i) {
        ans = max(ans, cnt[i]);
    }
    cout<<n - ans<<endl;
}

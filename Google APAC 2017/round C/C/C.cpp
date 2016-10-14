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
bool val[10010];
int cnt[10010];
vector<int> nxt[10010];

void gao(){
    scanf("%d",&n);
    int l = 0;
    map<string, int> ma;
    string str;
    memset(val,0,sizeof(val));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<10010;++i) {
        nxt[i].clear();
    }
    for(int i=0;i<n;++i) {
        cin>>str;
        string tmp;
        int lf;
        int j=0;
        for(;str[j]!='=';++j) {
            tmp.push_back(str[j]);
        }
        if(!ma[tmp]) {
            lf = ++l;
            ma[tmp] = l;
        } else {
            lf = ma[tmp];
        }
        while(str[j]!='(')
            ++j;
        while(str[j]!=')') {
            ++j;
            tmp.clear();
            while(str[j]!=','&&str[j]!=')') {
                tmp.push_back(str[j]);
                ++j;
            }
            if(tmp.length()==0) {
                val[lf] = 1;
            } else {
                if(!ma[tmp]) {
                    ma[tmp] = ++l;
                }
                nxt[ma[tmp]].push_back(lf);
                ++cnt[lf];
            }
        }
    }

    queue<int> qu;
    for(int i=1;i<=l;++i) {
        if(val[i]&&!cnt[i]) {
            qu.push(i);
        }
    }
    while(!qu.empty()) {
        int x = qu.front();
        qu.pop();
        for(int i=0;i<nxt[x].size();++i) {
            int y = nxt[x][i];
            --cnt[y];
            val[y] = 1;
            if(!cnt[y])
                qu.push(y);
        }
    }
    bool ans = true;
    for(int i=1;i<=l;++i) {
        if(cnt[i]||!val[i]) {
            ans = false;
            break;
        }
    }
    if(ans)
        printf("GOOD\n");
    else
        printf("BAD\n");

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

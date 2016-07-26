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
string s;
const ll M = 1000000007;
void useFile(string f) {
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
} 
void gao(){
	cin>>s;	
	ll ans = 1;
	for(int i=0;i<s.length();++i) {
		int cnt = 0;
		bool used[30] = {0};
		for(int j=i-1;j<=i+1;++j) {
			if(j<0||j>=s.length())
				continue;
			if(!used[s[j]-'a']) {
				used[s[j]-'a'] = 1;
				++cnt;
			}
		}
		ans*=cnt;
		ans%=M;
	}
	printf("%lld\n",ans);
}
int main()
{
	useFile("A-large-practice");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

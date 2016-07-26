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
struct Person {
	char name[30]; 
	int v;
} p[110];
int n;
bool used[30];
bool cmp(const Person &a, const Person &b) {
	return (strcmp(a.name, b.name)<0);
}

void gao(){
	scanf("%d",&n);
	getchar(); 
	int maxv = 0;
	for(int i=0;i<n;++i){
		gets(p[i].name);
		int l = strlen(p[i].name);
		memset(used,0,sizeof(used));
		int cnt = 0;
		for(int j=0;j<l;++j) {
			if(p[i].name[j]==' ')
			continue;
			if(!used[p[i].name[j]-'A']) {
				++cnt;
				used[p[i].name[j]-'A'] = 1;
			}
		}
		p[i].v = cnt;
		maxv = max(maxv,p[i].v);
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;++i)
	if(p[i].v==maxv) {
		puts(p[i].name);
		break;
	}
}
int main()
{
	useFile("A-large");
	int t;
    scanf("%d",&t);
    for(int i=1;i<=t;++i) {
    	printf("Case #%d: ",i);
    	gao();
    }
    return 0;
}

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
int h,w,l;
int a[505][505];
int step[4][2] = {
    -1,0,
    0,-1,
    -1,-1,
    -1,1
};
int step9[9][2] = {
    0,0,
    -1,0,
    0,-1,
    1,0,
    0,1,
    -1,-1,
    -1,1,
    1,-1,
    1,1
};
vector<pair<int, int> > v[505*505];

bool check(int x, int y) {
    return (x>0&&x<=h&&y>0&&y<=w&&a[x][y]!=-1);
}
bool checkMir(int x, int y) {
    int tx,ty;
    for(int i=0;i<1;++i) {
        tx = x + step9[i][0];
        ty = y + step9[i][1];
        if(check(tx, ty)) {
            return 1;
        }
    }
    return 0;
}
int getV(int i, int j) {
    return (i-1)*w+j-1;
}
void getC(int v, int &i, int &j) {
    i = v/w + 1;
    j = v%w + 1;
}
int Find(int i, int j) {
    int tmp = getV(i, j);
    if(tmp != a[i][j]) {
        int x, y;
        getC(a[i][j], x, y);
        return (a[i][j] = Find(x, y));
    }
    return tmp;
}
void Union(int i1, int j1, int i2, int j2) {
    int t1 = Find(i1, j1);
    int t2 = Find(i2, j2);

    if(t1 == t2)
        return;
    getC(t1, i1, j1);
    a[i1][j1] = t2;
}

int main() {
    char c;
    memset(a,-1,sizeof(a));
    scanf("%d%d",&h,&w);
    getchar();
    for(int i=1;i<=h;++i) {
        for(int j=1;j<=w;++j) {
            c = getchar();
            if(c=='#') {
                a[i][j] = getV(i, j);
                for(int k=0;k<4;++k) {
                    int x = i + step[k][0];
                    int y = j + step[k][1];
                    if(check(x, y))
                        Union(x, y, i, j);
                }
            }
        }
        getchar();
    }
    map<int, int> ma;
    int tmp, p;
    l = 0;
    for(int i=1;i<=h;++i) {
        for(int j=1;j<=w;++j) {
            if(a[i][j]!=-1) {
                tmp = Find(i,j);
                p = ma[tmp];
                if(!p) {
                    ma[tmp] = p = ++l;
                }
                v[p].push_back(make_pair(i,j));
            }

        }
    }

    int s = 0;

    for(int i=1;i<=l;++i) {
        double x = 0, y = 0;
        for(int j=0;j<v[i].size();++j) {
            x += v[i][j].first;
            y += v[i][j].second;
        }
        x /= v[i].size();
        y /= v[i].size();


        double eval = 0;

        cout<<i<<' '<<eval<<endl;
        if(eval >= 0.5) {
            cout<<i<<endl;
            ++s;
        }
    }
    printf("%d %d\n", l - s, s);
}

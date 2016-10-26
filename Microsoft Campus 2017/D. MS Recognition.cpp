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
bool a[505][505];
bool used[2][505][505];
int step[8][2] = {
    -1,0,
    -1,-1,
    0,-1,
    1,-1,
    1,0,
    1,1,
    0,1,
    -1,1
};

bool check(int x, int y) {
    return (x>=0&&x<h&&y>=0&&y<w&&a[x][y]);
}
bool wise(pair<int, int> v1, pair<int, int> v2) {
    return (v1.first*v2.second - v1.second*v2.first > 0);
}
int main() {
    char c;
    scanf("%d%d",&h,&w);
    getchar();
    for(int i=0;i<h;++i) {
        for(int j=0;j<w;++j) {
            c = getchar();
            if(c=='#') {
                a[i][j] = 1;
            }
        }
        getchar();
    }

    int s = 0, l = 0;
    for(int i=0;i<h;++i) {
        for(int j=0;j<w;++j) {
            if(a[i][j]&&!used[1][i][j]) {
                ++l;
                queue<pair<int, int> > qu;
                pair<int, int> p, q;
                int x, y, cnt = 0;
                double eval;
                used[0][p.first][p.second] = 1;
                qu.push(make_pair(i,j));
                while(!qu.empty()) {
                    p = qu.front();
                    qu.pop();
                    for(int k=0;k<8;++k) {
                        x = p.first + step[k][0];
                        y = p.second + step[k][1];
                        if(check(x,y)&&!used[0][x][y]) {
                            used[0][x][y] = 1;
                            qu.push(make_pair(x,y));
                        }
                    }
                }

                qu.push(p);
                used[1][p.first][p.second] = 1;
                vector<pair<int, int> > st;
                while(!qu.empty()) {
                    q = qu.front();
                    st.push_back(q);
                    qu.pop();
                    for(int k=0;k<8;++k) {
                        x = q.first + step[k][0];
                        y = q.second + step[k][1];
                        if(check(x,y)&&!used[1][x][y]) {
                            used[1][x][y] = 1;
                            qu.push(make_pair(x,y));
                        }
                    }
                }

                for(int k=0;k<st.size();++k) {
                    if(wise(make_pair(p.first - st[k].first, p.second - st[k].second), make_pair(q.first - st[k].first, q.second - st[k].second))) {
                        ++cnt;
                    }
                }

                eval = fabs(1.0*cnt/st.size() - 0.5);
                cout<<eval<<endl;

                if(eval < 0.1) {
                    ++s;
                }
            }
        }
    }

    printf("%d %d\n", l - s, s);
}

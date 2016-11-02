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
int h,w;
bool a[555][555];
bool used[2][555][555];
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
int main() {
    char c;
    string str;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;++i) {
        cin>>str;
        for(int j=0;j<w;++j) {
            c = str[j];
            if(c=='#') {
                a[i][j] = 1;
            }
        }
    }

    int s = 0, l = 0;
    for(int i=0;i<h;++i) {
        for(int j=0;j<w;++j) {
            if(a[i][j]&&!used[1][i][j]) {
                ++l;
                queue<pair<int, int> > qu;
                pair<int, int> p, q;
                int x, y, cnt = 0;
                int tp = h, bt = 0, lt = w, rt = 0;
                double eval;
                used[0][i][j] = 1;
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
                while(!qu.empty()) {
                    q = qu.front();
                    qu.pop();
                    tp = min(tp, q.first);
                    bt = max(bt, q.first);
                    lt = min(lt, q.second);
                    rt = max(rt, q.second);
                    for(int k=0;k<8;++k) {
                        x = q.first + step[k][0];
                        y = q.second + step[k][1];
                        if(check(x,y)&&!used[1][x][y]) {
                            used[1][x][y] = 1;
                            qu.push(make_pair(x,y));
                        }
                    }
                }

                double tmp1, tmp2, tmp3, tmp4;
                tmp1 = tp + bt - p.first - q.first;
                tmp2 = lt + rt - p.second - q.second;
                tmp3 = p.first - q.first;
                tmp4 = p.second - q.second;
                eval = (tmp1*tmp1 + tmp2*tmp2) / (tmp3*tmp3 + tmp4*tmp4);
                //cout<<eval<<endl;

                if(eval < 0.3) {
                    ++s;
                }
            }
        }
    }

    printf("%d %d\n", l - s, s);
}

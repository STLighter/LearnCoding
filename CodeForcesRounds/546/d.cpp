/**
 * D. Nastya Is Buying Lunch
 * https://codeforces.com/contest/1136/problem/D
 */

#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int p[300010];
vector<int> uv[300010];
bool hashSet[300010];

int main() {
  int n, m, u, v;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  for(int i = 0; i < m; ++i) {
    scanf("%d%d", &u, &v);
    uv[u].push_back(v);
  }

  int ans = 0, setSize = 1;
  hashSet[p[n - 1]] = 1;
  
  for(int i = n - 2; i >= 0; --i) {
    int cnt = 0;
    for(auto _v : uv[p[i]]) {
      if(hashSet[_v]) {
        ++cnt;
      }
    }
    if(cnt == setSize) ++ans;
    else {
      hashSet[p[i]] = 1;
      ++setSize;
    }
  }
  cout << ans << endl;
}

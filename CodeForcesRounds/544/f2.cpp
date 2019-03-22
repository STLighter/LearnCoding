/**
 * F2. Spanning Tree with One Fixed Degree
 * https://codeforces.com/contest/1133/problem/F2
 */

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
bool visited[200010];
vector<int> node[200010];
vector<int> group[200010];
queue<int> qu;
int n, m, d, g;

void dfs(int cur, int parent) {
  visited[cur] = true;
  for(auto next: node[cur]) {
    if(visited[next]) {
      if(parent == -1) group[g - 1].push_back(next);
      continue;
    }
    if(parent == -1) {
      group[g++].push_back(next);
    }
    dfs(next, cur);
  }
}

void bfs() {
  while(qu.size()) {
    int cur = qu.front();
    qu.pop();
    for(auto next: node[cur]) {
      if(!visited[next]) {
        visited[next] = true;
        cout << cur + 1 << ' ' << next + 1 << endl;
        qu.push(next);
      }
    }
  }
}

int main() {
  int x, y;
  cin >> n >> m >> d;
  for(int i = 0; i < m; ++i) {
    cin >> x >> y;
    --x;
    --y;
    node[x].push_back(y);
    node[y].push_back(x);
  }
  memset(visited, 0, sizeof(visited));
  dfs(0, -1);
  for(int i = 0; i < n; ++i) {
    if(!visited[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if(g > d || node[0].size() < d) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  memset(visited, 0, sizeof(visited));
  visited[0] = true;
  d -= g;
  for(int i = 0; i < g; ++i) {
    cout<< '1' << ' ' << group[i][0] + 1 << endl;
    visited[group[i][0]] = true;
    qu.push(group[i][0]);
    for(int j = 1; d && j < group[i].size(); ++j) {
      cout<< '1' << ' ' << group[i][j] + 1 << endl;
      visited[group[i][j]] = true;
      qu.push(group[i][j]);
      --d;
    }
  }
  bfs();
  return 0;
}

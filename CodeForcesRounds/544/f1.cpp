/**
 * F1. Spanning Tree with Maximum Degree
 * https://codeforces.com/contest/1133/problem/F1
 */

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> node[200010];
bool visited[200010];

void bfs(int start) {
  queue<int> qu;
  qu.push(start);
  visited[start] = true;
  while(qu.size()) {
    int cur = qu.front();
    qu.pop();
    for(auto next : node[cur]) {
      if(visited[next]) continue;
      visited[next] = true;
      qu.push(next);
      cout << cur + 1 << ' ' << next + 1 << endl;
    }
  }
}

int main() {
  int n, m, x, y, tmp, maxCnt = 0, maxNode = -1;
  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    cin >> x >> y;
    --x;
    --y;
    node[x].push_back(y);
    node[y].push_back(x);
    tmp = node[x].size() > node[y].size() ? x : y;
    if(node[tmp].size() > maxCnt) {
      maxCnt = node[tmp].size();
      maxNode = tmp;
    }
  }
  bfs(maxNode);
  return 0;
}

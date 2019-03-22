/**
 * C. Nastya Is Transposing Matrices
 * https://codeforces.com/contest/1136/problem/C
 */
#include<iostream>
#include<algorithm>
using namespace std;

int a[500][500], b[500][500];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> b[i][j];
    }
  }

  int x = 0, y = 0, l = 0, arra[500], arrb[500];
  while(x < n) {
    int px = x, py = y;
    l = 0;
    while(py >=0 && px < n) {
      arra[l] = a[px][py];
      arrb[l] = b[px][py];
      ++l;
      ++px;
      --py;
    }
    sort(arra, arra + l);
    sort(arrb, arrb + l);
    for(int i = 0; i < l; ++i) {
      if(arra[i] != arrb[i]) {
        cout << "NO" << endl;
        return 0;
      }
    }
    if(y == m - 1) ++x;
    else ++ y;
  }
  cout << "YES" << endl;
}

/**
 * D. Zero Quantity Maximization
 * https://codeforces.com/contest/1133/problem/D
 */
#include<iostream>
#include<map>
#include<cstdlib>

using namespace std;

int a[200000], b[200000];

int gcd(int x, int y) {
  if(x > y) return gcd(y, x);
  if(x == 0) return y;
  return gcd(y%x, x);
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin>>a[i];
  }
  for(int i = 0; i < n; ++i) {
    cin>>b[i];
  }
  int zeroBCnt = 0, zeroBothCnt = 0;
  map<pair<int, int>, int> hash;
  for(int i = 0; i < n; ++i) {
    if(a[i] == 0) {
      if(b[i] == 0) ++zeroBothCnt;
      continue;
    }
    if(b[i] == 0) {
      ++zeroBCnt;
    }
    int divisor = gcd(abs(a[i]), abs(b[i]));
    a[i] /= divisor;
    b[i] /= divisor;
    if(a[i] < 0) {
      a[i] = -a[i];
      b[i] = -b[i];
    }
    if(hash[make_pair(a[i], b[i])]) ++hash[make_pair(a[i], b[i])];
    else hash[make_pair(a[i], b[i])] = 1;
  }
  int ans = zeroBCnt;
  for(auto item: hash) {
    if(item.second > ans) ans = item.second;
  }
  cout << ans + zeroBothCnt << endl;
  return 0;
}

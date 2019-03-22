/**
 * A. Middle of the Contest 
 * https://codeforces.com/contest/1133/problem/A
 */

#include<cstdio>

int main() {
  int h0, m0, h1, m1, ans;
  scanf("%d:%d", &h0, &m0);
  scanf("%d:%d", &h1, &m1);
  ans = (h0 * 60 + m0 + h1 * 60 + m1) / 2;
  printf("%02d:%02d\n", ans/60, ans%60);
}

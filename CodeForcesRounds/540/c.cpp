// C. Palindromic Matrix
#include<iostream>
#include<cmath>

using namespace std;

int n, N, num[400], cnt[1010] = { 0 }, maxNum = 0;


void setSingle(int val) {
  num[n / 2 * n + n / 2] = val;
}

int doubleRow = 0, doubleCol = 0;
void setDouble(int val) {
  if(doubleRow < n / 2) {
    num[doubleRow * n + n / 2] = num[(n - 1 - doubleRow) * n + n / 2] = val;
    ++doubleRow;
    return;
  }
  num[n / 2 * n + doubleCol] = num[n / 2 * n + n - 1 - doubleCol] = val;
  ++doubleCol;
}

int squareRow = 0, squareCol = 0;
void setSquare(int val) {
  num[squareRow * n + squareCol] = 
  num[squareRow * n + n - 1 - squareCol] =
  num[(n - 1 - squareRow) * n + squareCol] =
  num[(n - 1 - squareRow) * n + n - 1 - squareCol] = val;
  ++squareCol;
  if(squareCol >= n / 2) {
    squareCol = 0;
    ++squareRow;
  }
}

int main() {
  cin >> n;
  N = n * n;

  for(int i= 0; i < N; ++i) {
    cin >> num[i];
    maxNum = max(num[i], maxNum);
    ++cnt[num[i]];
  }

  int singleCnt = (n & 1) ? 1 : 0;
  int doubleCnt = (n & 1) ? 2 * n - 2 : 0;
  int squareCnt = N - singleCnt - doubleCnt;
  int cur = 1;
  while(cur <= maxNum) {
    if(cnt[cur] >=4 && squareCnt) {
      squareCnt -= 4;
      cnt[cur] -= 4;
      setSquare(cur);
      continue;
    } else if (cnt[cur] >= 2 && doubleCnt) {
      doubleCnt -= 2;
      cnt[cur] -= 2;
      setDouble(cur);
      continue;
    } else if (cnt[cur] == 1 && singleCnt) {
      singleCnt -= 1;
      cnt[cur] -= 1;
      setSingle(cur);
      continue;
    } else if(cnt[cur] == 0) {
      ++cur;
      continue;
    }
    cout<< "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cout << num[i * n + j] << (j == n - 1 ? '\n': ' ');
    }
  }
}

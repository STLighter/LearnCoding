// A. Water Buying
#include<iostream>
using namespace std;

typedef long long ll;

int main() {
  int q;
  ll n, a, b, ans;
  cin >> q;
  while(q--) {
    cin >> n >> a >> b;
    if(a * 2 <= b) {
      ans = n * a;
    } else {
      ans = (n / 2) * b + ((n & 1)? a : 0);
    }
    cout << ans <<endl;
  }
}

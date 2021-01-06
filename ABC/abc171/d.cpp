#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MX = 100005;
int X[MX];

int main() {
  int n;
  cin >> n;
  REP(i,n){
    int a;
    cin >> a;

    X[a]++;
  }
  int q;
  cin >> q;
  vector<ll> sum(q+1);

  sum[0] = 0;
  REP(i,MX){
    sum[0] += i * X[i];
  }



  for(int i = 1; i <= q; ++i){
    int b, c;
    cin >> b >> c;
    ll tmp_b = X[b];
    X[b] = 0;
    X[c] += tmp_b;

    sum[i] = sum[i-1] - tmp_b*b + tmp_b*c;  //intだとオーバーフローしてしまうので注意
  }

  for(int i = 1; i <= q; ++i) cout << sum[i]<< endl;

  return 0;
}

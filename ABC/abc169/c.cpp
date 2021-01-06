#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a;
  double b;
  cin >> a >> b;

  ll bb = 100*b + 0.5;  //bを整数として扱えるようにする. doble->ll で誤差が僅かにでるので＋０．５で誤差がきれない

  ll ans = a*bb/100; //c++だと小数点以下は切り捨て

  //printf("%.f", ans);
  cout << ans << endl;

}
